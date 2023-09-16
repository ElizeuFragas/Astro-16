#ifndef KEYBOARDACTIONS_HPP
#define KEYBOARDACTIONS_HPP

#include <GL/gl.h>
#include "drawing.hpp"
#include "spaceobjects.hpp"

class EventHandler {
  
public:
  static Ship& ship;
  EventHandler(){};
  EventHandler(Ship &ship){
    this-> ship = ship;
  };
  static void keyBoardSpecialAction(int key, int x, int y);
  static void keyBoardAction(unsigned char key, int x, int y);
};

#endif // !DRAWING_HPP
