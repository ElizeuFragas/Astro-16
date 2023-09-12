#ifndef KEYBOARDACTIONS_HPP
#define KEYBOARDACTIONS_HPP

#include <GL/gl.h>
#include "drawing.hpp"

class EventHandler {
  
public:
  static void keyBoardSpecialAction(int key, int x, int y);
  static void keyBoardAction(unsigned char key, int x, int y);

};

#endif // !DRAWING_HPP
