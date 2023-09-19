#include "drawing.hpp"
#include "spaceobjects.hpp"
#include <GL/freeglut.h>
#include <cmath>
#include <iostream>
#include <string.h>

void drawShip(Ship &ship) {

  glPushMatrix();
  glTranslatef(ship.x, ship.y, 0.0f);
  glScalef(ship.size, ship.size, 1.0f);
  glRotatef(ship.degree, 0.0f, 0.0f, 1.0f);

  glBegin(GL_POLYGON);
  glColor3f(1.0f, 1.0f, 1.0f);
  glVertex2f(0.0f, 1.25f);
  glVertex2f(0.0f, -0.4f);
  glVertex2f(-0.2f, -0.4f);
  glVertex2f(-1.5f, -1.25f);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex2f(0.0f, 1.25f);
  glVertex2f(0.0f, -0.4f);
  glVertex2f(0.2f, -0.4f);
  glVertex2f(1.5f, -1.25f);
  glEnd();
  glPopMatrix();
}

void drawBullet(Bullet &bullet) {
  glPushMatrix();
  glColor3f(1.0f, 1.0f, 0.0f);
  drawCircle(bullet.x, bullet.y, 0.2f);
  glPopMatrix();
}

void drawAsteroid(Asteroid &asteroid) {
  glPushMatrix();
  glColor3f(0.5f, 0.5f, 0.5f);
  drawCircle(asteroid.x, asteroid.y, 0.5f);
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

void drawScore(int score) {

  glPushMatrix();
  glLoadIdentity();

  glColor3f(1.0, 1.0, 1.0);

  glRasterPos2f(-4.4f, 6.0f);

  std::string scoreStr = std::to_string(score);
  char const *charBuffer = scoreStr.c_str();

  const unsigned char *bufferChars =
      reinterpret_cast<const unsigned char *>(charBuffer);
  glutBitmapString(GLUT_BITMAP_HELVETICA_18, bufferChars);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1.0, 1.0, 1.0);
  glRasterPos2f(-6.0f, 6.0f);
  glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned const char *)"SCORE:");
  glPopMatrix();
  glPopMatrix();
}

void drawGameOver(){
  glPushMatrix();
  glLoadIdentity();

  glColor3f(1.0, 1.0, 1.0);

  glRasterPos2f(-1.05f, 0.0f);

  char gameOverMessage[] = "GAME OVER";
  glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)gameOverMessage);
  glPopMatrix();
  
}
void drawAxis() {

  glPushMatrix();
  glColor3f(0.0f, 0.0f, 0.0f);
  glBegin(GL_LINES);
  glVertex2f(0.0f, 7.0f);
  glVertex2f(0.0f, -7.0f);
  glVertex2f(7.0f, 0.0f);
  glVertex2f(-7.0f, 0.0f);
  glEnd();
  glPopMatrix();
}
