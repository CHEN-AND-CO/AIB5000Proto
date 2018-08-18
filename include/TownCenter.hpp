#ifndef TOWNCENTER_HPP
#define TOWNCENTER_HPP

#include "Entity.hpp"

class TownCenter: public Entity{
public:
  TownCenter(sf::Color col, Point p);

  virtual Type getType(){
    return Type::TownCenter;
  }

protected:
  virtual void move(Point){}
  
};

#endif
