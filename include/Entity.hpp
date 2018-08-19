#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Define.hpp"
#include <memory>

class Entity{
public:
  Entity(sf::Color col, int sp=1, Point p=Point{0,0}, Size s=Size{0,0}, std::string imagePath=""):position{p}, target{p}, size{s}, speed{sp}, color{col}
  {
    texture.loadFromFile(imagePath);
    sprite.setTexture(texture);
  }
  
  bool pointInEntity(Point) const;
  virtual void render(sf::RenderWindow&);
  Point getPosition() const{
    return position;
  }
  virtual void setTargetPosition(Point);
  
  virtual void update(std::vector<std::shared_ptr<Entity>>){}
  bool collide(const Entity&) const;
  virtual Type getType() = 0;
  
protected:
  virtual void move(Point);
  
  Point position, target;
  Size size;
  sf::Sprite sprite;
  sf::Texture texture;
  int speed;
  sf::Color color;
};

#endif
