#include "Entity.hpp"
#include <memory>

bool Entity::pointInEntity(Point p) const{
  if(p.x >= position.x &&
     p.x <= position.x + size.x &&
     p.y >= position.y &&
     p.y <= position.y + size.y){
    return true;
  }
  return false;
}

void Entity::render(sf::RenderWindow& w){
  w.draw(sprite);
}

void Entity::move(Point p){
  position += p;
  sprite.setPosition(position.x, position.y);
}

void Entity::setTargetPosition(Point p){
  target = p;
}

bool Entity::collide(const Entity& e) const{
  return e.pointInEntity(position) &&
    e.pointInEntity(position+size) &&
    e.pointInEntity(position+Point{size.x, 0}) &&
    e.pointInEntity(position+Point{0, size.y});
}
