#include "Entity.hpp"

bool Entity::pointInEntity(Point p){
  if(p.x > position.x &&
     p.x < position.x + size.x &&
     p.y > position.y &&
     p.y < position.y + size.y){
    return true;
  }
  return false;
}

void Entity::render(sf::RenderWindow& w){
  w.draw(sprite);
}

void Entity::move(Point p){
  position = p;
  sprite.setPosition(p.x, p.y);
}
