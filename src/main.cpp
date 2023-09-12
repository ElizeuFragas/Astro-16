#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include "drawing.hpp"
#include "keyboardActions.hpp"

void setUpWindow(){
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowSize(720, 720);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Astro-16");
}

void setUpScreen(){
  glClearColor(0.3f, 0.4f, 0.2f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  Drawing::drawObject();
  std::cout<<Drawing::mode<<'\n';
}

void resizeView(GLsizei w, GLsizei h){
  if(h == 0) h = 1;

  glViewport(0, 0, w, h);
  
  std::cout<< "w:" << w <<std::endl;
  std::cout<< "h:" << h <<std::endl;
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (w <= h) 
    gluOrtho2D (-7.0f, 7.0f, -7.0f*h/w, 7.0f*h/w);
  else 
    gluOrtho2D (-7.0f*w/h, 7.0f*w/h, 7.0f, 7.0f);
}

int main(int argc, char *argv[]){

  glutInit(&argc, argv);
  setUpWindow();
  glutDisplayFunc(setUpScreen);
  glutReshapeFunc(resizeView);
  glutSpecialFunc(EventHandler::keyBoardSpecialAction);
  glutKeyboardFunc(EventHandler::keyBoardAction);
  glutMainLoop();
  
  return EXIT_SUCCESS;
}
