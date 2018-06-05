#include "global.h"

GLfloat abobora[]={.99,.06,.75},     amarelo[]={1,1,0},     azul[]={0,0,1},      azulCeu[]={.53,.81,.98}, azulEsc[]={0,0,.55}, 
        azulMarinho[]={.07,.04,.56}, azulCiano[]={0,1,1},   branco[]={1,1,1},    cinza[]={.5,.5,.5},      cinzaClaro[]={.7,.7,.7},
        cinzaEsc[]={.66,.66,.66},    furchsia[]={1,0,1},    jambo[]={1,.27,0},  fuligem[]={.24,.17,.12}, laranja[]={1,.65,0},
        cinzaFosco[]={.41,.41,.41},  rosa[]={1,.75,.8},   rosaBri[]={1,0,.5}, roxo[]={.5,0,.5},         verde[]={0,1,0},
        verdeGrama[]={.49,.99,0},     verdeEsc[]={0,.39,0}, preto[]={0,0,0},     marrom[]={.65,.16,.16},
        roadColorA[]={.42,.42,.42},  roadColorB[]={.41,.41,.41}, grassColorA[]={.06,.78,.06}, grassColorB[]={0.0,.6,0.0};

GLfloat angX = 0, angY = 0, angZ = 0, passoCam = 10, fps = 60;
GLdouble theta=90,  aspect=1,   d_near=25, d_far=800;
GLdouble x_0=0,     y_0=35.0,   z_0=-150,
         x_ref=0,   y_ref=0,    z_ref=0,
         V_x=0,     V_y=1,      V_z = 0,
         xCam = 0,  yCam= 0,    zCam=0;

Array Linhas; GLint N; GLfloat x = 0, dx = 0;
GLfloat segL = 25, pistaWidht = 100;
GLfloat playerX = 0, carPosX = 0, carPosY = 0, carPosZ = -180;
GLboolean anima = GL_FALSE;

void Keyboard (unsigned char key, int x, int y){
    switch (key){
        case 27:            // ESC
            exit (0);
            break;
        case 'i':
        case 'I':
            pos += segL;
            break;
        case 'k':
        case 'K':
            pos -= segL;
            break;
        case 'j':
        case 'J':
            playerX += segL;
            break;
        case 'l':
        case 'L':
            playerX -= segL;
            break;
        case 'w': z_0 -= passoCam; break;
        case 'W': z_0 -= passoCam; break;
        case 's': z_0 += passoCam; break;
        case 'S': z_0 += passoCam; break;
        case 'a': x_0 -= passoCam; break;
        case 'A': x_0 -= passoCam; break;
        case 'd': x_0 += passoCam; break;
        case 'D': x_0 += passoCam; break;
        case 'e': y_0 += passoCam; break;
        case 'E': y_0 += passoCam; break;
        case 'q': y_0 -= passoCam; break;
        case 'Q': y_0 -= passoCam; break;
        case 'v': theta += 1; break;
        case 'V': theta -= 1; break;

        case 'B':
            anima = GL_TRUE;
            TimerFunc(1000/fps);
            break;
        case 'b':
            anima = GL_FALSE;
            break;
        default: break;
    }
   
    while(pos >= pistaLenght) pos -= pistaLenght;
    while(pos < 0) pos += pistaLenght;
    startPos = pos/segL;
    
    printf("pos: %d - startPos: %d - N: %d\n", pos, startPos, N);
    InitScreen();
}
void SpecialKeys (int key, int x, int y){
    switch(key){
        case GLUT_KEY_RIGHT:
            carPosX += segL;
            break;
        case GLUT_KEY_LEFT:
            carPosX -= segL;

            break;
        case GLUT_KEY_DOWN:
            carPosZ -= segL ;
            break;
        case GLUT_KEY_UP:
            carPosZ += segL ;
            break;
        case GLUT_KEY_PAGE_UP:
            d_far += 2;
            break;
        case GLUT_KEY_PAGE_DOWN:
            d_far -= 2;
            break;
        default:
            break;
    }
    InitScreen();
}

void TimerFunc(int value){
    pos += 1;
    if(anima)
        glutTimerFunc(1000/fps, TimerFunc, 1);
    glutPostRedisplay();
}

void DesenhaEstrada(){
    float *road, *grass, *rumble;
    Line_t *l, *p;
    x = 0;
    dx = 0;
   
    // Draw road /
    for(int n = startPos; n < startPos+500; n++){
        l = &(Linhas.array[n%N]);
        x += dx;
        dx += l->curve;
        l->x = x;
        road   = (n/3)%2 ? roadColorA  : roadColorB;
        grass  = (n/3)%2 ? grassColorA : grassColorB;
        rumble = (n/3)%2 ? preto : branco;

        p = &(Linhas.array[(n-1)%N]);
        
        DesenhaSeg(grass,  playerX - p->x, p->z+pos-(n-1>=N?pistaLenght+segL:0), 800,             playerX - l->x, l->z+pos-(n>=N?pistaLenght+segL:0), 800,     -2);
        DesenhaSeg(rumble, playerX - p->x, p->z+pos-(n-1>=N?pistaLenght+segL:0), pistaWidht *1.2, playerX - l->x, l->z+pos-(n>=N?pistaLenght+segL:0), pistaWidht*1.2, -1);
        DesenhaSeg(road,   playerX - p->x, p->z+pos-(n-1>=N?pistaLenght+segL:0), pistaWidht,      playerX - l->x, l->z+pos-(n>=N?pistaLenght+segL:0), pistaWidht,      0);
        
    }
}

void Desenha(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer
    glPushMatrix();
        DesenhaEstrada();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(carPosX, carPosY, carPosZ);
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
    
    initArray(&Linhas, 802);
    for(int i = 0; i < 800; i++){
        Line_t line;
        line.x = 0;
        line.y = 0;
        line.z = -i * segL;
        line.curve = 0;
        if(i > 0 && i < 300) line.curve = 0.5;
        if(i > 300 && i < 500) line.curve = -0.5;
        insertArray(&Linhas, line);
    }
    N = Linhas.used;
    pos = 0;
    pistaLenght = (N * segL);

    glutCreateWindow("CG TRAB-FINAL - ENDURO");FitWindow(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
        glutReshapeFunc(Reshape);
        glutPassiveMotionFunc(MovimentaMouse);
        glutMouseFunc(MouseFunc);
        glutKeyboardFunc(Keyboard);
        glutSpecialFunc(SpecialKeys);
        glutTimerFunc(0,TimerFunc,1);
        glutIdleFunc(IdleFunc);
        glutDisplayFunc(Desenha);
        glClearColor(.0f, .0f, .0f, .0f); //define a cor de fundo
        glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade
        InitScreen();
    glutMainLoop();
}