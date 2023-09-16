#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include "drawing.hpp"
// #include "keyboardActions.hpp"
// #include "spaceobjects.hpp"



void EventHandler::keyBoardSpecialAction(int key, int x, int y) {
  
  std::cout << ship.degree << '\n';
  Drawing::mode = 1;
  switch (key) {
    case GLUT_KEY_LEFT:
      std::cout << "UP_KEY\n";
      if (EventHandler::ship.degree > 360)
        EventHandler::ship.degree = 0;
      EventHandler::ship.degree += 6;
      std::cout << EventHandler::ship.degree << '\n';
      break;

    case GLUT_KEY_RIGHT:
      std::cout << "DOWN_KEY\n";
      if (EventHandler::ship.degree < -360) {
        EventHandler::ship.degree = 0;
      }
      EventHandler::ship.degree -= 6;
      std::cout << EventHandler::ship.degree << '\n';
      break;
  }
  glutPostRedisplay();
}

// void EventHandler::keyBoardAction(unsigned char key, int x, int y){
//   Drawing::mode = 2;
//   GLfloat xLeft, xRight;
//   if (abs(EventHandler::ship.degree) > 90) {
//     xLeft = 0.1f;  
//     xRight = -0.1f;  
//   } else {
//     xLeft = -0.1f;  
//     xRight = 0.1f;  
//   }
//   switch (key) {
//     case 'w':
//       Drawing::yC=0.1f;
//       Drawing::xC=0.0f;
//       break;
//     
//     case 's':
//       Drawing::yC=-0.1f;
//       Drawing::xC=0.0f;
//       break;
//     
//     case 'd':
//       Drawing::yC=0.0f;
//       Drawing::xC=xRight;
//       break;
//     
//     case 'a':
//       Drawing::yC=0.0f;
//       Drawing::xC=xLeft;
//       break;
//     }
//   glutPostRedisplay();
// }


