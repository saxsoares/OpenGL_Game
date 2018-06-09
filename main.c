
#include "global.h"
#define false GL_FALSE
#define true GL_TRUE

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
GLint N, TimeFlag = 0, volta = 0;
GLfloat segL = 15, pistaWidth = 70, x = 0, dx = 0;;
GLfloat playerX = 0, carPosX = 0, carPosY = 0, carPosZ = -194, s_car = 1, viraCarro = 0.1, speed = 1;
GLboolean anima = GL_FALSE;
GLboolean botoes[] = {false, false, false, false};

void Keyboard (unsigned char key, int x, int y){
    switch (key){
        case 27:            // ESC
            exit (0);
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

    while(pos >= pistaLenght) pos -= pistaLenght;
    while(pos < 0) pos += pistaLenght;
    startPos = pos/segL;

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
    switch(key){
        case GLUT_KEY_PAGE_UP:
            anima = GL_TRUE;
            TimeFlag++;
            TimerFunc(TimeFlag-1);
            break;
        case GLUT_KEY_PAGE_DOWN:
            TimeFlag--;
            if(!TimeFlag) anima = false;
            break;
        default:
            break;
    }
}

void TimerFunc(int value){
    int f = value;
    pos += 1 + speed;
    while(pos >= pistaLenght) pos =0;	//Troquei de "pos -= pistaLenght;" para o atual para evitar inconsistencias com a virada da volta.
    while(pos < 0) pos += pistaLenght;
    startPos = pos/segL;

	//Controle do céu
	if(volta%4 == 3 && (int)pos%18000!=0)glClearColor(.0f, .0f, pos/18000, .0f);
	else if (volta%4 == 1 && (int)pos%18000!=0)glClearColor(.0f, .0f, 1-(pos/18000), .0f);
	
	//Controle de velocidade
	if((int)pos%18000 == 0) volta++; 	//Cada volta no mapa tem 18000 posições.
	if(speed<35+(volta*2)) speed += 0.1;//Aceleracao maxima 35, aumenta em 2 para cada volta.
	if(speed<20) speed += 0.1;			//Aceleracao 0.2 quando abaixo de speed 20.
	if(speed<5) speed += 0.1;			//Aceleracao 0.3 quando abaixo de speed 05.
	
	//Inércia nas curvas
	if((pos>1500 && pos<3000) || (pos>7500 && pos<12000)){ //Curva para a direita.
		if(carPosX >= -(pistaWidth/2+25)) carPosX--;	
	}
	if((pos>4500 && pos<7500) || (pos>14500 && pos<18000)){ //Curva para a esquerda.
		if(carPosX <= pistaWidth/2+20) carPosX++;
	}	
	
    if(anima && f < TimeFlag)
        glutTimerFunc(1, TimerFunc, f);
    glutPostRedisplay();
}

void DesenhaEstrada(){
    float *road, *grass, *rumble;
    Line_t *l, *p;
    x = 0;
    dx = 0;
    Msg("Fernasdnasdasd", 0, 0);
    // Draw road /
    for(int n = startPos; n < startPos+600; n++){
        l = &(Linhas.array[n%N]);
        x += dx;
        dx += l->curve;
        l->x = x;

        road   = (n/11)%2 ? roadColorA  : roadColorB;
        grass  = (n/11)%2 ? grassColorA : grassColorB;
        rumble = (n/11)%2 ? preto : branco;

        p = &(Linhas.array[(n-1)%N]);

        DesenhaSeg(grass,   p->x, p->z+pos-(n-1>=N?pistaLenght+segL:0), -2,  2000,
                            l->x, l->z+pos-(n>=N?pistaLenght+segL:0),   -2, 2000);

        DesenhaSeg(rumble, p->x, p->z+pos-(n-1>=N?pistaLenght+segL:0), -1, pistaWidth *1.2,
                           l->x, l->z+pos-(n>=N?pistaLenght+segL:0),   -1, pistaWidth *1.2);

        DesenhaSeg(road,   p->x, p->z+pos-(n-1>=N?pistaLenght+segL:0), 0, pistaWidth,
                           l->x, l->z+pos-(n>=N?pistaLenght+segL:0),   0,pistaWidth);

        }

         glPushMatrix();
            glTranslatef(0+dx, 0, - 450+0.1*pos);
            glScalef(s_car, s_car, s_car);
            glTranslatef(0,0,-5);
            glRotatef(2*Linhas.array[(int)startPos].curve, 0, 1, 0);
            glRotatef(-20*Linhas.array[(int)startPos].curve, 0, 0, 1);
            glTranslatef(0,0, 5);
            DesenhaCarro(0, 0, 1);
        glPopMatrix();

}

void Desenha(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer
    glPushMatrix();
        DesenhaEstrada();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(carPosX, carPosY, carPosZ);
        glScalef(s_car, s_car, s_car);
        glTranslatef(0,0,-5);
        glRotatef(viraCarro+2*Linhas.array[(int)startPos].curve, 0, 1, 0);
        glRotatef(-0.5*viraCarro-20*Linhas.array[(int)startPos].curve, 0, 0, 1);
        glTranslatef(0,0, 5);
        DesenhaCarro(1, 0, 0);
    glPopMatrix();

    /* Controle de velocidade do carro é automático, não precisa se mover com W e S.
	if(botoes[0]){
        pos += 2;
    }
    if(botoes[1]){
        pos -= 2;
    }
    */
	if(botoes[2]){
        carPosX = carPosX >=  -(pistaWidth/2+30)? carPosX - 1.3: carPosX;
        viraCarro = viraCarro > 25 ? viraCarro : viraCarro + 0.8;
        if(anima) pos -= abs(carPosX) * 0.05;
    }
    if(botoes[3]){
        carPosX = carPosX <=  pistaWidth/2+30? carPosX + 1.3: carPosX;
        viraCarro = viraCarro <-25 ? viraCarro : viraCarro - 0.8;
        if(anima) pos -= abs(carPosX) * 0.05;
    }

    if(!botoes[2] && !botoes[3]){
        if(viraCarro > 0){
            viraCarro = viraCarro * 0.95;
        }else if (viraCarro < 0){
            viraCarro = viraCarro * 0.95;
        }
    }
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
    for(int i = 0; i < 1200; i++){
        Line_t line;
        line.x = 0;
        line.y = 0;
        line.z = -i * segL;
        line.curve = 0;
        if(i > 100 && i < 200) line.curve = 0.1;
        if(i > 300 && i < 500) line.curve = -0.1;
        if(i > 500 && i < 800) line.curve = 0.1;
        if(i > 900 && i < 1200) line.curve = -0.1;

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
        glutKeyboardUpFunc(UpKeyboard);
        glutSpecialFunc(SpecialKeys);
        glutTimerFunc(0,TimerFunc,1);
        glutIdleFunc(IdleFunc);
        glutDisplayFunc(Desenha);
        glClearColor(0.0f, 0.0f, 1.0f, 0.0f); //define a cor de fundo
        glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade
        InitScreen();
    glutMainLoop();
}
