#ifndef DRAWING_HPP
#define DRAWING_HPP

#include <GL/glut.h>
#include "spaceobjects.hpp"

void drawShip(Ship& ship);
void drawShip(Ship& ship, GLfloat zoom);
void drawAsteroid(Asteroid& asteroid);
void drawBullet(Bullet& bullet);
void drawScore(int score);
void drawCircle(GLfloat x, GLfloat y, GLfloat radius);
void drawGameOver();
void drawAxis();

#endif // !DRAWING_HPP
