#include <GL/gl.h>
#include <GL/glut.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include "drawing.hpp"

GLint Drawing::degree = 0.0f;
GLfloat Drawing::xC = 0.0f, Drawing::yC = 0.0f;
GLfloat Drawing::matrix[16] = {1.0f, 0.0f, 0.0f, 0.0f,
                               0.0f, 1.0f, 0.0f, 0.0f,
                               0.0f, 0.0f, 1.0f, 0.0f,
                               0.0f, 0.0f, 0.0f, 1.0f,};
GLint Drawing::mode;


void Drawing::drawObject(){
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  
  glPushMatrix();
  
  glBegin(GL_LINES);
  glColor3f(0.0f, 0.0f, 0.0f);
  glVertex2f(-7.0f, 0.0f);
  glVertex2f(7.0f, 0.0f);
  glVertex2f(0.0f, -7.0f);
  glVertex2f(0.0f, 7.0f);
  glEnd();
  
  for(GLfloat var : matrix) {
    std::cout<< var<<" ";    
  } 
  std::cout<<'\n';

  // glScalef(0.25f, 0.25f, 1.0f);
  
  if (mode == 1) {
    rotateObject();
  }
  else if (mode == 2) {
    translateObject();
  }
  
  glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(3.0f, 5.0f);
    glVertex2f(3.0f, 2.0f);
  glEnd();
  
  glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(6.0f, 0.0f);
    glVertex2f(3.0f, 5.0f);
    glVertex2f(3.0f, 2.0f);
  glEnd();
  glPopMatrix();
  glFlush();
}

void Drawing::rotateObject(){
  
  glMultMatrixf(matrix);
  glTranslatef(3.0f, 2.5f, 0.0f);
  glRotatef(degree, 0.0f, 0.0f, 1.0f);
  glTranslatef(-3.0f, -2.5f, 0.0f);
  glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
}

void Drawing::translateObject(){
  
  std::cout << "x: " << xC << " y: " << yC <<'\n';
  glLoadMatrixf(matrix);
  // glPushMatrix();
  // glLoadIdentity();
  // glRotatef(degree, 0.0f, 0.0f, 1.0f);
  glTranslatef(xC, yC, 0.0f);
  glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
  // glPopMatrix();
}

GLfloat Drawing::getDegree(){
  return degree;
}
