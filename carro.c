#include<GL/glut.h>

void DesenhaCarro(){
    glPushMatrix();
        //Roda dianteira esquerda
        glColor3f(0.1, 0.1, 0.1);
        glBegin(GL_QUADS);
            glVertex3f(-8.5, 0.0, -31.8); glVertex3f(-5.5, 0.0, -31.8);
            glVertex3f(-5.5, 0.0, -34.2); glVertex3f(-8.5, 0.0, -34.2);

            glVertex3f(-8.5, 0.0, -34.2); glVertex3f(-5.5, 0.0, -34.2);
            glVertex3f(-5.5, 1.7, -35.9); glVertex3f(-8.5, 1.7, -35.9);

            glVertex3f(-8.5, 1.7, -35.9); glVertex3f(-5.5, 1.7, -35.9);
            glVertex3f(-5.5, 4.2, -35.9); glVertex3f(-8.5, 4.2, -35.9);

            glVertex3f(-8.5, 4.2, -35.9); glVertex3f(-5.5, 4.2, -35.9);
            glVertex3f(-5.5, 5.9, -34.2); glVertex3f(-8.5, 5.9, -34.2);

            glVertex3f(-8.5, 5.9, -34.2); glVertex3f(-5.5, 5.9, -34.2);
            glVertex3f(-5.5, 5.9, -31.8); glVertex3f(-8.5, 5.9, -31.8);

            glVertex3f(-8.5, 5.9, -31.8); glVertex3f(-5.5, 5.9, -31.8);
            glVertex3f(-5.5, 4.2, -30.1); glVertex3f(-8.5, 4.2, -30.1);

            glVertex3f(-8.5, 4.2, -30.1); glVertex3f(-5.5, 4.2, -30.1);
            glVertex3f(-5.5, 1.7, -30.1); glVertex3f(-8.5, 1.7, -30.1);

            glVertex3f(-8.5, 1.7, -30.1); glVertex3f(-5.5, 1.7, -30.1);
            glVertex3f(-5.5, 0.0, -31.8); glVertex3f(-8.5, 0.0, -31.8);
        glEnd();
            //"Tampa" esquerda
            glBegin(GL_POLYGON);
                glVertex3f(-8.5, 0.0, -31.8); glVertex3f(-8.5, 0.0, -34.2);
                glVertex3f(-8.5, 1.7, -35.9); glVertex3f(-8.5, 4.2, -35.9);
                glVertex3f(-8.5, 5.9, -34.2); glVertex3f(-8.5, 5.9, -31.8);
                glVertex3f(-8.5, 4.2, -30.1); glVertex3f(-8.5, 1.7, -30.1);
            glEnd();

        //Roda dianteira direita
        glColor3f(0.1, 0.1, 0.1);
        glBegin(GL_QUADS);
            glVertex3f(5.5, 0.0, -31.8); glVertex3f(8.5, 0.0, -31.8);
            glVertex3f(8.5, 0.0, -34.2); glVertex3f(5.5, 0.0, -34.2);

            glVertex3f(5.5, 0.0, -34.2); glVertex3f(8.5, 0.0, -34.2);
            glVertex3f(8.5, 1.7, -35.9); glVertex3f(5.5, 1.7, -35.9);

            glVertex3f(5.5, 1.7, -35.9); glVertex3f(8.5, 1.7, -35.9);
            glVertex3f(8.5, 4.2, -35.9); glVertex3f(5.5, 4.2, -35.9);

            glVertex3f(5.5, 4.2, -35.9); glVertex3f(8.5, 4.2, -35.9);
            glVertex3f(8.5, 5.9, -34.2); glVertex3f(5.5, 5.9, -34.2);

            glVertex3f(5.5, 5.9, -34.2); glVertex3f(8.5, 5.9, -34.2);
            glVertex3f(8.5, 5.9, -31.8); glVertex3f(5.5, 5.9, -31.8);

            glVertex3f(5.5, 5.9, -31.8); glVertex3f(8.5, 5.9, -31.8);
            glVertex3f(8.5, 4.2, -30.1); glVertex3f(5.5, 4.2, -30.1);

            glVertex3f(5.5, 4.2, -30.1); glVertex3f(8.5, 4.2, -30.1);
            glVertex3f(8.5, 1.7, -30.1); glVertex3f(5.5, 1.7, -30.1);

            glVertex3f(5.5, 1.7, -30.1); glVertex3f(8.5, 1.7, -30.1);
            glVertex3f(8.5, 0.0, -31.8); glVertex3f(5.5, 0.0, -31.8);
        glEnd();
            //"Tampa" direita
            glBegin(GL_POLYGON);
                glVertex3f(8.5, 0.0, -31.8); glVertex3f(8.5, 0.0, -34.2);
                glVertex3f(8.5, 1.7, -35.9); glVertex3f(8.5, 4.2, -35.9);
                glVertex3f(8.5, 5.9, -34.2); glVertex3f(8.5, 5.9, -31.8);
                glVertex3f(8.5, 4.2, -30.1); glVertex3f(8.5, 1.7, -30.1);
            glEnd();

        //Roda traseira esquerda
        glColor3f(0.1, 0.1, 0.1);
        glBegin(GL_QUADS);
            glVertex3f(-10.0, 0.0, -5.5);  glVertex3f(-6.0, 0.0, -5.5);
            glVertex3f(-6.0, 0.0, -8.5);   glVertex3f(-10.0, 0.0, -8.5);

            glVertex3f(-10.0, 0.0, -8.5);  glVertex3f(-6.0, 0.0, -8.5);
            glVertex3f(-6.0, 2.1, -10.5);  glVertex3f(-10.0, 2.1, -10.5);

            glVertex3f(-10.0, 2.1, -10.5); glVertex3f(-6.0, 2.1, -10.5);
            glVertex3f(-6.0, 5.0, -10.5);  glVertex3f(-10.0, 5.0, -10.5);

            glVertex3f(-10.0, 5.0, -10.5); glVertex3f(-6.0, 5.0, -10.5);
            glVertex3f(-6.0, 7.1, -8.5);   glVertex3f(-10.0, 7.1, -8.5);

            glVertex3f(-10.0, 7.1, -8.5);  glVertex3f(-6.0, 7.1, -8.5);
            glVertex3f(-6.0, 7.1, -5.5);   glVertex3f(-10.0, 7.1, -5.5);

            glVertex3f(-10.0, 7.1, -5.5);  glVertex3f(-6.0, 7.1, -5.5);
            glVertex3f(-6.0, 5.0, -3.5);   glVertex3f(-10.0, 5.0, -3.5);

            glVertex3f(-10.0, 5.0, -3.5);  glVertex3f(-6.0, 5.0, -3.5);
            glVertex3f(-6.0, 2.1, -3.5);   glVertex3f(-10.0, 2.1, -3.5);

            glVertex3f(-10.0, 2.1, -3.5);  glVertex3f(-6.0, 2.1, -3.5);
            glVertex3f(-6.0, 0.0, -5.5);   glVertex3f(-10.0, 0.0, -5.5);
        glEnd();
            //"Tampa" esquerda
            glBegin(GL_POLYGON);
                glVertex3f(-10.0, 0.0, -5.5);  glVertex3f(-10.0, 0.0, -8.5);
                glVertex3f(-10.0, 2.1, -10.5); glVertex3f(-10.0, 5.0, -10.5);
                glVertex3f(-10.0, 7.1, -8.5);  glVertex3f(-10.0, 7.1, -5.5);
                glVertex3f(-10.0, 5.0, -3.5);  glVertex3f(-10.0, 2.1, -3.5);
            glEnd();

        //Roda traseira direita
        glBegin(GL_QUADS);
            glVertex3f(6.0, 0.0, -5.5);   glVertex3f(10.0, 0.0, -5.5);
            glVertex3f(10.0, 0.0, -8.5);  glVertex3f(6.0, 0.0, -8.5);

            glVertex3f(6.0, 0.0, -8.5);   glVertex3f(10.0, 0.0, -8.5);
            glVertex3f(10.0, 2.1, -10.5); glVertex3f(6.0, 2.1, -10.5);

            glVertex3f(6.0, 2.1, -10.5);  glVertex3f(10.0, 2.1, -10.5);
            glVertex3f(10.0, 5.0, -10.5); glVertex3f(6.0, 5.0, -10.5);

            glVertex3f(6.0, 5.0, -10.5);  glVertex3f(10.0, 5.0, -10.5);
            glVertex3f(10.0, 7.1, -8.5);  glVertex3f(6.0, 7.1, -8.5);

            glVertex3f(6.0, 7.1, -8.5);   glVertex3f(10.0, 7.1, -8.5);
            glVertex3f(10.0, 7.1, -5.5);  glVertex3f(6.0, 7.1, -5.5);

            glVertex3f(6.0, 7.1, -5.5);   glVertex3f(10.0, 7.1, -5.5);
            glVertex3f(10.0, 5.0, -3.5);  glVertex3f(6.0, 5.0, -3.5);

            glVertex3f(6.0, 5.0, -3.5);   glVertex3f(10.0, 5.0, -3.5);
            glVertex3f(10.0, 2.1, -3.5);  glVertex3f(6.0, 2.1, -3.5);

            glVertex3f(6.0, 2.1, -3.5);   glVertex3f(10.0, 2.1, -3.5);
            glVertex3f(10.0, 0.0, -5.5);  glVertex3f(6.0, 0.0, -5.5);
        glEnd();
            //"Tampa" direita
            glBegin(GL_POLYGON);
                glVertex3f(10.0, 0.0, -5.5);  glVertex3f(10.0, 0.0, -8.5);
                glVertex3f(10.0, 2.1, -10.5); glVertex3f(10.0, 5.0, -10.5);
                glVertex3f(10.0, 7.1, -8.5);  glVertex3f(10.0, 7.1, -5.5);
                glVertex3f(10.0, 5.0, -3.5);  glVertex3f(10.0, 2.1, -3.5);
            glEnd();

        //Laterais
        glColor3f(1.0, 0.0 , 0.0);
        glBegin(GL_TRIANGLES);
            //Esquerda
            glVertex3f(-8.5, 5.4, 0.0);   glVertex3f(-8.5, 5.4, -2.5);   glVertex3f(-8.5, 11.6, 0.0);//01
            glVertex3f(-8.5, 5.4, -2.5);  glVertex3f(-8.5, 8.1, -5.1);   glVertex3f(-8.5, 11.6, 0.0);//02
            glVertex3f(-8.5, 8.1, -5.1);  glVertex3f(-8.5, 16.2, -10.0); glVertex3f(-8.5, 11.6, 0.0);//03
            glVertex3f(-8.5, 8.1, -5.1);  glVertex3f(-8.5, 8.1, -8.9);   glVertex3f(-8.5, 16.2, -10.0);//04
            glVertex3f(-8.5, 8.1, -8.9);  glVertex3f(-8.5, 16.2, -20.0); glVertex3f(-8.5, 16.2, -10.0);//05
            glVertex3f(-8.5, 8.1, -8.9);  glVertex3f(-8.5, 11.8, -26.7);  glVertex3f(-8.5, 16.2, -20.0);//06
            glVertex3f(-8.5, 8.1, -8.9);  glVertex3f(-8.5, 5.4, -11.5);  glVertex3f(-8.5, 11.8, -26.7);//07
            glVertex3f(-8.5, 5.4, -11.5); glVertex3f(-8.5, 6.6, -31.5);  glVertex3f(-8.5, 11.8, -26.7);//08
            glVertex3f(-8.5, 5.4, -11.5); glVertex3f(-8.5, 4.5, -29.3);  glVertex3f(-8.5, 6.6, -31.5);//09
            glVertex3f(-8.5, 5.4, -11.5); glVertex3f(-8.5, 2.9, -11.5);  glVertex3f(-8.5, 4.5, -29.3);//10
            glVertex3f(-8.5, 2.9, -11.5); glVertex3f(-8.5, 2.9, -29.3);  glVertex3f(-8.5, 4.5, -29.3);//11
            glVertex3f(-8.5, 6.6, -31.5); glVertex3f(-8.5, 6.6, -34.5);  glVertex3f(-8.5, 11.8, -26.7);//12
            glVertex3f(-8.5, 6.6, -34.5); glVertex3f(-8.5, 9.6, -40.0);  glVertex3f(-8.5, 11.8, -26.7);//13
            glVertex3f(-8.5, 6.6, -34.5); glVertex3f(-8.5, 4.5, -36.7);  glVertex3f(-8.5, 9.6, -40.0);//14
            glVertex3f(-8.5, 4.5, -36.7); glVertex3f(-8.5, 4.5, -40.0);  glVertex3f(-8.5, 9.6, -40.0);//15
            //Direita
            glVertex3f(8.5, 5.4, 0.0);   glVertex3f(8.5, 5.4, -2.5);   glVertex3f(8.5, 11.6, 0.0);//01
            glVertex3f(8.5, 5.4, -2.5);  glVertex3f(8.5, 8.1, -5.1);   glVertex3f(8.5, 11.6, 0.0);//02
            glVertex3f(8.5, 8.1, -5.1);  glVertex3f(8.5, 16.2, -10.0); glVertex3f(8.5, 11.6, 0.0);//03
            glVertex3f(8.5, 8.1, -5.1);  glVertex3f(8.5, 8.1, -8.9);   glVertex3f(8.5, 16.2, -10.0);//04
            glVertex3f(8.5, 8.1, -8.9);  glVertex3f(8.5, 16.2, -20.0); glVertex3f(8.5, 16.2, -10.0);//05
            glVertex3f(8.5, 8.1, -8.9);  glVertex3f(8.5, 11.8, -26.7);  glVertex3f(8.5, 16.2, -20.0);//06
            glVertex3f(8.5, 8.1, -8.9);  glVertex3f(8.5, 5.4, -11.5);  glVertex3f(8.5, 11.8, -26.7);//07
            glVertex3f(8.5, 5.4, -11.5); glVertex3f(8.5, 6.6, -31.5);  glVertex3f(8.5, 11.8, -26.7);//08
            glVertex3f(8.5, 5.4, -11.5); glVertex3f(8.5, 4.5, -29.3);  glVertex3f(8.5, 6.6, -31.5);//09
            glVertex3f(8.5, 5.4, -11.5); glVertex3f(8.5, 2.9, -11.5);  glVertex3f(8.5, 4.5, -29.3);//10
            glVertex3f(8.5, 2.9, -11.5); glVertex3f(8.5, 2.9, -29.3);  glVertex3f(8.5, 4.5, -29.3);//11
            glVertex3f(8.5, 6.6, -31.5); glVertex3f(8.5, 6.6, -34.5);  glVertex3f(8.5, 11.8, -26.7);//12
            glVertex3f(8.5, 6.6, -34.5); glVertex3f(8.5, 9.6, -40.0);  glVertex3f(8.5, 11.8, -26.7);//13
            glVertex3f(8.5, 6.6, -34.5); glVertex3f(8.5, 4.5, -36.7);  glVertex3f(8.5, 9.6, -40.0);//14
            glVertex3f(8.5, 4.5, -36.7); glVertex3f(8.5, 4.5, -40.0);  glVertex3f(8.5, 9.6, -40.0);//15
        glEnd();

        //Carroceria
        glBegin(GL_QUADS);
            //Parachoque traseiro
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f(-8.5, 5.4, 0.0); glVertex3f(8.5, 5.4, 0.0);
            glVertex3f(8.5, 2.9, 0.0);  glVertex3f(-8.5, 2.9, 0.0);

            glVertex3f(-8.5, 2.9, 0.0); glVertex3f(8.5, 2.9, 0.0);
            glVertex3f(8.5, 2.9, -2.5); glVertex3f(-8.5, 2.9, -2.5);

            glVertex3f(-8.5, 2.9, -2.5);  glVertex3f(8.5, 2.9, -2.5);
            glVertex3f(8.5, 5.4, -2.5);   glVertex3f(-8.5, 5.4, -2.5);
                //Tampa esquerda
                glVertex3f(-8.5, 2.9, 0.0);  glVertex3f(-8.5, 2.9, -2.5);
                glVertex3f(-8.5, 5.4, -2.5); glVertex3f(-8.5, 5.4, 0.0);
                //Tampa direita
                glVertex3f(8.5, 2.9, 0.0);  glVertex3f(8.5, 2.9, -2.5);
                glVertex3f(8.5, 5.4, -2.5); glVertex3f(8.5, 5.4, 0.0);

            //Cavidade traseira
            glColor3f(1.0, 0.0, 0.0);
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
            glVertex3f(8.5, 4.5, -29.3);  glVertex3f(-8.5, 4.5, -29.3);

            glVertex3f(-8.5, 4.5, -29.3); glVertex3f(8.5, 4.5, -29.3);
            glVertex3f(8.5, 6.6, -31.5);  glVertex3f(-8.5, 6.6, -31.5);

            glVertex3f(-8.5, 6.6, -31.5); glVertex3f(8.5, 6.6, -31.5);
            glVertex3f(8.5, 6.6, -34.5);  glVertex3f(-8.5, 6.6, -34.5);

            glVertex3f(-8.5, 6.6, -34.5); glVertex3f(8.5, 6.6, -34.5);
            glVertex3f(8.5, 4.5, -36.7);  glVertex3f(-8.5, 4.5, -36.7);

            //Parachoque dianteiro
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f(-8.5, 4.5, -36.7); glVertex3f(8.5, 4.5, -36.7);
            glVertex3f(8.5, 2.9, -36.7);  glVertex3f(-8.5, 2.9, -36.7);

            glVertex3f(-8.5, 2.9, -36.7); glVertex3f(8.5, 2.9, -36.7);
            glVertex3f(8.5, 2.9, -40.0);  glVertex3f(-8.5, 2.9, -40.0);

            glVertex3f(-8.5, 2.9, -40.0); glVertex3f(8.5, 2.9, -40.0);
            glVertex3f(8.5, 4.5, -40.0);  glVertex3f(-8.5, 4.5, -40.0);
                //Tampa esquerda
                glVertex3f(-8.5, 2.9, -36.7); glVertex3f(-8.5, 2.9, -40.0);
                glVertex3f(-8.5, 4.5, -40.0); glVertex3f(-8.5, 4.5, -36.7);
                //Tampa direita
                glVertex3f(8.5, 2.9, -36.7); glVertex3f(8.5, 2.9, -40.0);
                glVertex3f(8.5, 4.5, -40.0); glVertex3f(8.5, 4.5, -36.7);

            //Dianteira
            glColor3f(1.0, 0.0, 0.0);
            glVertex3f(-8.5, 4.5, -40.0);  glVertex3f(8.5, 4.5, -40.0);
            glVertex3f(8.5, 9.6, -40.0);   glVertex3f(-8.5, 9.6, -40.0);

            //Capo
            glVertex3f(-8.5, 9.6, -40.0);  glVertex3f(8.5, 9.6, -40.0);
            glVertex3f(8.5, 11.8, -26.7);   glVertex3f(-8.5, 11.8, -26.7);

            //Parabrisa
            glVertex3f(-8.5, 11.8, -26.7);  glVertex3f(8.5, 11.8, -26.7);
            glVertex3f(8.5, 16.2, -20.0);  glVertex3f(-8.5, 16.2, -20.0);

            //Teto
            glVertex3f(-8.5, 16.2, -20.0); glVertex3f(8.5, 16.2, -20.0);
            glVertex3f(8.5, 16.2, -10.0);  glVertex3f(-8.5, 16.2, -10.0);

            //Traseira
            glVertex3f(-8.5, 16.2, -10.0); glVertex3f(8.5, 16.2, -10.0);
            glVertex3f(8.5, 11.6, 0.0);   glVertex3f(-8.5, 11.6, 0.0);

            glVertex3f(-8.5, 11.6, 0.0);  glVertex3f(8.5, 11.6, 0.0);
            glVertex3f(8.5, 5.4, 0.0);    glVertex3f(-8.5, 5.4, 0.0);
        glEnd();

        //Vidros
        glColor3f(0.2, 0.2, 0.2);
            glBegin(GL_QUADS);
                //Traseiro
                glVertex3f(-7.5, 12.45, -1.8); glVertex3f(7.5, 12.45, -1.8);
                glVertex3f(7.5, 15.8, -9.1);   glVertex3f(-7.5, 15.8, -9.1);
            glEnd();
            glBegin(GL_QUADS);
                //Dianteiro
                glVertex3f(-7.5, 12.7, -25.4); glVertex3f(7.5, 12.7, -25.4);
                glVertex3f(7.5, 15.7, -20.8);   glVertex3f(-7.5, 15.7, -20.8);
            glEnd();

            glBegin(GL_POLYGON);
                //Vidros esquerdo
                glVertex3f(-8.51, 11.2, -1.6);  glVertex3f(-8.51, 11.2, -25.7);
                glVertex3f(-8.51, 15.2, -19.7); glVertex3f(-8.51, 15.2, -10.2);
            glEnd();
            glBegin(GL_POLYGON);
                //Vidros direito
                glVertex3f(8.51, 11.2, -1.6);  glVertex3f(8.51, 11.2, -25.7);
                glVertex3f(8.51, 15.2, -19.7); glVertex3f(8.51, 15.2, -10.2);
            glEnd();

        //Portas
        glColor3f(0.0, 0.0, 0.0);
            //Esquerda
            glBegin(GL_LINES);
                glVertex3f(-8.51, 4.4, -13.0); glVertex3f(-8.51, 15.2, -13.0);
                glVertex3f(-8.51, 4.4, -13.0); glVertex3f(-8.51, 4.4, -25.7);
                glVertex3f(-8.51, 4.4, -25.7); glVertex3f(-8.51, 11.2, -25.7);
            glEnd();
            //Direita
            glBegin(GL_LINES);
                glVertex3f(8.51, 4.4, -13.0); glVertex3f(8.51, 15.2, -13.0);
                glVertex3f(8.51, 4.4, -13.0); glVertex3f(8.51, 4.4, -25.7);
                glVertex3f(8.51, 4.4, -25.7); glVertex3f(8.51, 11.2, -25.7);
            glEnd();

        //Lanternas
        glColor3f(0.8, 0.0, 0.0);
            //Traseira esquerda
            glBegin(GL_QUADS);
                glVertex3f(-6.5, 9.1, 0.1);  glVertex3f(-4.5, 9.1, 0.1);
                glVertex3f(-4.5, 10.6, 0.1); glVertex3f(-6.5, 10.6, 0.1);
            glEnd();

            //Traseira direita
            glBegin(GL_QUADS);
                glVertex3f(6.5, 9.1, 0.1);  glVertex3f(4.5, 9.1, 0.1);
                glVertex3f(4.5, 10.6, 0.1); glVertex3f(6.5, 10.6, 0.1);
            glEnd();

        glColor3f(0.9, 0.9, 0.0);
            //Seta esquerda
            glBegin(GL_QUADS);
                glVertex3f(-7.5, 9.1, 0.1);  glVertex3f(-6.5, 9.1, 0.1);
                glVertex3f(-6.5, 10.6, 0.1); glVertex3f(-7.5, 10.6, 0.1);
            glEnd();

            //Seta direita
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
}
