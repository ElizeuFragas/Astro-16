#include "actions.hpp"
#include "drawing.hpp"
#include "spaceobjects.hpp"
#include "utils.hpp"
#include "window.hpp"
#include <GL/freeglut.h>
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <iostream>
#include <vector>

const int MAX_BULLETS = 1;
const int MAX_ASTEROIDS = 7;
const double BULLET_SPEED = 0.3;
const double ASTEROID_SPEED = 0.06;
const int UPDATE_TIMER = 15;
const int ANIMATION_TIMER = 10;

Ship ship;
std::vector<Bullet> bullets(MAX_BULLETS);
std::vector<Asteroid> asteroids(MAX_ASTEROIDS);
int score = 0;
bool onStart = true;
bool animationStatus = false;
bool inGameStatus = false;

void initialAnimationTimer(int value) {

  if (ship.size >= 0.5f) {
    ship.size -= 0.05f;

    glutPostRedisplay();
    // Reagenda a função timer para ser chamada novamente após 100 milissegundos
    glutTimerFunc(ANIMATION_TIMER, initialAnimationTimer, 0);
  } else if (ship.y > -4.0f) {
    ship.y -= 0.05f;
    glutPostRedisplay();
    // Reagenda a função timer para ser chamada novamente após 100 milissegundos
    glutTimerFunc(ANIMATION_TIMER, initialAnimationTimer, 0);

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

  if (inGameStatus) {
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
  else if (animationStatus) {

    drawShip(ship);
  }
  else {
    drawShip(ship);
    drawInitialMessage();
  }
  glutPostRedisplay();
  glutSwapBuffers();
}
void keyBoardSpecialAction(int key, int x, int y) { rotateShip(key, ship); }

void keyBoardAction(unsigned char key, int x, int y) {
  translateShip(key, ship);
  if (key == 'f' && !ship.isAlive) {
    animationStatus = true;
    inGameStatus = false;
    initSpaceObjects(asteroids, bullets, ship);
    glutPostRedisplay();
    glutTimerFunc(ANIMATION_TIMER, initialAnimationTimer, 0);
  }
  if (key == 's' && !inGameStatus && !animationStatus) {
    animationStatus = true;
    initSpaceObjects(asteroids, bullets, ship);
    glutPostRedisplay();
    glutTimerFunc(ANIMATION_TIMER, initialAnimationTimer, 0);
  }
}

void update(int value) {

  if (inGameStatus) {
    updateBullets(bullets, ship, BULLET_SPEED);
  }
  if (inGameStatus) {
    updateAsteroids(asteroids, bullets, score, ASTEROID_SPEED);
  }
  updateShipStatus(ship, asteroids);
  glutPostRedisplay();
  glutTimerFunc(UPDATE_TIMER, update, 0);
}

int main(int argc, char *argv[]) {

  glutInit(&argc, argv);
  initSpaceObjects(asteroids, bullets, ship);
  setUpWindow();
  glutDisplayFunc(display);
  glutTimerFunc(UPDATE_TIMER, update, 0);
  glutReshapeFunc(resizeView);
  glutSpecialFunc(keyBoardSpecialAction);
  glutKeyboardFunc(keyBoardAction);
  glutMainLoop();

  return EXIT_SUCCESS;
}
