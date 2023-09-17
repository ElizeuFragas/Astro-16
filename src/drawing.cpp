#include "drawing.hpp"
#include "spaceobjects.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>

void drawShip(Ship& ship) {
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  
  glPushMatrix();
  glTranslatef(ship.x, ship.y, 0.0f);
  glScalef(0.5f, 0.5f, 1.0f);
  glTranslatef(0.0f, -6.0f, 0.0f);
  glRotatef(ship.degree, 0.0f, 0.0f, 1.0f);
  glTranslatef(0.0f, 6.0f, 0.0f);
  
  
  glBegin(GL_POLYGON);
  glColor3f(1.0f, 1.0f, 1.0f);
  glVertex2f(0.0f, -4.75f);
  glVertex2f(0.0f, -6.5f);
  glVertex2f(-0.2f, -6.5f);
  glVertex2f(-1.5f, -7.25f);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex2f(0.0f, -4.75f);
  glVertex2f(0.0f, -6.5f);
  glVertex2f(0.2f, -6.5f);
  glVertex2f(1.5f, -7.25f);
  glEnd();
  glPopMatrix();
}

void drawBullet(Bullet& bullet) {
  glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(bullet.x, bullet.y, 0.2f);
  glPopMatrix();
}

void drawAsteroid(Asteroid& asteroid) {
  glPushMatrix();
    glColor3f(0.5f, 0.5f, 0.5f);
    drawCircle(asteroid.x, asteroid.y, 0.05f);
  glPopMatrix();
}

void drawCircle(GLfloat xc, GLfloat yc, GLfloat radius) {
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i++) {
    float angle = i * M_PI / 180.0f;
    float x = xc + radius * cos(angle);
    float y = yc + radius * sin(angle);
    glVertex2f(x, y);
  }
  glEnd();
}
