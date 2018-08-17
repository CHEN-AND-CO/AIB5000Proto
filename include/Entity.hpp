#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Define.hpp"

class Entity{
public:
  Entity(int sp=1, Point p=Point{0,0}, Size s=Size{0,0}, sf::RectangleShape sh=sf::RectangleShape()):position{p}, target{p}, size{s}, sprite{sh}, speed{sp}
  {
    sprite.setPosition(position.x, position.y);
    sprite.setSize(sf::Vector2f{static_cast<float>(size.x), static_cast<float>(size.y)});
    sprite.setFillColor(sf::Color::Blue);
  }
  
  bool pointInEntity(Point) const;
  void render(sf::RenderWindow&);
  Point getPosition() const{
    return position;
  }
  void setTargetPosition(Point);
  void update(std::vector<Entity>&);
  bool collide(const Entity&) const;
  
private:
  void move(Point);
  
  Point position, target;
  Size size;
  sf::RectangleShape sprite;
  int speed;
};

#endif
