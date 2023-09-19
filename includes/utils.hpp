#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include "spaceobjects.hpp"

void initSpaceObjects(std::vector<Asteroid> &asteroids, std::vector<Bullet> &bullets, Ship &ship);
float calculateDistance(const Asteroid& asteroid1, const Asteroid& asteroid2);
#endif // !UTILS_HPP
#define UTILS_HPP
