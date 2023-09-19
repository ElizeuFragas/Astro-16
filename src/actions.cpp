#include "drawing.hpp"
#include "spaceobjects.hpp"
#include <GL/glut.h>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

void rotateShip(int key, Ship &ship) {

  GLfloat relDegree = 6.0f;
  switch (key) {
  case GLUT_KEY_LEFT:
    ship.degree += relDegree;
    break;

  case GLUT_KEY_RIGHT:
    ship.degree -= relDegree;
    break;
  }
  GLfloat degreeInRad = (90.0f + ship.degree) * M_PI / 180.0f;
  ship.xDir = cos(degreeInRad);
  ship.yDir = sin(degreeInRad);
  if (abs(ship.degree) >= 359.0f) {
    ship.degree = 0.0f;
  }
}

void translateShip(unsigned char key, Ship &ship) {

  GLfloat step = 0.2f, relativeStep;
  GLfloat relativeDegree = abs(ship.degree);
  if (relativeDegree > 90.0f) {
    relativeStep = -step;
  } else {
    relativeStep = step;
  }
  switch (key) {

    break;
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
}
void updateBullets(std::vector<Bullet> &bullets, Ship ship,
                   double bulletSpeed) {

  for (int i = 0; i < bullets.size(); i++) {

    if (!bullets[i].status) {
      bullets[i].status = true;
      bullets[i].x = ship.x;
      bullets[i].y = ship.y;
      bullets[i].xDir = ship.xDir;
      bullets[i].yDir = ship.yDir;
      break;
    }
  }
  for (int i = 0; i < bullets.size(); i++) {

    if (bullets[i].status) {
      bullets[i].x += bullets[i].xDir * bulletSpeed;
      bullets[i].y += bullets[i].yDir * bulletSpeed;

      if (abs(bullets[i].x) > 7.0f || abs(bullets[i].y) > 7.0f) {
        bullets[i].status = false;
      }
    }
  }
}

void updateAsteroids(std::vector<Asteroid> &asteroids,
                     std::vector<Bullet> &bullets, int &score,
                     double asteroidSpeed) {
  int r = rand() % 10;

  if (r < 5) {

    for (int i = 0; i < asteroids.size(); i++) {
      if (!asteroids[i].status) {

        asteroids[i].status = 1;
        int edge = rand() % 4;
        switch (edge) {
        case 0:
          asteroids[i].x = (rand() % 900 - 100) / 100.0;

          asteroids[i].y = 7.05;
          break;
        case 1:
          asteroids[i].x = (rand() % 900 - 100) / 100.0;

          asteroids[i].y = -7.05;
          break;
        case 2:
          asteroids[i].x = -7.05;

          asteroids[i].y = (rand() % 900 - 100) / 100.0;

          break;
        case 3:
          asteroids[i].x = 7.05;

          asteroids[i].y = (rand() % 900 - 100) / 100.0;

          break;
        }

        asteroids[i].xDir =
            -asteroids[i].x / sqrt(asteroids[i].x * asteroids[i].x +
                                   asteroids[i].y * asteroids[i].y);
        asteroids[i].yDir =
            -asteroids[i].y / sqrt(asteroids[i].x * asteroids[i].x +
                                   asteroids[i].y * asteroids[i].y);

        break;
      }
    }
  }

  for (int i = 0; i < asteroids.size(); i++) {
    if (asteroids[i].status) {
      asteroids[i].x += asteroids[i].xDir * asteroidSpeed;
      asteroids[i].y += asteroids[i].yDir * asteroidSpeed;

      if (asteroids[i].x > 7.0 || asteroids[i].x < -7.0 ||
          asteroids[i].y > 7.0 || asteroids[i].y < -7.0) {
        asteroids[i].status = 0;
      }
    }
  }

  for (int i = 0; i < asteroids.size(); i++) {
    if (asteroids[i].status) {
      for (int j = 0; j < bullets.size(); j++) {
        if (bullets[j].status) {

          float dx = asteroids[i].x - bullets[j].x;
          float dy = asteroids[i].y - bullets[j].y;
          float d = sqrt(dx * dx + dy * dy);

          if (d < 0.5 + 0.2) {
            asteroids[i].status = 0;
            bullets[j].status = 0;
            score++;
          }
        }
      }
    }
  }
}
void updateShipStatus(Ship ship, std::vector<Asteroid> &asteroids) {

  for (int i = 0; i < asteroids.size(); i++) {

    if (asteroids[i].status) {

      float dx = asteroids[i].x -ship.x;
      float dy = asteroids[i].y - ship.y;
      float d = sqrt(dx * dx + dy * dy);

      if (d < 0.5 + 0.2) {
        asteroids[i].status = 0;
        ship.isAlive = false;
      }
    }
  }
}
