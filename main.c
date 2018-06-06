#include "global.h"
#include <unistd.h>

GLfloat abobora[]={.99,.06,.75},     amarelo[]={1,1,0},     azul[]={0,0,1},      azulCeu[]={.53,.81,.98}, azulEsc[]={0,0,.55}, 
        azulMarinho[]={.07,.04,.56}, azulCiano[]={0,1,1},   branco[]={1,1,1},    cinza[]={.5,.5,.5},      cinzaClaro[]={.7,.7,.7},
        cinzaEsc[]={.66,.66,.66},    furchsia[]={1,0,1},    jambo[]={1,.27,0},  fuligem[]={.24,.17,.12}, laranja[]={1,.65,0},
        cinzaFosco[]={.41,.41,.41},  rosa[]={1,.75,.8},   rosaBri[]={1,0,.5}, roxo[]={.5,0,.5},         verde[]={0,1,0},
        verdeGrama[]={.49,.99,0},     verdeEsc[]={0,.39,0}, preto[]={0,0,0},     marrom[]={.65,.16,.16},
        roadColorA[]={.42,.42,.42},  roadColorB[]={.41,.41,.41}, grassColorA[]={.06,.78,.06}, grassColorB[]={0.0,.6,0.0};

GLfloat angX = 0, angY = 0, angZ = 0, passoCam = 1, fps = 60;
GLdouble theta=90,  aspect=1,   d_near=1, d_far=1800;
GLdouble x_0=0,     y_0=42.0,   z_0=-118,
         x_ref=0,   y_ref=0,    z_ref=-210,
         V_x=0,     V_y=1,      V_z = 0,
         xCam = 0,  yCam= 0,    zCam=0;

Array Linhas; 
GLint N, TimeFlag = 0;
GLfloat segL = 15, pistaWidht = 70, x = 0, dx = 0;;
GLfloat playerX = 0, carPosX = 0, carPosY = 0, carPosZ = -194, s_car = 1;
GLboolean anima = GL_FALSE;

void Keyboard (unsigned char key, int x, int y){
    switch (key){
        case 27:            // ESC
            exit (0);
            break;
        case 'i':
        case 'I':  pos += segL;  break;
        case 'k':
        case 'K':  pos -= segL;  break;
        case 'j':
        case 'J':  playerX += 1;  break;
        case 'l':
        case 'L':  playerX -= 1;  break;
       
    
        case 'B':
            anima = GL_TRUE;
            TimeFlag++;
            TimerFunc(TimeFlag-1);
            break;
        case 'b':
            TimeFlag--;
            break;
        default: break;
    }
   
    while(pos >= pistaLenght) pos -= pistaLenght;
    while(pos < 0) pos += pistaLenght;
    startPos = pos/segL;
    
    InitScreen();
}
void SpecialKeys (int key, int x, int y){
    switch(key){
        default:
            break;
    }
}

void TimerFunc(int value){
    int f = value;
    if (Linhas.array[(int)startPos].curve != 0 ){
        if(f == 0){
            pos += segL;
            usleep(100000);
        }
        else ;
    }
    else
        pos = pos + 1;

    while(pos >= pistaLenght) pos -= pistaLenght;
    while(pos < 0) pos += pistaLenght;
    startPos = pos/segL;
    printf("startPos: %.2f - pos: %.2f - x: %.2f - dx: %.2f\n",startPos, pos, x, dx );
    if(anima && f < TimeFlag)
        glutTimerFunc(1000/fps, TimerFunc, f);
    glutPostRedisplay();
}

void DesenhaEstrada(){
    float *road, *grass, *rumble;
    Line_t *l, *p;
    x = 0;
    dx = 0;
   
    // Draw road /
    for(int n = startPos; n < startPos+600; n++){
        l = &(Linhas.array[n%N]);
        x += dx;
        dx += l->curve;
        l->x = x;
        road   = (n/3)%2 ? roadColorA  : roadColorB;
        grass  = (n/3)%2 ? grassColorA : grassColorB;
        rumble = (n/3)%2 ? preto : branco;

        p = &(Linhas.array[(n-1)%N]);
        
        DesenhaSeg(grass,  carPosX + playerX - p->x, p->z+pos-(n-1>=N?pistaLenght+segL:0), 2000,  
                           carPosX + playerX - l->x, l->z+pos-(n>=N?pistaLenght+segL:0), 2000,     -2);
        
        DesenhaSeg(rumble, carPosX + playerX - p->x, p->z+pos-(n-1>=N?pistaLenght+segL:0), pistaWidht *1.2, 
                           carPosX + playerX - l->x, l->z+pos-(n>=N?pistaLenght+segL:0), pistaWidht*1.2, -1);
        
        DesenhaSeg(road,   carPosX + playerX - p->x, p->z+pos-(n-1>=N?pistaLenght+segL:0), pistaWidht, 
                           carPosX + playerX - l->x, l->z+pos-(n>=N?pistaLenght+segL:0), pistaWidht,      0);
        
    }
}

void Desenha(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer
    glPushMatrix();
        DesenhaEstrada();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(carPosX, carPosY, carPosZ);
        glScalef(s_car, s_car, s_car);
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
    for(int i = 0; i < 700; i++){
        Line_t line;
        line.x = 0;
        line.y = 0;
        line.z = -i * segL;
        line.curve = 0;
        if(i > 0 && i < 100) line.curve = 0.5;
        if(i > 200 && i < 600) line.curve = -0.5;
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