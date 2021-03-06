#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <time.h>

#define PI M_PI
#define false GL_FALSE
#define true GL_TRUE

typedef struct {
    GLfloat x, y, z;
    GLboolean cor ;
    GLfloat dx;
    GLboolean bot;
    GLfloat curve;
}Ponto_t, *Ponto ;

typedef struct {
  Ponto_t *ponto;
  size_t used;
  size_t size;
} Array;

extern GLfloat  
    preto[],   branco[],   verde[],   verdeGrama[], verdeEsc[], azul[],     azulEsc[],    azulCeu[],
    amarelo[], furchsia[], rosa[],    rosaBri[],    abobora[],  ciano[],    marinho[],    fuligem[],
    roxo[],    jambo[],    laranja[], marrom[],     cinza[],    cinzaEsc[], cinzaFosco[], vermelho[], 
    cinzaClaro[], roadColorA[], roadColorB[], grassColorA[], grassColorB[], rundleColorA[], rundleColorB[];

GLint sw, sh, winPosX, winPosY;
GLfloat w_width, w_height;
GLfloat mouseX, mouseY, mouseClickX, mouseClickY;


//Camera
extern GLdouble theta, aspect, d_near, d_far;
extern GLdouble x_0,    y_0,    z_0,
                x_ref,  y_ref,  z_ref,
                V_x,    V_y,   V_z,
                xCam,   yCam,   zCam;
// Game
extern GLboolean anima, colidiu;
extern GLint volta, contaCor, voltaAnt;
GLint posQndoBateu, voltaAnt2,contaCor2, vetorEstrelasY[200], vetorEstrelasX[200];
GLfloat ambiente[5], posicao[4];
extern GLfloat pontuacao, posCeu, R, G, B;
extern GLchar pontuacaoStr[12];

// Pista
Array Pontos;
GLfloat x, dx;
extern GLint tamPista, larPista;

// Teclas
extern GLboolean botoes[];

// Player
extern GLfloat s_car;
extern GLint pos;
extern GLfloat s_car, carPosX, viraCarro, speed;

// Bot
extern GLfloat *corBot[], speed;
extern GLint posBot;
GLfloat rotBot;
GLint contador, dxBot;

int main(int, char**);
int isTouchingLeft();
int isTouchingRight();
void initArray(Array *a, size_t initialSize);
void insertArray(Array *a, Ponto_t element);
void freeArray(Array *a);
void Msg(char *string, GLfloat x, GLfloat y);
void MsgGde(char *string, GLfloat x, GLfloat y, GLfloat *cor);
void delay(float secs);
void FitWindow(GLsizei w, GLsizei h);
void InitScreen();
void MovimentaMouse(int, int);
void MouseFunc(int, int, int, int);
void Keyboard(unsigned char, int, int);
void UpKeyboard(unsigned char, int, int);
void SpecialKeys(int, int, int);
void Timer(int);
void TimerFunc(int );
void Reshape(int, int); 
void Msg(char *, GLfloat , GLfloat );
void Msg2(char *string, GLfloat x, GLfloat y, GLfloat *cor);
void Titulo1();
void Titulo2();
void Titulo3();
void Desenha();
void DesenhaGrade();
void DesenhaCarro(GLfloat *);
void DesenhaBots(GLfloat *, GLint, GLint);
void DesenhaPista();
void Desecelera();
void DesenhaSeg(GLfloat *cor, float x1, float z1, float y1, float x2, float z2, float y2, float w2);
void IdleFunc();
void desenha_actvision();
#endif
