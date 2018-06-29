#include "global.h"
#include <unistd.h>
#include <time.h>

GLfloat abobora[]={.99,.06,.75},     amarelo[]={1,1,0},     azul[]={0,0,1},      azulCeu[]={.53,.81,.98}, azulEsc[]={0,0,.55},
        azulMarinho[]={.07,.04,.56}, azulCiano[]={0,1,1},   branco[]={1,1,1},    cinza[]={.5,.5,.5},      cinzaClaro[]={.7,.7,.7},
        cinzaEsc[]={.66,.66,.66},    furchsia[]={1,0,1},    jambo[]={1,.27,0},  fuligem[]={.24,.17,.12}, laranja[]={1,.65,0},
        cinzaFosco[]={.41,.41,.41},  rosa[]={1,.75,.8},   rosaBri[]={1,0,.5}, roxo[]={.5,0,.5},         verde[]={0,1,0},
        verdeGrama[]={.49,.99,0},     verdeEsc[]={0,.39,0}, preto[]={0,0,0},     marrom[]={.65,.16,.16},vermelho[]={1,0,0},
        roadColorA[]={.42,.42,.42},  roadColorB[]={.41,.41,.41}, grassColorA[]={.06,.78,.06}, grassColorB[]={0.0,.6,0.0};

// Camera
GLboolean botoes[] = {false, false, false, false};
GLdouble theta=90,  aspect=1,   d_near=1, d_far=1800;
GLdouble x_0=0,     y_0=40.0,   z_0= -100,
         x_ref=0,   y_ref=0,    z_ref=-200,
         V_x=0,     V_y=1,      V_z = 0,
         xCam = 0,  yCam= 0,    zCam=0;

// Game
GLboolean anima = false, colidiu = false;
GLint contaCor = 0, voltaAnt = 0; 
GLfloat pontuacao = 0, posCeu = 0, R = 1, G = 1, B = 0;
GLchar pontuacaoStr[12];


// Pista
GLint tamPista = 19000, larPista = 80, volta = 0;


// Jogador
GLfloat s_car = 1;
GLint pos = 0;
GLfloat carPosX = 0.0, viraCarro = 0, speed = 1;

// Bot
GLint posBot = 500;
GLfloat *corBot[] = {amarelo, verde, azul, rosa};
GLint teste = 0;

void initArray(Array *a, size_t initialSize) {
    a->ponto = (Ponto_t *)calloc(initialSize , sizeof(Ponto_t));
    a->used = 0;
    a->size = initialSize;
}
void insertArray(Array *a, Ponto_t element) {
    if (a->used == a->size) {
        a->size *= 2;
        a->ponto = (Ponto_t *)realloc(a->ponto, a->size * sizeof(Ponto_t));
    }
    a->ponto[a->used++] = element;
}

void freeArray(Array *a) {
    free(a->ponto);
    a->ponto = NULL;
    a->used = a->size = 0;
}

void delay(float secs){
	float end = clock()/CLOCKS_PER_SEC + secs;
	while((clock()/CLOCKS_PER_SEC) < end);
}

void Msg(char *string, GLfloat x, GLfloat y){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
        glRasterPos2f(x,y);
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,*string++);
    glutPostRedisplay();
}
void MsgGde(char *string, GLfloat x, GLfloat y, GLfloat *cor){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
    glColor3fv(cor);
    glRasterPos2f(x,y);
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
    glutPostRedisplay();
}
void Msg2(char *string, GLfloat x, GLfloat y, GLfloat *cor){
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 500.0);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0, 0, 10, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Altere aqui para visualizar diferentes estilos, seta 3 item para algo 10 pra tu ver
        glScalef(.005,.005,.005); // AUmenta e diminui o tamanho da letra
        glTranslatef(-300, y, 0);
            
        glColor3fv(cor);
        glLineWidth(15.0);
        while(*string)
             glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,*string++);
        glLineWidth(1.0);
        glutPostRedisplay();
}

void InitScreen(){
    w_width = glutGet(GLUT_WINDOW_WIDTH);
    w_height = glutGet(GLUT_WINDOW_HEIGHT);

    glMatrixMode(GL_PROJECTION); //define que a matrix é a de projeção
    glLoadIdentity(); //carrega a matrix de identidade
    gluPerspective(theta, aspect, d_near, d_far);

    glPushMatrix();
        glMatrixMode(GL_MODELVIEW); //define que a matrix é a model view
        glLoadIdentity(); //carrega a matrix de identidade
        gluLookAt(x_0,   y_0,   z_0,
                  x_ref, y_ref, z_ref,
                  V_x,   V_y,   V_z);
    glPopMatrix();
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambiente);
  
    //Controle do ambiente
    if(volta != voltaAnt2){
        voltaAnt2 = volta;
        contaCor2 = (contaCor2+1) % 4;
    }
    if(contaCor2 == 3){
        ambiente[0] = 1.0 - B;
        ambiente[1] = 1.0 - B;
        ambiente[2] = 1.0 - B;
        ambiente[4] = 1.0;
    }
    else if(contaCor2 == 2){
        ambiente[0] = 1.0;
        ambiente[1] = 1.0;
        ambiente[2] = 1.0;
        ambiente[4] = 1.0;
    }
    else if(contaCor2 == 1){
        ambiente[0] = B;
        ambiente[1] = B;
        ambiente[2] = B;
        ambiente[4] = 1.0;
    }
    else{
        ambiente[0] = 0.0;
        ambiente[1] = 0.0;
        ambiente[2] = 0.0;
        ambiente[4] = 1.0;
    }
    printf("contador: %d  R: %.3f  G: %.3f  B: %.3f\n", contaCor2, R, G, B);
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

// check if the car is touching border or not
// por algum motivo  M I S T E R I O S O  não consegui colocar as duas
// condições dentro do mesmo método. Bizarro mesmo. Separei em touch left/right
int isTouchingLeft(){
    return carPosX >= -(larPista/2+30) ? 0 : 1; //touching left side
}

int isTouchingRight(){
    return carPosX <= larPista/2+30 ? 0 : 1; //touching right side
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
void DesenhaSeg(GLfloat *cor, float x1, float y1, float z1, 
                              float x2, float y2, float z2, float w){
    glColor3fv(cor);
    glBegin(GL_QUADS);
        glVertex3f(x1-w,y1,z1);
        glVertex3f(x2-w,y2,z2);
        glVertex3f(x2+w,y2,z2);
        glVertex3f(x1+w,y1,z1);
    glEnd();
}

void Keyboard (unsigned char key, int x, int y){
    // printf("key_: %d\n", key);
    int timerID = 0;
    switch (key){
        case 27:            // ESC
            exit (0);
            break;
        case 13:            // ENTER
            
            break;
        case 32:            // SPACE
            anima = anima ? false : true;
            TimerFunc(timerID);
            speed = 1;
            break;
        case 'w':
        case 'W':  botoes[0] = true;  break;
        case 's':
        case 'S':  botoes[1] = true;  break;
        case 'a':
        case 'A':  botoes[2] = true;  break;
        case 'd':
        case 'D':  botoes[3] = true;  break;

        default: break;
    }
    InitScreen();
}

void UpKeyboard (unsigned char key, int x, int y){
    switch (key){
        case 'w':
        case 'W':  botoes[0] = false;  break;
        case 's':
        case 'S':  botoes[1] = false;  break;
        case 'a':
        case 'A':  botoes[2] = false;  break;
        case 'd':
        case 'D':  botoes[3] = false;  break;
    }
}

void SpecialKeys (int key, int x, int y){
    // printf("key: %d\n", key);
    switch(key){
        case GLUT_KEY_RIGHT:
            carPosX += 1;
            printf("carPosX: %g\n", carPosX);
            break;
        case GLUT_KEY_LEFT:
            carPosX -= 1;
            printf("carPosX: %g\n", carPosX);
            break;
        case GLUT_KEY_UP:
            pos += 1;
            printf("pos: %d - posBot: %d\n", pos, posBot);
            break;
        case GLUT_KEY_DOWN:
            pos -= 1;
            printf("pos: %d - posBot: %d\n", pos, posBot);
            break;
        default:
            break;
    }
    printf("posBot: %d\n", posBot);
}
GLfloat posAct = -1.9, Ytitulo1 = 0;
GLboolean flagIntro = false,flagIntro2= false, flagIntro3 = false;
void TimerFuncIntro(int valor){
    int f = valor+1;
    if(posAct < 0)
        posAct += 0.0007;
    glutPostRedisplay();
    if(valor < 200)
        glutTimerFunc(30,TimerFuncIntro, f);
    else
        flagIntro = true;
}
void desenha_actvision () {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer
    glColor3f(1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glutTimerFunc(0,TimerFuncIntro, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-1.0,1.0,-1.0,1.0);

    glPushMatrix();
        glTranslatef(posAct,0.0,0.0);
        glScalef(0.35,0.35,0.35);
        glColor3f(1.00, 0.75, 0.25);
        //  E
        glPushMatrix();
            glTranslatef(-3,-3.0,0.0);
            glBegin(GL_QUADS);
                //glTranslatef(-3.0,-3.0,0.0);
                //Arco-iris
                glColor3f(255, 0.0, 0.0);
                glVertex2f(0.00, 2.00); glVertex2f(0.00, 2.20);
                glVertex2f(1.00, 2.20);	glVertex2f(1.00, 2.00);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glColor3f(1, 0.5, 0);
                glVertex2f(0.00, 2.20);	glVertex2f(0.00, 2.39);
                glVertex2f(1.00, 2.39);	glVertex2f(1.00, 2.20);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glColor3f(255, 100, 0.0);
                glVertex2f(0.00, 2.39);	glVertex2f(0.00, 2.58);
                glVertex2f(1.00, 2.58);	glVertex2f(1.00, 2.39);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glColor3f(0, 255, 0.0);
                glVertex2f(0.00, 2.58);	glVertex2f(0.00, 2.77);
                glVertex2f(1.00, 2.77);	glVertex2f(1.00, 2.58);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glColor3f(0.0, 0.0, 255);
                glVertex2f(0.00, 2.77);	glVertex2f(0.00, 2.97);
                glVertex2f(1.00, 2.97);	glVertex2f(1.00, 2.77);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glColor3f(120, 0.0, 255);
                glVertex2f(0.00, 2.97);	glVertex2f(0.00, 3.17);
                glVertex2f(1.00, 3.17);	glVertex2f(1.00, 2.97);
            glEnd();
        glPopMatrix();

        glColor3f(1.00, 1, 1);
        //Inicio das letras
        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
            //A
            glVertex2f(1.00, 2.00);	glVertex2f(1.00, 3.17);
            glVertex2f(1.19, 3.17);	glVertex2f(1.19, 2.00);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glVertex2f(1.0, 3.18);	glVertex2f(1.18, 3.18);
                glVertex2f(1.68, 2.00);	glVertex2f(1.50, 2.00);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glVertex2f(1.20, 2.39);	glVertex2f(1.32, 2.39);
                glVertex2f(1.39, 2.27);	glVertex2f(1.20, 2.27);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                //C
                glVertex2f(2.00, 2.00);	glVertex2f(1.60, 2.55);
                glVertex2f(1.60, 2.26);	glVertex2f(1.68, 2.00);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glVertex2f(1.60, 2.55);	glVertex2f(1.68, 2.74);
                glVertex2f(2.00, 2.74);	glVertex2f(1.60, 2.26);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                //T
                glVertex2f(2.03, 2.00);	glVertex2f(2.15, 2.00);
                glVertex2f(2.15, 2.86);	glVertex2f(2.03, 2.86);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glVertex2f(2.66, 2.86);	glVertex2f(1.50, 2.86);
                glVertex2f(1.50, 3.00);	glVertex2f(2.66, 3.00);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                //V
                glVertex2f(2.24, 2.00);	glVertex2f(2.24, 2.50);
                glVertex2f(2.40, 2.50);	glVertex2f(2.40, 2.00);
            glEnd();
        glPopMatrix();
        //I
        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glVertex2f(2.35, 2.85);	glVertex2f(2.76, 2.00);
                glVertex2f(3.13, 2.85);	glVertex2f(2.93, 2.85);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glVertex2f(3.05, 2.47);	glVertex2f(3.05, 2.00);
                glVertex2f(3.20, 2.00);	glVertex2f(3.20, 2.47);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glVertex2f(3.86, 2.58);	glVertex2f(3.86, 2.77);
                glVertex2f(3.40, 2.77);	glVertex2f(3.25, 2.57);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glVertex2f(3.28, 2.20);	glVertex2f(3.28, 2.00);
                glVertex2f(3.72, 2.00);	glVertex2f(3.85, 2.20);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glVertex2f(3.25, 2.57);	glVertex2f(3.39, 2.77);
                glVertex2f(3.85, 2.20);	glVertex2f(3.70, 2.02);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glVertex2f(3.93, 2.00);	glVertex2f(3.93, 2.63);
                glVertex2f(4.10, 2.63);	glVertex2f(4.10, 2.00);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glVertex2f(4.20, 2.63);	glVertex2f(4.27, 2.77);
                glVertex2f(4.74, 2.77);	glVertex2f(4.80, 2.63);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glVertex2f(4.74, 2.77);	glVertex2f(4.80, 2.64);
                glVertex2f(4.80, 2.17);	glVertex2f(4.74, 2.08);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glVertex2f(4.27, 2.77);	glVertex2f(4.20, 2.63);
                glVertex2f(4.20, 2.18);	glVertex2f(4.27, 2.04);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glVertex2f(4.80, 2.18);	glVertex2f(4.74, 2.04);
                glVertex2f(4.27, 2.04);	glVertex2f(4.24, 2.18);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glVertex2f(4.93, 2.02);	glVertex2f(4.93, 2.74);
                glVertex2f(5.06, 2.74);	glVertex2f(5.06, 2.02);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glVertex2f(4.93, 2.74);	glVertex2f(5.33, 2.00);
                glVertex2f(5.44, 2.00);	glVertex2f(5.06, 2.74);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glVertex2f(5.33, 2.00);	glVertex2f(5.33, 2.74);
                glVertex2f(5.44, 2.74);	glVertex2f(5.45, 2.00);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-3.0,-3.0,0.0);
            glBegin(GL_QUADS);
                glVertex2f(2.66, 2.86);	glVertex2f(2.66, 3.00);
                glVertex2f(4.14, 3.00);	glVertex2f(4.14, 2.86);
            glEnd();
        glPopMatrix();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
    if(flagIntro)
        glutDisplayFunc(Titulo1);
}

void TimerFuncIntro2(int valor){
    int f = valor+1;
    if(Ytitulo1 < 200)
        Ytitulo1 += 0.2;
    glutPostRedisplay();
    if(valor < 100)
        glutTimerFunc(2,TimerFuncIntro2    , f);
    else
        flagIntro2 = true;
}
//Mostra o logo do Enduro
void Titulo1(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer
       
    glutTimerFunc(0,TimerFuncIntro2, 0);
    Msg2("Enduro", 0,Ytitulo1, verdeGrama);

    glFlush();
    glutSwapBuffers();
        
    glFlush();
    glutSwapBuffers();
    if(flagIntro2)
        glutDisplayFunc(Titulo2);
}
void TimerFuncIntro3(int valor){
    int f = valor+1;
    if(valor < 200)
        glutTimerFunc(20,TimerFuncIntro3    , f);
    else
        flagIntro3 = true;
}
//Mostra alguma outra coisa
void Titulo2(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer
    
    glutTimerFunc(0,TimerFuncIntro3, 0);
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
    Msg2("Enduro", -.1,Ytitulo1, verdeGrama);
    MsgGde("Eduardo"    ,-0.14  , 0.4, branco);
    MsgGde("Fernando"   ,-0.16   , 0.3, branco);
    MsgGde("Magno"      ,-0.125 , 0.2, branco);
    MsgGde("Takaki"     ,-0.125 , 0.1, branco);
    MsgGde("Yoji"       ,-0.09  , 0.0, branco);
    
    
    glFlush();
    glutSwapBuffers();
    if(flagIntro3)
        glutDisplayFunc(Desenha);
}
