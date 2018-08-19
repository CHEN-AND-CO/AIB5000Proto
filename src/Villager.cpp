#include "Villager.hpp"

Villager::Villager(sf::Color c, Point p):Entity{c, 5, p, Size{10,10}, "ressources/villager.jpg"}
{}

void Villager::update(std::vector<std::shared_ptr<Entity>>){
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
