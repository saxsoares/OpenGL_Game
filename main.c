#include "global.h"


//Mostra o logo do Enduro
void Titulo1(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer
    glColor3f(1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-1.0,1.0,-1.0,1.0);

    MsgGde("Enduro", -.1,0);

    glFlush();
    glutSwapBuffers();
    delay(2);
    glutDisplayFunc(Titulo2);
}
//Mostra alguma outra coisa
void Titulo2(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer
      
    glColor3f(1.0,1.0,1.0);
    	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
    MsgGde("Grupo", -.1,0);

    glFlush();
    glutSwapBuffers();
    delay(2);
    glutDisplayFunc(Desenha);
}

void DesenhaPista(){
    Ponto_t *p2, *p1;
    int n;
    x= 0;
    dx = 0;
    // Pontos.ponto[posBot].bot = true;
    for(n = pos; n < pos+2500; n++){
        
        p1 = &(Pontos.ponto[(n-1)%tamPista]);
        p2 = &(Pontos.ponto[n%tamPista]);
        x += dx;
        dx += p2->curve;
        p2->x = x;
       
        DesenhaSeg(p1->cor? grassColorA : grassColorB,  
                    p1->x, p1->y-2, p1->z+pos-(n-1>=tamPista?tamPista:0), 
                    p2->x, p2->y-2, p2->z+pos-(n  >=tamPista?tamPista:0), larPista*200);
        DesenhaSeg(p1->cor? preto : branco,
                    p1->x, p1->y-1, p1->z+pos-(n-1>=tamPista?tamPista:0), 
                    p2->x, p2->y-1, p2->z+pos-(n  >=tamPista?tamPista:0), larPista*1.2);
        DesenhaSeg(p1->cor? roadColorA: roadColorB,   
                    p1->x, p1->y,   p1->z+pos-(n-1>=tamPista?tamPista:0), 
                    p2->x, p2->y,   p2->z+pos-(n  >=tamPista?tamPista:0), larPista);

        
    }
}

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

void TimerFunc(int valor){
    int f = valor;
    if(colidiu){
        if(posQndoBateu > 100) {
            colidiu = false;
        }else{
            speed = 0.98 * speed > 8 ? 0.98 * speed : 2;
            pos = pos - 0.5;
            posBot += 2;
            if(viraCarro > 0){
                viraCarro = viraCarro * 0.90;
            }else if (viraCarro < 0){
                viraCarro = viraCarro * 0.90;
            }
            posQndoBateu++;
        }
    }
    else{
        pos += speed ;
    }
    posBot += 0.8*speed;
        
    while(pos >= tamPista){
        pos -= tamPista;
        volta++;
    }
    while(pos < 0)            pos += tamPista;
    while(posBot >= tamPista) posBot -= tamPista;
    while(posBot < 0)         posBot += tamPista;
  
    //Controle do céu
    if(volta != voltaAnt){
        voltaAnt = volta;
        contaCor = (contaCor+1) % 4;
    }
    if(contaCor == 3){
        glClearColor(.0f, .0f, 1.0 - ((float)pos/(float)tamPista), .0f);
    }
    else if(contaCor == 2){
        glClearColor(.0f, .0f, 1.0, .0f);
    }
    else if(contaCor == 1){
        glClearColor(.0f, .0f, ((float)pos/(float)tamPista), .0f);
    }
    else{
        glClearColor(.0f, .0f, 0, .0f);
    }
    //Controle de velocidade
    // if((int)pos%tamPista == 0) volta++; //Cada volta no mapa tem tamPista posições.
    if(speed<15+(volta*2)) speed += 0.005;//Aceleracao maxima 35, aumenta em 2 para cada volta.
    if(speed<10) speed += 0.005;			//Aceleracao 0.2 quando abaixo de speed 20.
    if(speed<5) speed += 0.005;			//Aceleracao 0.3 quando abaixo de speed 05.
    
    //Inércia nas curvas
    if(Pontos.ponto[pos].curve > 0 ){ //Curva para a direita.
        if(carPosX >= -(larPista/2+25)) 
            carPosX = carPosX-1.3*speed/(15+(volta*2));	
    }
    if(Pontos.ponto[pos].curve < 0 ){ //Curva para a esquerda.
        if(carPosX <= larPista/2+25) 
            carPosX = carPosX+1.3*speed/(15+(volta*2));
    }
    
    // debug (ignore)
    //printf("posCarro: %lf \t tamPista: %d\n", carPosX, tamPista);

    // verifica se o carro está tocando alguma das bordas e desacelera
    if(isTouchingRight() || isTouchingLeft()){
        pos -= (0.12 * speed);
        posBot += 0.15 * speed;
        speed -= 0.02;
    }

    InitScreen();
    if(anima)
        glutTimerFunc(5, TimerFunc, f);
    glutPostRedisplay();
}

void Desenha(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer
    
    
    glColor3f(1.0,1.0,1.0);
    
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    float posicao[]={0.0, 50.0, -300.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, posicao);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
    Msg("Enduro", -.9,.9);
    InitScreen();
    // Pista
    glPushMatrix();
        DesenhaPista();
    glPopMatrix();

    // Player
    glPushMatrix();
        glTranslatef(carPosX, 0,  -180);
        glTranslatef(0,0,-5);
        glRotatef(viraCarro - Pontos.ponto[pos].curve * 2000, 0, 1, 0);
        glRotatef(-0.5*viraCarro + Pontos.ponto[pos].curve * 2000, 0, 0, 1);
        glTranslatef(0,0, 5);
        glScalef(s_car, s_car, s_car);
        DesenhaCarro(vermelho);
    glPopMatrix();

    for(int i = 0; i < tamPista; i+=991){
        glPushMatrix();
            if(contador == 0){
                contador++;
                dxBot = 0;
                DesenhaBots(corBot[contador], i, dxBot);
            }else if(contador == 1){
                contador++;
                dxBot = 35;
                DesenhaBots(corBot[contador], i, dxBot);
            }else if(contador == 2){
                contador++;
                dxBot = 0;
                DesenhaBots(corBot[contador], i, dxBot);
            }else if(contador == 3){
                contador = 0;
                dxBot = -35;
                DesenhaBots(corBot[contador], i, dxBot);
            }
        glPopMatrix();
    }
    //  DesenhaBots(amarelo, 0, 0);

    // Verifica Teclas:
    if(!colidiu){
        if(botoes[0] && anima){
            pos += (0.12 * speed);
            posBot += 0.01 * speed;
        }
        if((botoes[1] ) && anima){
            pos -= (0.12 * speed);
            posBot += 0.15 * speed;
            speed -= 0.02;
        }
        if(botoes[2] && !isTouchingLeft()){ // impedir virar pra esquerda quando estiver fora da pista
            carPosX = carPosX >= -(larPista/2+30)? carPosX - 1.5 * speed/(15+(volta*2)): carPosX;
            if(viraCarro < 0)
                viraCarro = viraCarro > 25 ? viraCarro : viraCarro + 1.5;
            viraCarro = viraCarro > 25 ? viraCarro : viraCarro + 0.8;
            if(anima) speed = speed > 1 ? speed + abs(carPosX) * 0.0001 * speed/(15+(volta*2)) : 1;
        }
        if(botoes[3] && !isTouchingRight()){ // impedir virar pra direita quando estiver fora da pista
            carPosX = carPosX <= larPista/2+30? carPosX + 1.5 * speed/(15+(volta*2)): carPosX;
            if(viraCarro > 0)
                viraCarro = viraCarro < -25 ? viraCarro : viraCarro - 1.5;
            viraCarro = viraCarro < -25 ? viraCarro : viraCarro - 0.8;
            if(anima) speed = speed > 1 ? speed + abs(carPosX) * 0.0001 * speed/(15+(volta*2)): 1;
        }
        
        if(!botoes[2] && !botoes[3]){
            if(viraCarro > 0){
                viraCarro = viraCarro * 0.92;
            }else if (viraCarro < 0){
                viraCarro = viraCarro * 0.92;
            }
        }
    }
    while(pos >= tamPista)    pos -= tamPista;
    while(pos < 0)           pos += tamPista;
    while(posBot >= tamPista) posBot -= tamPista;
    while(posBot < 0)        posBot += tamPista;

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
    GLint c = 0;
    GLboolean flagCor = false;
    x = 0; dx = 0;
    initArray(&Pontos, tamPista+2);
    for(int i = 0; i < tamPista; i++){
        Ponto_t ponto;
        ponto.x = 0;
        ponto.y = 0;
        ponto.z = -i ;
        ponto.curve = 0;

        //Cor
        if (c == 50){
            c = 0;
            flagCor = flagCor? false : true;
        }else c++;
        ponto.cor =   flagCor;

        // Curvas
        if( i > 1800 && i < 2800) ponto.curve = 0.001;
        if( i > 3800 && i < 4800) ponto.curve = -0.001;
        if( i > 5800 && i < 8800) ponto.curve = 0.001;
        if( i > 12800 && i < 14800) ponto.curve = -0.001;
        if( i > 10000 && i < 12000) ponto.curve = 0.001;
        if( i > 15000 && i < 17000) ponto.curve = -0.001;

        insertArray(&Pontos, ponto);
    }

    glutCreateWindow("CG TRAB-FINAL - ENDURO");FitWindow(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
        glutReshapeFunc(Reshape);
        glutPassiveMotionFunc(MovimentaMouse);
        glutMouseFunc(MouseFunc);
        glutKeyboardFunc(Keyboard);
        glutKeyboardUpFunc(UpKeyboard);
        glutSpecialFunc(SpecialKeys);
        glutTimerFunc(0,TimerFunc,1);
        glutIdleFunc(IdleFunc);
        glutDisplayFunc(Titulo1);
        //glutDisplayFunc(Desenha);
        glClearColor(.0f, .0f, .0f, .0f); //define a cor de fundo
        glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade
        InitScreen();
    glutMainLoop();
}
