#include "global.h"

void DesenhaCarro(GLfloat *cor){
    glPushMatrix();
        //Roda dianteira esquerda
        glPushMatrix();
        glTranslatef(-7.0,0.0,-33.0);    
        glRotatef(viraCarro - Pontos.ponto[pos].curve * 2000, 0, 1, 0);//Roda dianteira direita
        glTranslatef(7.0,0.0,33.0);    
        glColor3f(0.05, 0.05, 0.05);
        glBegin(GL_QUADS);
            glVertex3f(-8.5, 0.0, -31.8); glVertex3f(-5.5, 0.0, -31.8);
            glVertex3f(-5.5, 0.0, -34.2); glVertex3f(-8.5, 0.0, -34.2);

            glVertex3f(-8.5, 0.0, -34.2); glVertex3f(-5.5, 0.0, -34.2);
            glVertex3f(-5.5, 2.1, -35.9); glVertex3f(-8.5, 2.1, -35.9);

            glVertex3f(-8.5, 2.1, -35.9); glVertex3f(-5.5, 2.1, -35.9);
            glVertex3f(-5.5, 5.0, -35.9); glVertex3f(-8.5, 5.0, -35.9);

            glVertex3f(-8.5, 5.0, -35.9); glVertex3f(-5.5, 5.0, -35.9);
            glVertex3f(-5.5, 7.1, -34.2); glVertex3f(-8.5, 7.1, -34.2);

            glVertex3f(-8.5, 7.1, -34.2); glVertex3f(-5.5, 7.1, -34.2);
            glVertex3f(-5.5, 7.1, -31.8); glVertex3f(-8.5, 7.1, -31.8);

            glVertex3f(-8.5, 7.1, -31.8); glVertex3f(-5.5, 7.1, -31.8);
            glVertex3f(-5.5, 5.0, -30.1); glVertex3f(-8.5, 5.0, -30.1);

            glVertex3f(-8.5, 5.0, -30.1); glVertex3f(-5.5, 5.0, -30.1);
            glVertex3f(-5.5, 2.1, -30.1); glVertex3f(-8.5, 2.1, -30.1);

            glVertex3f(-8.5, 2.1, -30.1); glVertex3f(-5.5, 2.1, -30.1);
            glVertex3f(-5.5, 0.0, -31.8); glVertex3f(-8.5, 0.0, -31.8);
        glEnd();
        
            //"Tampa" esquerda
            glBegin(GL_POLYGON);
                glVertex3f(-8.5, 0.0, -31.8); glVertex3f(-8.5, 0.0, -34.2);
                glVertex3f(-8.5, 2.1, -35.9); glVertex3f(-8.5, 5.0, -35.9);
                glVertex3f(-8.5, 7.1, -34.2); glVertex3f(-8.5, 7.1, -31.8);
                glVertex3f(-8.5, 5.0, -30.1); glVertex3f(-8.5, 2.1, -30.1);
            glEnd();
        glPopMatrix();
        //Roda dianteira direita
        glColor3f(0.05, 0.05, 0.05);
        glPushMatrix();
        glTranslatef(7.0,0.0,-33.0);    
        glRotatef(viraCarro - Pontos.ponto[pos].curve * 2000, 0, 1, 0);//Roda dianteira direita
        glTranslatef(-7.0,0.0,33.0);    
        glBegin(GL_QUADS);
            glVertex3f(5.5, 0.0, -31.8); glVertex3f(8.5, 0.0, -31.8);
            glVertex3f(8.5, 0.0, -34.2); glVertex3f(5.5, 0.0, -34.2);

            glVertex3f(5.5, 0.0, -34.2); glVertex3f(8.5, 0.0, -34.2);
            glVertex3f(8.5, 2.1, -35.9); glVertex3f(5.5, 2.1, -35.9);

            glVertex3f(5.5, 2.1, -35.9); glVertex3f(8.5, 2.1, -35.9);
            glVertex3f(8.5, 5.0, -35.9); glVertex3f(5.5, 5.0, -35.9);

            glVertex3f(5.5, 5.0, -35.9); glVertex3f(8.5, 5.0, -35.9);
            glVertex3f(8.5, 7.1, -34.2); glVertex3f(5.5, 7.1, -34.2);

            glVertex3f(5.5, 7.1, -34.2); glVertex3f(8.5, 7.1, -34.2);
            glVertex3f(8.5, 7.1, -31.8); glVertex3f(5.5, 7.1, -31.8);

            glVertex3f(5.5, 7.1, -31.8); glVertex3f(8.5, 7.1, -31.8);
            glVertex3f(8.5, 5.0, -30.1); glVertex3f(5.5, 5.0, -30.1);

            glVertex3f(5.5, 5.0, -30.1); glVertex3f(8.5, 5.0, -30.1);
            glVertex3f(8.5, 2.1, -30.1); glVertex3f(5.5, 2.1, -30.1);

            glVertex3f(5.5, 2.1, -30.1); glVertex3f(8.5, 2.1, -30.1);
            glVertex3f(8.5, 0.0, -31.8); glVertex3f(5.5, 0.0, -31.8);
        glEnd();
            //"Tampa" direita
            glBegin(GL_POLYGON);
                glVertex3f(8.5, 0.0, -31.8); glVertex3f(8.5, 0.0, -34.2);
                glVertex3f(8.5, 2.1, -35.9); glVertex3f(8.5, 5.0, -35.9);
                glVertex3f(8.5, 7.1, -34.2); glVertex3f(8.5, 7.1, -31.8);
                glVertex3f(8.5, 5.0, -30.1); glVertex3f(8.5, 2.1, -30.1);
            glEnd();
        glPopMatrix();
        //Roda traseira esquerda
        glColor3f(0.05, 0.05, 0.05);
        glBegin(GL_QUADS);
            glVertex3f(-9.0, 0.0, -5.5);  glVertex3f(-6.0, 0.0, -5.5);
            glVertex3f(-6.0, 0.0, -8.5);   glVertex3f(-9.0, 0.0, -8.5);

            glVertex3f(-9.0, 0.0, -8.5);  glVertex3f(-6.0, 0.0, -8.5);
            glVertex3f(-6.0, 2.1, -10.5);  glVertex3f(-9.0, 2.1, -10.5);

            glVertex3f(-9.0, 2.1, -10.5); glVertex3f(-6.0, 2.1, -10.5);
            glVertex3f(-6.0, 5.0, -10.5);  glVertex3f(-9.0, 5.0, -10.5);

            glVertex3f(-9.0, 5.0, -10.5); glVertex3f(-6.0, 5.0, -10.5);
            glVertex3f(-6.0, 7.1, -8.5);   glVertex3f(-9.0, 7.1, -8.5);

            glVertex3f(-9.0, 7.1, -8.5);  glVertex3f(-6.0, 7.1, -8.5);
            glVertex3f(-6.0, 7.1, -5.5);   glVertex3f(-9.0, 7.1, -5.5);

            glVertex3f(-9.0, 7.1, -5.5);  glVertex3f(-6.0, 7.1, -5.5);
            glVertex3f(-6.0, 5.0, -3.5);   glVertex3f(-9.0, 5.0, -3.5);

            glVertex3f(-9.0, 5.0, -3.5);  glVertex3f(-6.0, 5.0, -3.5);
            glVertex3f(-6.0, 2.1, -3.5);   glVertex3f(-9.0, 2.1, -3.5);

            glVertex3f(-9.0, 2.1, -3.5);  glVertex3f(-6.0, 2.1, -3.5);
            glVertex3f(-6.0, 0.0, -5.5);   glVertex3f(-9.0, 0.0, -5.5);
        glEnd();
            //"Tampa" esquerda
            glBegin(GL_POLYGON);
                glVertex3f(-9.0, 0.0, -5.5);  glVertex3f(-9.0, 0.0, -8.5);
                glVertex3f(-9.0, 2.1, -10.5); glVertex3f(-9.0, 5.0, -10.5);
                glVertex3f(-9.0, 7.1, -8.5);  glVertex3f(-9.0, 7.1, -5.5);
                glVertex3f(-9.0, 5.0, -3.5);  glVertex3f(-9.0, 2.1, -3.5);
            glEnd();

        //Roda traseira direita
        glBegin(GL_QUADS);
            glVertex3f(6.0, 0.0, -5.5);   glVertex3f(9.0, 0.0, -5.5);
            glVertex3f(9.0, 0.0, -8.5);  glVertex3f(6.0, 0.0, -8.5);

            glVertex3f(6.0, 0.0, -8.5);   glVertex3f(9.0, 0.0, -8.5);
            glVertex3f(9.0, 2.1, -10.5); glVertex3f(6.0, 2.1, -10.5);

            glVertex3f(6.0, 2.1, -10.5);  glVertex3f(9.0, 2.1, -10.5);
            glVertex3f(9.0, 5.0, -10.5); glVertex3f(6.0, 5.0, -10.5);

            glVertex3f(6.0, 5.0, -10.5);  glVertex3f(9.0, 5.0, -10.5);
            glVertex3f(9.0, 7.1, -8.5);  glVertex3f(6.0, 7.1, -8.5);

            glVertex3f(6.0, 7.1, -8.5);   glVertex3f(9.0, 7.1, -8.5);
            glVertex3f(9.0, 7.1, -5.5);  glVertex3f(6.0, 7.1, -5.5);

            glVertex3f(6.0, 7.1, -5.5);   glVertex3f(9.0, 7.1, -5.5);
            glVertex3f(9.0, 5.0, -3.5);  glVertex3f(6.0, 5.0, -3.5);

            glVertex3f(6.0, 5.0, -3.5);   glVertex3f(9.0, 5.0, -3.5);
            glVertex3f(9.0, 2.1, -3.5);  glVertex3f(6.0, 2.1, -3.5);

            glVertex3f(6.0, 2.1, -3.5);   glVertex3f(9.0, 2.1, -3.5);
            glVertex3f(9.0, 0.0, -5.5);  glVertex3f(6.0, 0.0, -5.5);
        glEnd();
            //"Tampa" direita
            glBegin(GL_POLYGON);
                glVertex3f(9.0, 0.0, -5.5);  glVertex3f(9.0, 0.0, -8.5);
                glVertex3f(9.0, 2.1, -10.5); glVertex3f(9.0, 5.0, -10.5);
                glVertex3f(9.0, 7.1, -8.5);  glVertex3f(9.0, 7.1, -5.5);
                glVertex3f(9.0, 5.0, -3.5);  glVertex3f(9.0, 2.1, -3.5);
            glEnd();

        //Laterais
        glColor3fv(cor);
        glBegin(GL_TRIANGLES);
            //Esquerda
            glNormal3f(-1.0, 0.0, 0.0);
            glVertex3f(-8.5, 5.4, 0.0);   glVertex3f(-8.5, 5.4, -2.5);   glVertex3f(-8.5, 11.6, 0.0);//01
            glVertex3f(-8.5, 5.4, -2.5);  glVertex3f(-8.5, 8.1, -5.1);   glVertex3f(-8.5, 11.6, 0.0);//02
            glVertex3f(-8.5, 8.1, -5.1);  glVertex3f(-8.5, 16.2, -10.0); glVertex3f(-8.5, 11.6, 0.0);//03
            glVertex3f(-8.5, 8.1, -5.1);  glVertex3f(-8.5, 8.1, -8.9);   glVertex3f(-8.5, 16.2, -10.0);//04
            glVertex3f(-8.5, 8.1, -8.9);  glVertex3f(-8.5, 16.2, -20.0); glVertex3f(-8.5, 16.2, -10.0);//05
            glVertex3f(-8.5, 8.1, -8.9);  glVertex3f(-8.5, 11.8, -26.7);  glVertex3f(-8.5, 16.2, -20.0);//06
            glVertex3f(-8.5, 8.1, -8.9);  glVertex3f(-8.5, 5.4, -11.5);  glVertex3f(-8.5, 11.8, -26.7);//07
            glVertex3f(-8.5, 5.4, -11.5); glVertex3f(-8.5, 8.1, -31.5);  glVertex3f(-8.5, 11.8, -26.7);//08
            glVertex3f(-8.5, 5.4, -11.5); glVertex3f(-8.5, 5.4, -29.3);  glVertex3f(-8.5, 8.1, -31.5);//09
            glVertex3f(-8.5, 5.4, -11.5); glVertex3f(-8.5, 2.9, -11.5);  glVertex3f(-8.5, 5.4, -29.3);//10
            glVertex3f(-8.5, 2.9, -11.5); glVertex3f(-8.5, 2.9, -29.3);  glVertex3f(-8.5, 5.4, -29.3);//11
            glVertex3f(-8.5, 8.1, -31.5); glVertex3f(-8.5, 8.1, -34.5);  glVertex3f(-8.5, 11.8, -26.7);//12
            glVertex3f(-8.5, 8.1, -34.5); glVertex3f(-8.5, 9.6, -40.0);  glVertex3f(-8.5, 11.8, -26.7);//13
            glVertex3f(-8.5, 8.1, -34.5); glVertex3f(-8.5, 5.4, -36.7);  glVertex3f(-8.5, 9.6, -40.0);//14
            glVertex3f(-8.5, 5.4, -36.7); glVertex3f(-8.5, 5.4, -40.0);  glVertex3f(-8.5, 9.6, -40.0);//15
            //Direita
            glNormal3f(1.0, 0.0, 0.0);
            glVertex3f(8.5, 5.4, 0.0);   glVertex3f(8.5, 5.4, -2.5);   glVertex3f(8.5, 11.6, 0.0);//01
            glVertex3f(8.5, 5.4, -2.5);  glVertex3f(8.5, 8.1, -5.1);   glVertex3f(8.5, 11.6, 0.0);//02
            glVertex3f(8.5, 8.1, -5.1);  glVertex3f(8.5, 16.2, -10.0); glVertex3f(8.5, 11.6, 0.0);//03
            glVertex3f(8.5, 8.1, -5.1);  glVertex3f(8.5, 8.1, -8.9);   glVertex3f(8.5, 16.2, -10.0);//04
            glVertex3f(8.5, 8.1, -8.9);  glVertex3f(8.5, 16.2, -20.0); glVertex3f(8.5, 16.2, -10.0);//05
            glVertex3f(8.5, 8.1, -8.9);  glVertex3f(8.5, 11.8, -26.7);  glVertex3f(8.5, 16.2, -20.0);//06
            glVertex3f(8.5, 8.1, -8.9);  glVertex3f(8.5, 5.4, -11.5);  glVertex3f(8.5, 11.8, -26.7);//07
            glVertex3f(8.5, 5.4, -11.5); glVertex3f(8.5, 8.1, -31.5);  glVertex3f(8.5, 11.8, -26.7);//08
            glVertex3f(8.5, 5.4, -11.5); glVertex3f(8.5, 5.4, -29.3);  glVertex3f(8.5, 8.1, -31.5);//09
            glVertex3f(8.5, 5.4, -11.5); glVertex3f(8.5, 2.9, -11.5);  glVertex3f(8.5, 5.4, -29.3);//10
            glVertex3f(8.5, 2.9, -11.5); glVertex3f(8.5, 2.9, -29.3);  glVertex3f(8.5, 5.4, -29.3);//11
            glVertex3f(8.5, 8.1, -31.5); glVertex3f(8.5, 8.1, -34.5);  glVertex3f(8.5, 11.8, -26.7);//12
            glVertex3f(8.5, 8.1, -34.5); glVertex3f(8.5, 9.6, -40.0);  glVertex3f(8.5, 11.8, -26.7);//13
            glVertex3f(8.5, 8.1, -34.5); glVertex3f(8.5, 5.4, -36.7);  glVertex3f(8.5, 9.6, -40.0);//14
            glVertex3f(8.5, 5.4, -36.7); glVertex3f(8.5, 5.4, -40.0);  glVertex3f(8.5, 9.6, -40.0);//15
        glEnd();

        //Carroceria
        glBegin(GL_QUADS);
            //Parachoque traseiro
            glColor3f(0.0, 0.0, 0.0);
            glNormal3f(0.0, 0.0, 1.0);
            glVertex3f(-8.5, 5.4, 0.0); glVertex3f(8.5, 5.4, 0.0);
            glVertex3f(8.5, 2.9, 0.0);  glVertex3f(-8.5, 2.9, 0.0);

            glVertex3f(-8.5, 2.9, 0.0); glVertex3f(8.5, 2.9, 0.0);
            glVertex3f(8.5, 2.9, -2.5); glVertex3f(-8.5, 2.9, -2.5);

            glVertex3f(-8.5, 2.9, -2.5);  glVertex3f(8.5, 2.9, -2.5);
            glVertex3f(8.5, 5.4, -2.5);   glVertex3f(-8.5, 5.4, -2.5);
                //Tampa esquerda
                glNormal3f(-1.0, 0.0, 0.0);
                glVertex3f(-8.5, 2.9, 0.0);  glVertex3f(-8.5, 2.9, -2.5);
                glVertex3f(-8.5, 5.4, -2.5); glVertex3f(-8.5, 5.4, 0.0);
                //Tampa direita
                glNormal3f(1.0, 0.0, 0.0);
                glVertex3f(8.5, 2.9, 0.0);  glVertex3f(8.5, 2.9, -2.5);
                glVertex3f(8.5, 5.4, -2.5); glVertex3f(8.5, 5.4, 0.0);

            //Cavidade traseira
            glColor3fv(cor);
            glVertex3f(-8.5, 5.4, -2.5);  glVertex3f(8.5, 5.4, -2.5);
            glVertex3f(8.5, 8.1, -5.1);   glVertex3f(-8.5, 8.1, -5.1);

            glVertex3f(-8.5, 8.1, -5.1);  glVertex3f(8.5, 8.1, -5.1);
            glVertex3f(8.5, 8.1, -8.9);   glVertex3f(-8.5, 8.1, -8.9);

            glVertex3f(-8.5, 8.1, -8.9);  glVertex3f(8.5, 8.1, -8.9);
            glVertex3f(8.5, 8.1, -11.5);  glVertex3f(-8.5, 8.1, -11.5);

            glVertex3f(-8.5, 8.1, -11.5); glVertex3f(8.5, 8.1, -11.5);
            glVertex3f(8.5, 2.9, -11.5);  glVertex3f(-8.5, 2.9, -11.5);

            //Base
            glVertex3f(-8.5, 2.9, -11.5); glVertex3f(8.5, 2.9, -11.5);
            glVertex3f(8.5, 2.9, -29.3);  glVertex3f(-8.5, 2.9, -29.3);

            //Cavidade dianteira
            glVertex3f(-8.5, 2.9, -29.3); glVertex3f(8.5, 2.9, -29.3);
            glVertex3f(8.5, 5.4, -29.3);  glVertex3f(-8.5, 5.4, -29.3);

            glVertex3f(-8.5, 5.4, -29.3); glVertex3f(8.5, 5.4, -29.3);
            glVertex3f(8.5, 8.1, -31.5);  glVertex3f(-8.5, 8.1, -31.5);

            glVertex3f(-8.5, 8.1, -31.5); glVertex3f(8.5, 8.1, -31.5);
            glVertex3f(8.5, 8.1, -34.5);  glVertex3f(-8.5, 8.1, -34.5);

            glVertex3f(-8.5, 8.1, -34.5); glVertex3f(8.5, 8.1, -34.5);
            glVertex3f(8.5, 5.4, -36.7);  glVertex3f(-8.5, 5.4, -36.7);

            //Parachoque dianteiro
            glColor3f(0.0, 0.0, 0.0);
            glNormal3f(0.0, 0.0, -1.0);
            glVertex3f(-8.5, 4.5, -36.7); glVertex3f(8.5, 4.5, -36.7);
            glVertex3f(8.5, 2.9, -36.7);  glVertex3f(-8.5, 2.9, -36.7);

            glVertex3f(-8.5, 2.9, -36.7); glVertex3f(8.5, 2.9, -36.7);
            glVertex3f(8.5, 2.9, -40.0);  glVertex3f(-8.5, 2.9, -40.0);

            glVertex3f(-8.5, 2.9, -40.0); glVertex3f(8.5, 2.9, -40.0);
            glVertex3f(8.5, 4.5, -40.0);  glVertex3f(-8.5, 4.5, -40.0);
                //Tampa esquerda
                glNormal3f(-1.0, 0.0, 0.0);
                glVertex3f(-8.5, 2.9, -36.7); glVertex3f(-8.5, 2.9, -40.0);
                glVertex3f(-8.5, 4.5, -40.0); glVertex3f(-8.5, 4.5, -36.7);
                //Tampa direita
                glNormal3f(1.0, 0.0, 0.0);
                glVertex3f(8.5, 2.9, -36.7); glVertex3f(8.5, 2.9, -40.0);
                glVertex3f(8.5, 4.5, -40.0); glVertex3f(8.5, 4.5, -36.7);

            //Dianteira
            glColor3fv(cor);
            glNormal3f(0.0, 0.0, -1.0);
            glVertex3f(-8.5, 4.5, -40.0);  glVertex3f(8.5, 4.5, -40.0);
            glVertex3f(8.5, 9.6, -40.0);   glVertex3f(-8.5, 9.6, -40.0);

            //Capo
            glNormal3f(0.0, 1.0, 0.0);
            glVertex3f(-8.5, 9.6, -40.0);  glVertex3f(8.5, 9.6, -40.0);
            glVertex3f(8.5, 11.8, -26.7);   glVertex3f(-8.5, 11.8, -26.7);

            //Parabrisa
            glVertex3f(-8.5, 11.8, -26.7);  glVertex3f(8.5, 11.8, -26.7);
            glVertex3f(8.5, 16.2, -20.0);  glVertex3f(-8.5, 16.2, -20.0);

            //Teto
            glVertex3f(-8.5, 16.2, -20.0); glVertex3f(8.5, 16.2, -20.0);
            glVertex3f(8.5, 16.2, -10.0);  glVertex3f(-8.5, 16.2, -10.0);

            //Traseira
            glNormal3f(0.0, 0.0, 1.0);
            glVertex3f(-8.5, 16.2, -10.0); glVertex3f(8.5, 16.2, -10.0);
            glVertex3f(8.5, 11.6, 0.0);   glVertex3f(-8.5, 11.6, 0.0);

            glVertex3f(-8.5, 11.6, 0.0);  glVertex3f(8.5, 11.6, 0.0);
            glVertex3f(8.5, 5.4, 0.0);    glVertex3f(-8.5, 5.4, 0.0);
        glEnd();

        //Vidros
        glColor3f(0.2, 0.2, 0.2);
            glBegin(GL_QUADS);
                //Traseiro
                glNormal3f(0.0, 0.0, 1.0);
                glVertex3f(-7.5, 12.45, -1.8); glVertex3f(7.5, 12.45, -1.8);
                glVertex3f(7.5, 15.8, -9.1);   glVertex3f(-7.5, 15.8, -9.1);
            glEnd();
            glBegin(GL_QUADS);
                //Dianteiro
                glNormal3f(0.0, 0.0, -1.0);
                glVertex3f(-7.5, 12.7, -25.4); glVertex3f(7.5, 12.7, -25.4);
                glVertex3f(7.5, 15.7, -20.8);   glVertex3f(-7.5, 15.7, -20.8);
            glEnd();

            glBegin(GL_POLYGON);
                //Vidros esquerdo
                glNormal3f(-1.0, 0.0, 0.0);
                glVertex3f(-8.51, 11.2, -1.6);  glVertex3f(-8.51, 11.2, -25.7);
                glVertex3f(-8.51, 15.2, -19.7); glVertex3f(-8.51, 15.2, -10.2);
            glEnd();
            glBegin(GL_POLYGON);
                //Vidros direito
                glNormal3f(1.0, 0.0, 0.0);
                glVertex3f(8.51, 11.2, -1.6);  glVertex3f(8.51, 11.2, -25.7);
                glVertex3f(8.51, 15.2, -19.7); glVertex3f(8.51, 15.2, -10.2);
            glEnd();

        //Portas
        glColor3f(0.0, 0.0, 0.0);
            //Esquerda
            glNormal3f(-1.0, 0.0, 0.0);
            glBegin(GL_LINES);
                glVertex3f(-8.51, 4.4, -13.0); glVertex3f(-8.51, 15.2, -13.0);
                glVertex3f(-8.51, 4.4, -13.0); glVertex3f(-8.51, 4.4, -25.7);
                glVertex3f(-8.51, 4.4, -25.7); glVertex3f(-8.51, 11.2, -25.7);
            glEnd();
            //Direita
            glNormal3f(1.0, 0.0, 0.0);
            glBegin(GL_LINES);
                glVertex3f(8.51, 4.4, -13.0); glVertex3f(8.51, 15.2, -13.0);
                glVertex3f(8.51, 4.4, -13.0); glVertex3f(8.51, 4.4, -25.7);
                glVertex3f(8.51, 4.4, -25.7); glVertex3f(8.51, 11.2, -25.7);
            glEnd();

        //Lanternas
        glColor3f(0.8, 0.0, 0.0);
            //Traseira esquerda
            glNormal3f(0.0, 0.0, 1.0);
            glBegin(GL_QUADS);
                glVertex3f(-6.5, 9.1, 0.1);  glVertex3f(-4.5, 9.1, 0.1);
                glVertex3f(-4.5, 10.6, 0.1); glVertex3f(-6.5, 10.6, 0.1);
            glEnd();

            //Traseira direita
            glNormal3f(0.0, 0.0, 1.0);
            glBegin(GL_QUADS);
                glVertex3f(6.5, 9.1, 0.1);  glVertex3f(4.5, 9.1, 0.1);
                glVertex3f(4.5, 10.6, 0.1); glVertex3f(6.5, 10.6, 0.1);
            glEnd();

        glColor3f(0.9, 0.9, 0.0);
            //Seta esquerda
            glNormal3f(0.0, 0.0, 1.0);
            glBegin(GL_QUADS);
                glVertex3f(-7.5, 9.1, 0.1);  glVertex3f(-6.5, 9.1, 0.1);
                glVertex3f(-6.5, 10.6, 0.1); glVertex3f(-7.5, 10.6, 0.1);
            glEnd();

            //Seta direita
            glNormal3f(0.0, 0.0, 1.0);
            glBegin(GL_QUADS);
                glVertex3f(6.5, 9.1, 0.1);  glVertex3f(7.5, 9.1, 0.1);
                glVertex3f(7.5, 10.6, 0.1); glVertex3f(6.5, 10.6, 0.1);
            glEnd();

        //Escapamentos
        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_LINES);
            glVertex3f(5.3, 3.9, 0.1); glVertex3f(5.7, 3.9, 0.1);
            glVertex3f(5.7, 3.9, 0.1); glVertex3f(6.0, 4.2, 0.1);
            glVertex3f(6.0, 4.2, 0.1); glVertex3f(6.0, 4.6, 0.1);
            glVertex3f(6.0, 4.6, 0.1); glVertex3f(5.7, 4.9, 0.1);
            glVertex3f(5.7, 4.9, 0.1); glVertex3f(5.3, 4.9, 0.1);
            glVertex3f(5.3, 4.9, 0.1); glVertex3f(5.1, 4.6, 0.1);
            glVertex3f(5.1, 4.6, 0.1); glVertex3f(5.1, 4.2, 0.1);
            glVertex3f(5.1, 4.2, 0.1); glVertex3f(5.3, 3.9, 0.1);
        glEnd();
        glBegin(GL_LINES);
            glVertex3f(6.3, 3.9, 0.1); glVertex3f(6.7, 3.9, 0.1);
            glVertex3f(6.7, 3.9, 0.1); glVertex3f(7.0, 4.2, 0.1);
            glVertex3f(7.0, 4.2, 0.1); glVertex3f(7.0, 4.6, 0.1);
            glVertex3f(7.0, 4.6, 0.1); glVertex3f(6.7, 4.9, 0.1);
            glVertex3f(6.7, 4.9, 0.1); glVertex3f(6.3, 4.9, 0.1);
            glVertex3f(6.3, 4.9, 0.1); glVertex3f(6.1, 4.6, 0.1);
            glVertex3f(6.1, 4.6, 0.1); glVertex3f(6.1, 4.2, 0.1);
            glVertex3f(6.1, 4.2, 0.1); glVertex3f(6.3, 3.9, 0.1);
        glEnd();
    glPopMatrix();
    glNormal3f(0.0, 1.0, 0.0);
}