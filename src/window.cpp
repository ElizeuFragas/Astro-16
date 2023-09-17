#include "window.hpp"
#include <GL/glut.h>

void setUpWindow() {
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowSize(720, 720);
  glutInitWindowPosition(1260, 0);
  glutCreateWindow("Astro-16");
}

void resizeView(GLsizei w, GLsizei h) {
  if (h == 0)
    h = 1;

  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (w <= h)
    gluOrtho2D(-7.0f, 7.0f, -7.0f * h / w, 7.0f * h / w);
  else
    gluOrtho2D(-7.0f * w / h, 7.0f * w / h, 7.0f, 7.0f);
}
