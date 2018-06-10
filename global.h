#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

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

extern GLboolean anima;
extern GLint volta;
//Camera
extern GLdouble theta, aspect, d_near, d_far;
extern GLdouble x_0,    y_0,    z_0,
                x_ref,  y_ref,  z_ref,
                V_x,    V_y,   V_z,
                xCam,   yCam,   zCam;

// Pista
Array Pontos;
GLfloat x, dx;
extern GLint tamPista, larPista;

// Teclas
extern GLboolean botoes[];

// Player
GLint pos;
extern GLfloat s_car, carPosX, viraCarro, speed;

// Bot
extern GLfloat *corBot[];
extern GLint posBot;

int main(int, char**);
void initArray(Array *a, size_t initialSize);
void insertArray(Array *a, Ponto_t element);
void freeArray(Array *a);
void Msg(char *string, GLfloat x, GLfloat y);
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
void Desenha();
void DesenhaGrade();
void DesenhaCarro(GLfloat *);
void DesenhaBots(GLfloat *);
void DesenhaPista();

void DesenhaSeg(GLfloat *cor, float x1, float z1, float y1, float x2, float z2, float y2, float w2);
void IdleFunc();

#endif