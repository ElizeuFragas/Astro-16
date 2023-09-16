#include "drawing.hpp"
#include "spaceobjects.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>

void drawShip(Ship &ship) {
  std::cout << "from drawShip: "<< ship.degree << '\n';
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glTranslatef(ship.x, ship.y, 0.0f);
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
  glFlush();
}

void drawBullet(Bullet bullet) {
    glColor3f(1.0, 1.0, 0.0);

    drawCircle(bullet.x, bullet.y, 0.01);
}

void drawAsteroid(Asteroid asteroid) {
    glColor3f(0.5, 0.5, 0.5);

    // Desenhar o asteroide como um círculo de raio 0.05
    drawCircle(asteroid.x, asteroid.y, 0.05);
}
void drawCircle(GLfloat x, GLfloat y, GLfloat radius) {
    glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float angle = i * M_PI / 180;
            float x = x + radius * cos(angle);
            float y = y + radius * sin(angle);
            glVertex2f(x, y);
        }
    glEnd();
}
