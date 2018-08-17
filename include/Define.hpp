#ifndef DEFINE_HPP
#define DEFINE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <algorithm>

struct Point{
  int x,y;

  Point& operator+=(const Point& a){
    this->x += a.x;
    this->y += a.y;
    return *this;
  }
};

Point operator-(const Point&, const Point&);
Point operator+(const Point&, const Point&);

using Size = Point;

#endif
