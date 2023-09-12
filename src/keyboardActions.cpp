#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include "drawing.hpp"
#include "keyboardActions.hpp"

void EventHandler::keyBoardSpecialAction(int key, int x, int y) {
  Drawing::mode = 1;
  switch (key) {
    case GLUT_KEY_LEFT:
      std::cout << "UP_KEY\n";
      if (Drawing::degree > 360)
        Drawing::degree = 0;
      Drawing::degree = 6;
      std::cout << Drawing::degree << '\n';
      break;

    case GLUT_KEY_RIGHT:
      std::cout << "DOWN_KEY\n";
      if (Drawing::degree < -360) {
        Drawing::degree = 0;
      }
      Drawing::degree = -6;
      std::cout << Drawing::degree << '\n';
      break;
  }
  glutPostRedisplay();
}

void EventHandler::keyBoardAction(unsigned char key, int x, int y){
  Drawing::mode = 2;
  GLfloat xLeft, xRight;

  if (abs(Drawing::degree) > 90) {
    xLeft = 0.1f;  
    xRight = -0.1f;  
  } else {
    xLeft = -0.1f;  
    xRight = 0.1f;  
  }
  switch (key) {
    case 'w':
      // Drawing::xC+=0.1f;
      Drawing::yC=0.1f;
      Drawing::xC=0.0f;
      // std::cout<<Drawing::yC<<'\n';
      break;
    
    case 's':
      // Drawing::xC-=0.1f;
      Drawing::yC=-0.1f;
      Drawing::xC=0.0f;
      // std::cout<<Drawing::yC<<'\n';
      break;
    
    case 'd':
      Drawing::yC=0.0f;
      // std::cout<<Drawing::yC<<'\n';
      Drawing::xC=xRight;
      // std::cout<<Drawing::xC<<'\n';
      break;
    
    case 'a':
      Drawing::yC=0.0f;
      // std::cout<<Drawing::yC<<'\n';
      Drawing::xC=xLeft;
      // std::cout<<Drawing::xC<<'\n';
      break;
    }
  glutPostRedisplay();
}


