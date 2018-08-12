#include "Entity.hpp"
#include <vector>
#include <iostream>

int main(){
  sf::RenderWindow w(sf::VideoMode(800,600), "AIB5000 Proto");
  std::vector<Entity> entities;
  int selectedEntity = -1;
  
  entities.push_back(Entity(Point{10,10}, Size{10,10}, sf::RectangleShape()));
  
  while(w.isOpen()){
    sf::Event event;
    while(w.pollEvent(event)){
      switch(event.type){
      case sf::Event::Closed:
	w.close();
	break;
	
      case sf::Event::MouseButtonPressed:
	{
	  bool select = false;
	  int i = 0;
	  std::cout << "Mouse Clik\n";
	  for(Entity& e: entities){
	    if(e.pointInEntity(Point{event.mouseButton.x, event.mouseButton.y})){
	      std::cout << "Selected\n";
	      selectedEntity = i;
	      select = true;
	    }
	    i++;	    
	  }
	  
	  if(!select && selectedEntity != -1){
	    std::cout << "Move\n";
	    entities[selectedEntity].move(Point{event.mouseButton.x, event.mouseButton.y});
	  }
	  
	  break;
	}
	
      default:
	break;
      }
    }
    
    w.clear();
    for(auto& e: entities){
      e.render(w);
    }
    w.display();
  }
  
  return 0;
}
