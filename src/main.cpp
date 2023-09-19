#include "actions.hpp"
#include "drawing.hpp"
#include "spaceobjects.hpp"
#include "utils.hpp"
#include "window.hpp"
#include <GL/freeglut_std.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>

const int TIMER = 15;
const int MAX_BULLETS = 1;
const double BULLET_SPEED = 0.3;
const int MAX_ASTEROIDS = 10;
const double ASTEROID_SPEED = 0.06;

Ship ship;
std::vector<Bullet> bullets(MAX_BULLETS);
std::vector<Asteroid> asteroids(MAX_ASTEROIDS);
int score = 0;
bool animationStatus = false;
bool inGameStatus = false;

unsigned int animationTimer = 10;
unsigned int count = 0;
GLfloat scale = 18.0f;
GLfloat move = 0.0f;

void initialAnimationTimer(int value) {

  if (ship.size >= 0.5f) {
    std::cout << "scale: " << ship.size << '\n';
    ship.size -= 0.05f;

    glutPostRedisplay();
    // Reagenda a função timer para ser chamada novamente após 100 milissegundos
    glutTimerFunc(animationTimer, initialAnimationTimer, 0);
  } else if (ship.y > -4.0f) {
    std::cout << "move: " << ship.y << '\n';
    ship.y -= 0.05f;
    glutPostRedisplay();
    // Reagenda a função timer para ser chamada novamente após 100 milissegundos
    glutTimerFunc(animationTimer, initialAnimationTimer, 0);

  } else {
    animationStatus = false;
    inGameStatus = true;
  }
}
void display() {

  glClearColor(0.10f, 0.10f, 0.10f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  if (!animationStatus) {
    // inialtAnimation(scale, move);
    drawScore(score);

    for (Asteroid asteroid : asteroids) {

      if (asteroid.status) {
        drawAsteroid(asteroid);
      }
    }
    if (ship.isAlive) {

      for (Bullet bullet : bullets) {

        if (bullet.status) {
          drawBullet(bullet);
        }
      }
      drawShip(ship);
    } else {

      drawGameOver();
    }
  }
  glutPostRedisplay();
  glFlush();
}
void keyBoardSpecialAction(int key, int x, int y) {

  std::cout << key << '\n';
  rotateShip(key, ship);
  // glutPostRedisplay();
}

void keyBoardAction(unsigned char key, int x, int y) {
  translateShip(key, ship);
  // glutPostRedisplay();
  std::cout << key << '\n';
}

void update(int value) {

  updateBullets(bullets, ship, BULLET_SPEED);
  updateAsteroids(asteroids, bullets, score, ASTEROID_SPEED);
  updateShipStatus(ship, asteroids);
  glutPostRedisplay();
  glutTimerFunc(TIMER, update, 0);
}

void idle() {
  if (inGameStatus) {
    glutTimerFunc(TIMER, update, 0);
    inGameStatus = false;
  }
}

int main(int argc, char *argv[]) {

  glutInit(&argc, argv);
  initSpaceObjects(asteroids, bullets, ship);
  setUpWindow();
  glutTimerFunc(animationTimer, initialAnimationTimer, 0);
  glutDisplayFunc(display);
  glutReshapeFunc(resizeView);
  glutSpecialFunc(keyBoardSpecialAction);
  glutKeyboardFunc(keyBoardAction);
  glutIdleFunc(idle);
  glutMainLoop();

  return EXIT_SUCCESS;
}
