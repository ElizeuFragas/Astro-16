#ifndef DRAWING_HPP
#define DRAWING_HPP

#include <GL/gl.h>
#include <GL/glut.h>

class Drawing {
public:
  static GLint degree, mode;
  static GLfloat xC, yC, matrix[16];
 
  static void drawObject();
  static GLfloat getDegree();
  
private:
  static void rotateObject(); 
  static void translateObject();
};

#endif // !DRAWING_HPP
