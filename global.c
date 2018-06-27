#include "global.h"
#include <unistd.h>
<<<<<<< HEAD
#include <time.h>

=======
>>>>>>> master
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


// Pista
GLint tamPista = 15000, larPista = 80, volta = 0;


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
        glRasterPos2f(x,y);
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,*string++);
}
void MsgGde(char *string, GLfloat x, GLfloat y){
        glRasterPos2f(x,y);
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
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

    //Iluminacao
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    float difusao[]={1.0, 1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, difusao);

    //Controle do ambiente
    if(volta != voltaAnt2){
        voltaAnt2 = volta;
        contaCor2 = (contaCor2+1) % 4;
    }
    if(contaCor2 == 3){
        ambiente[0] = 1.0 - ((float)pos/(float)tamPista) > 0.3 ? 1.0 - ((float)pos/(float)tamPista) : 0.3;
        ambiente[1] = 1.0 - ((float)pos/(float)tamPista) > 0.3 ? 1.0 - ((float)pos/(float)tamPista) : 0.3;
        ambiente[2] = 1.0 - ((float)pos/(float)tamPista) > 0.3 ? 1.0 - ((float)pos/(float)tamPista) : 0.3;
        printf("contaCor2==3: %f\n", ambiente[1]);
        ambiente[4] = 1.0;
    }
    else if(contaCor2 == 2){
        ambiente[0] = 1.0;
        ambiente[1] = 1.0;
        ambiente[2] = 1.0;
        printf("contaCor2==2: %f\n", ambiente[1]);
        ambiente[4] = 1.0;
    }
    else if(contaCor2 == 1){
        ambiente[0] = ((float)pos/(float)tamPista) > 0.3 ? ((float)pos/(float)tamPista) : 0.3;
        ambiente[1] = ((float)pos/(float)tamPista) > 0.3 ? ((float)pos/(float)tamPista) : 0.3;
        ambiente[2] = ((float)pos/(float)tamPista) > 0.3 ? ((float)pos/(float)tamPista) : 0.3;
        printf("contaCor2==1: %f\n", ambiente[1]);
        ambiente[4] = 1.0;
    }
    else{
        ambiente[0] = 0.3;
        ambiente[1] = 0.3;
        ambiente[2] = 0.3;
        printf("contaCor2==0: %f\n", ambiente[1]);
        ambiente[4] = 1.0;
    }
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambiente);
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
 
<<<<<<< HEAD
=======
void DesenhaBots(GLfloat *cor, GLint dzBot, GLint dx){
    // Verifica se posBot+dzBot esta dentro do range (0-tamPista)
    if((posBot + dzBot) > tamPista){
        dzBot = -(tamPista - dzBot);
    }
    GLint da = abs(Pontos.ponto[posBot+dzBot].z - Pontos.ponto[pos].z);
    GLint db = abs(tamPista - abs(Pontos.ponto[pos].z) + abs(Pontos.ponto[posBot+dzBot].z)); // Se um ja reiniciou a pista e o outro nao
    GLint distBotfromPlayer = da > db ? db : da;        // Distancia real entre o bot e o player
    glPushMatrix();     // BOT
        glTranslatef(Pontos.ponto[posBot+dzBot].x + dx, 0,Pontos.ponto[posBot+dzBot].z+pos-(Pontos.ponto[posBot+dzBot].z+pos > 0 ? tamPista : 0));
        glTranslatef(0,0,-5);       // Calculo de quanto o bot vira nas curvas em função da distancia entre ele e o bot e se o player esta ou nao em curva
        glRotatef(- ((int)(Pontos.ponto[posBot+dzBot].curve*1000) ? Pontos.ponto[posBot+dzBot].curve : Pontos.ponto[pos].curve) * 1200 * (distBotfromPlayer/35), 0, 1, 0);
        glRotatef(Pontos.ponto[posBot+dzBot].curve * 2000, 0, 0, 1);
        glTranslatef(0,0,+5);
        glScalef(s_car, s_car, s_car);
        DesenhaCarro(cor);
    glPopMatrix();

    if(Pontos.ponto[pos].curve == 0.0){
        if( (pos > (posBot+dzBot-220) && pos < posBot+dzBot-140) && (              // estao na mesma posicao em z
            (carPosX - 18 <= dx && carPosX >= dx) || // player do lado direito do bot
            (carPosX + 18 >= dx && carPosX <= dx) )  // player do lado esquerdo do bot
        )  
        {
            colidiu = true;
            posQndoBateu = 0;
            
        }
    }else if(Pontos.ponto[pos].curve > 0.0){
        if( (pos > (posBot+dzBot-220) && pos < posBot+dzBot-140) && (              // estao na mesma posicao em z
            (carPosX - 26 <= dx && carPosX >= dx) || // player do lado direito do bot
            (carPosX + 10 >= dx && carPosX <= dx) )  // player do lado esquerdo do bot
        )  
        {
            colidiu = true;
            posQndoBateu = 0;
            
        }
    }else if(Pontos.ponto[pos].curve < 0.0){
        if( (pos > (posBot+dzBot-220) && pos < posBot+dzBot-140) && (              // estao na mesma posicao em z
            (carPosX - 10 <= dx && carPosX >= dx) || // player do lado direito do bot
            (carPosX + 26 >= dx && carPosX <= dx) )  // player do lado esquerdo do bot
        )  
        {
            colidiu = true;
            posQndoBateu = 0;
            
        }
    }
}

>>>>>>> master
