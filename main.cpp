#include <GL/freeglut.h>
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
#include <exception>

void setUpScreen(){
  glClearColor(0.3f, 0.4f, 0.2f, 0.4f);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}

int main(int argc, char *argv[]){

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Astro-16");
  glutDisplayFunc(setUpScreen);
  glutMainLoop();
  
  return EXIT_SUCCESS;
}
