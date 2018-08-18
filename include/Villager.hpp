#ifndef VILLAGER_HPP
#define VILLAGER_HPP

#include "Entity.hpp"

class Villager: public Entity{
public:
  Villager(sf::Color, Point);
  virtual Type getType(){
    return Type::Villager;
  }
  virtual void update(std::vector<std::shared_ptr<Entity>>);
  
protected:
  
};

#endif
