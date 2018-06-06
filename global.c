#include "global.h"

void initArray(Array *a, size_t initialSize) {
  a->array = (Line_t *)calloc(initialSize , sizeof(Line_t));
  a->used = 0;
  a->size = initialSize;
}
void insertArray(Array *a, Line_t element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (Line_t *)realloc(a->array, a->size * sizeof(Line_t));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

void Msg(char *string, GLfloat x, GLfloat y){
        glRasterPos2f(x,y);
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,*string++);
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

void InitScreen(){
    w_width = glutGet(GLUT_WINDOW_WIDTH);
    w_height = glutGet(GLUT_WINDOW_HEIGHT);

    glMatrixMode(GL_PROJECTION); //define que a matrix é a de projeção
    glLoadIdentity(); //carrega a matrix de identidade
    gluPerspective(theta, aspect, d_near, d_far);

    glPushMatrix();
        glRotatef(angX, 1, 0, 0);
        glRotatef(angY, 0, 1, 0);
        glRotatef(angZ, 0, 0, 1);

        glMatrixMode(GL_MODELVIEW); //define que a matrix é a model view
        glLoadIdentity(); //carrega a matrix de identidade

        gluLookAt(x_0, y_0, z_0,
                  x_ref, y_ref, z_ref,
                  V_x, V_y, V_z);
    glPopMatrix();
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
void DesenhaSeg(GLfloat *cor, float x1, float z1, float w1, float x2, float z2, float w2, float y){
    glColor3fv(cor);
    glBegin(GL_QUADS);
        glVertex3f(x1-w1,y,z1);
        glVertex3f(x2-w2,y,z2);
        glVertex3f(x2+w2,y,z2);
        glVertex3f(x1+w1,y,z1);
    glEnd();
}