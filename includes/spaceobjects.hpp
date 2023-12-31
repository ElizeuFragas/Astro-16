#ifndef SPACE_OBJECTS_HPP
#define SPACE_OBJECTS_HPP

#include <GL/glut.h>

class Ship {

public:
  GLfloat degree, x, y, size;
  GLfloat xDir, yDir;
  bool isAlive;
  Ship(){}
  Ship(GLfloat degree, GLfloat x, GLfloat y) {

    this->degree = degree;
    this->x = x;
    this->y = y;
  }
};

class Bullet{

  public:
    GLfloat x, y;
    GLfloat degree;
    GLfloat xDir, yDir;
    bool status;
    
    Bullet(){}
  //   Bullet(GLfloat x, GLfloat y, GLfloat degree, GLfloat xDir, GLfloat yDir){
  //     this->x = x;
  //     this->y = x;
  //     this->degree = degree;
  //     this->xDir = xDir;
  //     this->yDir = yDir;
  // }
};

class Asteroid{
  
  public:
    GLfloat x, y, degree, xDir, yDir;
    bool status;
    
    Asteroid(){}
    Asteroid(GLfloat x, GLfloat y, GLfloat degree, GLfloat xDir, GLfloat yDir){
      this->x = x;
      this->y = x;
      this->degree = degree;
      this->xDir = xDir;
      this->yDir = yDir;
  }
};

#endif // !SPACE_SHIP_HPPj
