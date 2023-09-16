#include "drawing.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <array>
#include <cmath>
#include <iostream>
#include <math.h>
// #include "keyboardActions.hpp"
#include "spaceobjects.hpp"

Ship ship;
std::array<Bullet, 16> bullets;
std::array<Asteroid, 16> asteroids;

void setUpWindow() {
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowSize(720, 720);
  glutInitWindowPosition(1260, 0);
  glutCreateWindow("Astro-16");
}

void display() {

  glClearColor(0.3f, 0.4f, 0.2f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  drawShip(ship);

  for (Bullet bullet : bullets) {

    if (bullet.status) {
      drawBullet(bullet);
    }
  }
  for (Asteroid asteroid : asteroids) {

    if (asteroid.status) {
      drawAsteroid(asteroid);
    }
  }
}
void init() {

  ship.degree = 0.0f;
  ship.x = 0.0f;
  ship.y = 0.0f;
  ship.xDir = 0.0f;
  ship.yDir = 1.0f;

  Bullet bullet;
  bullet.status = false;
  Asteroid asteroid;
  asteroid.status = false;

  for (int i = 0; i < bullets.size(); ++i) {
    bullets[i] = bullet;
    asteroids[i] = asteroid;
  }
  std::cout << bullets.size() << '\n';
}
void keyBoardSpecialAction(int key, int x, int y) {

  GLfloat degreeInRad = (90.0f + ship.degree) * M_PI / 180.0f;
  std::cout << ship.degree << '\n';
  switch (key) {
  case GLUT_KEY_LEFT:
    std::cout << "LEFT_KEY\n";
    ship.degree += 6;
    std::cout << ship.degree << '\n';
    break;

  case GLUT_KEY_RIGHT:
    std::cout << "RIGHT_KEY\n";
    ship.degree -= 6;
    std::cout << ship.degree << '\n';
    break;
  }
  ship.xDir = cos(degreeInRad);
  ship.yDir = sin(degreeInRad);
  if (abs(ship.degree) >= 359) {
    ship.degree = 0;
  }
  glutPostRedisplay();
}

void keyBoardAction(unsigned char key, int x, int y) {
  GLfloat step = 0.1f, relativeStep;
  GLfloat relativeDegree = abs(ship.degree);
  if (relativeDegree > 90) {
    relativeStep = -0.1f;
  } else {
    relativeStep = 0.1f;
  }
  switch (key) {
  case 'w':
    ship.y += ship.yDir * step;
    ship.x += ship.xDir * step;
    break;

  case 's':
    ship.y -= ship.yDir * step;
    ship.x -= ship.xDir * step;
    break;

  case 'd':
    ship.y += -ship.xDir * relativeStep;
    ship.x += ship.yDir * relativeStep;
    break;

  case 'a':
    ship.y += ship.xDir * relativeStep;
    ship.x += -ship.yDir * relativeStep;
    break;
  }
  std::cout << "x: " << ship.x << " y: " << ship.y << '\n';
  glutPostRedisplay();
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

int main(int argc, char *argv[]) {

  glutInit(&argc, argv);
  init();
  setUpWindow();
  glutDisplayFunc(display);
  glutReshapeFunc(resizeView);
  glutSpecialFunc(keyBoardSpecialAction);
  glutKeyboardFunc(keyBoardAction);
  glutMainLoop();

  return EXIT_SUCCESS;
}
