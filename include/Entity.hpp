#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Define.hpp"

class Entity{
public:
  Entity(Point p=Point{0,0}, Size s=Size{0,0}, sf::RectangleShape sh=sf::RectangleShape()):position{p}, size{s}, sprite{sh}
  {
    sprite.setPosition(position.x, position.y);
    sprite.setSize(sf::Vector2f{static_cast<float>(size.x), static_cast<float>(size.y)});
    sprite.setFillColor(sf::Color::Blue);
  }
  
  bool pointInEntity(Point);
  void render(sf::RenderWindow&);
  void move(Point);
  Point getPosition(){
    return position;
  }
  
private:
  Point position;
  Size size;
  sf::RectangleShape sprite;
};

#endif
