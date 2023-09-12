#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>

GLfloat angle = 0.0f;
GLfloat xc = 0.0f, yc = 0.0f;
GLfloat matrix[16] = {1.0f, 0.0f, 0.0f, 0.0f,
                               0.0f, 1.0f, 0.0f, 0.0f,
                               0.0f, 0.0f, 1.0f, 0.0f,
                               0.0f, 0.0f, 0.0f, 1.0f,};

void display(void) {
  glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // Desenha os eixos
  glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);
  glEnd();

  // Desenha o triângulo
  glPushMatrix();
    // Multiplica a matriz atual pela matriz da transformação anterior
    // glMultMatrixf(matrix);
    // Rotaciona o triângulo em torno do seu centro
    glLoadIdentity();
    glTranslatef(xc, yc, 0.0f);
    glTranslatef(0.5f, 0.5f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-0.5f, -0.5f, 0.0f);
    // Translada o triângulo na direção x e y
    std::cout << "x: "<< xc << " y: "<< yc << '\n';
    glTranslatef(xc, yc, 0.0f);
    // Salva a matriz da transformação atual
    glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
    // Desenha o triângulo com cores diferentes
    glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.25f, 0.25f);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.75f, 0.75f);
      glColor3f(1.0f, 1.5f, 1.f);
      glVertex2f(1.f, .25F);
    glEnd();
  glPopMatrix();

  glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 'a':
      angle += 10;
      break;
    case 'd':
      angle -= 10;
      break;
    case 'w':
      yc += .05;
      break;
    case 's':
      yc -= .05f;
      break;
    case 'q':
      xc -= .05f;
      break;
    case 'e':
      xc += .05f;
      break;
    default:
      break;
   }
   glutPostRedisplay();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(500,500); 
   glutInitWindowPosition(100,100); 
   glutCreateWindow("Triangulo");
   glutDisplayFunc(display); 
   glutKeyboardFunc(keyboard); 
   glutMainLoop(); 
   return 0; 
}

