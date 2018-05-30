#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.141592654

void InitScreen();
void MovimentaMouse(int, int);
void MouseFunc(int, int, int, int);
void Keyboard(unsigned char, int, int);
void SpecialKeys(int, int, int);
void Timer(int);
void TimerFunc(int );
void Desenha();
void Reshape(int, int);
void Msg(char *, GLfloat , GLfloat );
void DesenhaGrade();
void DesenhaCarro();
void DesenhaEstrada();
void IdleFunc();

GLfloat preto[]={0,0,0},        branco[]={1,1,1},           verde[]={0,1,0},            vermelho[]={1,0,0},
        azul[]={0,0,1},         amarelo[]={1,1,0},          furchsia[]={1,0,1},         rosa[]={1,0.75,0.8},
        rosaBri[]={1,0,0.5},    abobora[]={0.99,0.06,0.75}, ciano[]={0,1,1},            verdeEsc[]={0,0.39,0},
        azulEsc[]={0,0,0.55},   marinho[]={0.07,0.04,0.56}, fuligem[]={0.24,0.17,0.12}, roxo[]={0.5,0,0.5},
        jambo[]={1,0.27,0},     laranja[]={1,0.65,0},       marrom[]={0.65,0.16,0.16},  cinza[]={0.5,0.5,0.5},
        cinzaClaro[]={0.7,0.7,0.7},
        cinzaEsc[]={0.66,0.66,0.66},  azulCeu[]={0.53,0.81,0.98}, verdeGrama[]={0.49,0.99,0}, cinzaFosco[]={0.41,0.41,0.41};

GLint sw, sh, winPosX, winPosY;
GLfloat w_width, w_height;
GLfloat mouseX, mouseY, mouseClickX, mouseClickY;
GLfloat angX = 0, angY = 0, angZ = 0;
GLdouble theta=90, aspect=1, d_near=25, d_far=500;
GLdouble x_0=0, y_0=35.0, z_0=150,
         x_ref=0, y_ref=0, z_ref=0,
         V_x=0, V_y=1, V_z = 0,
         xCam = 0, yCam= 0, zCam=0;
GLdouble raio = 50;
GLfloat coordX = 3.003, coordZ = 3.003, passo = 0.5, sinal = 1;
GLfloat pos_car_x=0, pos_car_z = 105, viraCarro = 0;

GLfloat passoEst = 0; GLboolean flagEst = 0; GLint fps = 60;

void Msg(char *string, GLfloat x, GLfloat y){
        glRasterPos2f(x,y);
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,*string++);
}
void FitWindow(GLsizei w, GLsizei h){
     if (w >= h)
        glutReshapeWindow(h, h);
    else
        glutReshapeWindow(w, w);
}
void IdleFunc(){
    glutPostRedisplay();
}
void Reshape(int w, int h){
    if (w >= h)
        glViewport(0, 0, (GLsizei)h, (GLsizei)h) ;
    else
        glViewport(0, 0, (GLsizei)w, (GLsizei)w) ;
    glMatrixMode(GL_PROJECTION) ;
    glLoadIdentity() ;

    InitScreen();
}
void InitScreen(){
    w_width = glutGet(GLUT_WINDOW_WIDTH);
    w_height = glutGet(GLUT_WINDOW_HEIGHT);

    glMatrixMode(GL_PROJECTION); //define que a matrix é a de projeção
    glLoadIdentity(); //carrega a matrix de identidade
    gluPerspective(theta, aspect, d_near, d_far);

    glPushMatrix();
        glRotatef(angX, 1, 0, 0);
        glRotatef(angY, 0, 1, 0);
        glRotatef(angZ, 0, 0, 1);

        glMatrixMode(GL_MODELVIEW); //define que a matrix é a model view
        glLoadIdentity(); //carrega a matrix de identidade

        gluLookAt(x_0, y_0, z_0,
                  x_ref, y_ref, z_ref,
                  V_x, V_y, V_z);
    glPopMatrix();
}

void MovimentaMouse(int x, int y){
    y = w_height - y;
    mouseX = (double)(((double)y/(double)w_height)*2.0 - 1.0);
    mouseY = (double)(((double)x/(double)w_width)*2.0 -1.0);

}

void MouseFunc(int botao, int estado, int x, int y){
    switch (botao){
        case GLUT_LEFT_BUTTON :
            if (estado == GLUT_DOWN){
                y = w_height - y;
                mouseClickX = (float)(((float)x/(float)w_width)*2.0 -1.0);
                mouseClickY = (float)(((float)y/(float)w_height)*2.0 - 1.0);
            }
            break ;
        default :
            break ;
    }
}
void Keyboard (unsigned char key, int x, int y){
    switch (key)    {
    case 'x': angX += 1; break;
    case 'y': angY += 1; break;
    case 'z': angZ += 1; break;
    case 'X': angX -= 1; break;
    case 'Y': angY -= 1; break;
    case 'Z': angZ -= 1; break;

    case 'j':
    case 'J':
        pos_car_x -= 1;
        viraCarro += 2;
        break;
    case 'l':
    case 'L':
        pos_car_x += 1;
        viraCarro -= 2;
        break;
    case 'K': pos_car_z += 1;break;
    case 'k': pos_car_z += 1;break;
    case 'I': pos_car_z -= 1;break;
    case 'i': pos_car_z -= 1;break;

    case 'w': z_0 -= 3; break;
    case 'W': z_0 -= 3; break;
    case 's': z_0 += 3; break;
    case 'S': z_0 += 3; break;
    case 'a': x_0 -= 3; break;
    case 'A': x_0 -= 3; break;
    case 'd': x_0 += 3; break;
    case 'D': x_0 += 3; break;
    case 'e': y_0 += 3; break;
    case 'E': y_0 += 3; break;
    case 'q': y_0 -= 3; break;
    case 'Q': y_0 -= 3; break;
    case 'v': theta += 1; break;
    case 'V': theta -= 1; break;
    case 'f': aspect += 0.2; break;
    case 'F': aspect -= 0.2; break;

    case 'b':
        flagEst = 0;
        break;
    case 'B':
        flagEst = 1;
        TimerFunc(0);
        break;
    default: break;
    }
    InitScreen();
    printf("x_0: %g, y_0: %g, z_0: %g, theta: %g, aspect: %g \n", x_0, y_0, z_0, theta, aspect );
    printf("pos_carX: %.2f - pos_carZ: %.2f\n", pos_car_x, pos_car_z);
}
void SpecialKeys (int key, int x, int y){
   switch(key){
        case GLUT_KEY_RIGHT:
            d_far += 1;
            break;
        case GLUT_KEY_LEFT:
            d_far -= 1;

            break;
        case GLUT_KEY_DOWN:
            d_near -= 1 ;
            break;
        case GLUT_KEY_UP:
            d_near += 1 ;
            break;
        case GLUT_KEY_PAGE_UP:
            fps += 1;
            break;
        case GLUT_KEY_PAGE_DOWN:
            fps -= 1;
            break;
        default:
            break;
    }
    InitScreen();
    printf("d_far: %.2f - d_near: %.2f - fps: %d\n", d_far, d_near, fps);
}

void TimerFunc(int value){
    passoEst = passoEst < 9 ? passoEst + 1 : 0;
    if(flagEst){
        glutTimerFunc(1000/fps, TimerFunc, 1);
        if(viraCarro > 0){
            viraCarro = viraCarro * 0.95;
        }else if (viraCarro < 0){
            viraCarro = viraCarro * 0.95;
        }
    }
    glutPostRedisplay();
}
void DesenhaEstrada(){
    int i,j;
    glColor3fv(verde);
    glBegin(GL_LINES);
        glColor3fv(verde);
        for(i = -10; i <= 10; i++){
            glVertex3f(i *10, 0,  130);
            glVertex3f(i *10, 0, -500);

        }
        for(i = -50; i <= 13; i++){
            glVertex3f( 100, 0, i * 10 + passoEst);
            glVertex3f(-100, 0, i * 10 + passoEst);
        }
    glEnd();
    for(i = -50; i <= 13; i++){
        glPushMatrix();
            glTranslatef( 97.5, 0, i*10 + passoEst);
            glutSolidCube(5);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-97.5, 0, i*10 + passoEst);
            glutSolidCube(5);
        glPopMatrix();
    }
    glLineWidth(1.0);
    glColor3fv(rosaBri);
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
        glVertex3f(0,0,0);
    for(j = 0; j < 90; j ++){
        glVertex3f(500 * cos(j*PI/180)-500, 0, -500 * sin(j*PI/180));
    }
        glVertex3f(-500,0,-500);
    glEnd();
    glPopMatrix();
    glColor3fv(verdeGrama);
    glLineWidth(1.0);
}
void DesenhaGrade(){
//    glLineWidth(4.0);
//    glBegin(GL_LINES);
//        glColor3fv(vermelho);
//        glVertex3f(0, 0,0);
//        glVertex3f(500, 0,0);
//    glEnd();
//    glBegin(GL_LINES);
//        glColor3fv(amarelo);
//        glVertex3f(0, 0,0);
//        glVertex3f(0, 500,0);
//    glEnd();
//    glBegin(GL_LINES);
//        glColor3fv(laranja);
//        glVertex3f(0, 0,0);
//        glVertex3f(0, 0,500);
//    glEnd();
//    glLineWidth(1.0);
}
void Desenha(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer

    DesenhaGrade();
    DesenhaEstrada();
    glPushMatrix();
        glTranslatef(pos_car_x, 0, pos_car_z);
        glTranslatef(0,0,-10);
        glRotatef(viraCarro, 0, 1, 0);
        glTranslatef(0,0, 10);
        DesenhaCarro();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}
int main(int argc, char *argv[]){
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    sw = glutGet(GLUT_SCREEN_WIDTH);
    sh = glutGet(GLUT_SCREEN_HEIGHT);
    winPosX = (sw-sh)/2; winPosY = 0;
    glutInitWindowPosition(winPosX, winPosY);
    glutInitWindowSize(sh, sh);
    glutSetKeyRepeat(1);
    glutCreateWindow("CG TRAB-FINAL - ENDURO");
        FitWindow(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
        glutReshapeFunc(Reshape);
        glutPassiveMotionFunc(MovimentaMouse);
        glutMouseFunc(MouseFunc);
        glutKeyboardFunc(Keyboard);
        glutSpecialFunc(SpecialKeys);
        glutTimerFunc(0,TimerFunc,1);
        glutIdleFunc(IdleFunc);
        glutDisplayFunc(Desenha);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //define a cor de fundo
        glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade
        InitScreen();
    glutMainLoop();
}

