#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include "drawing.hpp"
#include "spaceobjects.hpp"
#include <vector>

void rotateShip(int key, Ship &ship);
void translateShip(unsigned char key, Ship &ship);
void updateBullets(std::vector<Bullet> &bullets, Ship ship, double bulletSpeed);
void updateAsteroids(std::vector<Asteroid> &asteroids,
                     std::vector<Bullet> &bullets, int &score,
                     double asteroidSpeed);
void updateShipStatus(Ship &ship, std::vector<Asteroid> &asteroids);
#endif // !DRAWING_HPP
