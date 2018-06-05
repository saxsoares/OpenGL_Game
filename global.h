#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#define PI M_PI

typedef struct {
    GLfloat x, y, z ;
    GLfloat curve;
}Line_t, *Line ;

typedef struct {
  Line_t *array;
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
GLint  pistaLenght;
extern GLfloat fps;
extern GLfloat carPosX, carPosY, carPosZ;

extern GLint numSeg;
extern GLfloat angX, angY, angZ;
extern GLdouble theta, aspect, d_near, d_far;
extern GLdouble x_0,    y_0,    z_0,
         x_ref,  y_ref,  z_ref,
         V_x,    V_y,   V_z,
         xCam,   yCam,   zCam;
extern GLfloat playerX;

GLint startPos, pos;

int main(int, char**);
void initArray(Array *a, size_t initialSize);
void insertArray(Array *a, Line_t element);
void freeArray(Array *a);
void Msg(char *string, GLfloat x, GLfloat y);
void FitWindow(GLsizei w, GLsizei h);
void InitScreen();
void MovimentaMouse(int, int);
void MouseFunc(int, int, int, int);
void Keyboard(unsigned char, int, int);
void SpecialKeys(int, int, int);
void Timer(int);
void TimerFunc(int );
void Reshape(int, int);
void Msg(char *, GLfloat , GLfloat );
void Desenha();
void DesenhaGrade();
void DesenhaCarro();
void DesenhaEstrada();
void DesenhaSeg(GLfloat *cor, float x1, float y1, float w1, float x2, float y2, float w2, float y);
void IdleFunc();

#endif