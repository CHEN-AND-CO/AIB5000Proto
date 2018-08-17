#include "Entity.hpp"

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

void Entity::update(std::vector<Entity>&x){
  Point nextPos{target.x-position.x, target.y-position.y};

  if(nextPos.x > 0){
    if(nextPos.x < 5){
      nextPos.x = 0;
    }else{
      nextPos.x = speed;
    }
  }else if(nextPos.x < 0){
    if(nextPos.x > -5){
      nextPos.x = 0;
    }else{
      nextPos.x = -speed;
    }
  }

  if(nextPos.y > 0){
    if(nextPos.y < 5){
      nextPos.y = 0;
    }else{
      nextPos.y = speed;
    }
  }else if(nextPos.y < 0){
    if(nextPos.y > -5){
      nextPos.y = 0;
    }else{
      nextPos.y = -speed;
    }
  }
  
  move(nextPos);
}

bool Entity::collide(const Entity& e) const{
  return e.pointInEntity(position) &&
    e.pointInEntity(position+size);
}
