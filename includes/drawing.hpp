#ifndef DRAWING_HPP
#define DRAWING_HPP

#include <GL/gl.h>
#include <GL/glut.h>
#include "spaceobjects.hpp"

void drawShip(Ship& ship);
void drawAsteroid(Asteroid& asteroid);
void drawBullet(Bullet& bullet);
void drawCircle(GLfloat x, GLfloat y, GLfloat radius);

#endif // !DRAWING_HPP
