#include "spaceobjects.hpp"
#include "utils.hpp"
#include <vector>

void initSpaceObjects(std::vector<Asteroid> &asteroids, std::vector<Bullet> &bullets, Ship& ship){

  Bullet bullet;
  Asteroid asteroid;

  ship.x = 0.0f;
  ship.y = 0.0f;
  ship.xDir = 0.0f;
  ship.yDir = 1.0f;
  ship.degree = 0.0f;
  ship.size = 18.0f;
  ship.isAlive = true;

  bullet.status = false;
  asteroid.status = false;

  for (int i = 0; i < bullets.size(); ++i) {
    bullets[i] = bullet;
  }
  for (int i = 0; i < asteroids.size(); ++i) {
    asteroids[i] = asteroid;
  }
}
