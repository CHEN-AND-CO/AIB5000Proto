#include "Entity.hpp"

int main(){
  sf::RenderWindow w(sf::VideoMode(800,600), "AIB5000 Proto");
  std::vector<Entity> entities;
  std::vector<int> selectedEntities;

  w.setFramerateLimit(60);
  
  entities.push_back(Entity(5, Point{10,10}, Size{10,10}, sf::RectangleShape()));
  entities.push_back(Entity(4, Point{20,20}, Size{10,10}, sf::RectangleShape()));
  entities.push_back(Entity(3, Point{30,30}, Size{10,10}, sf::RectangleShape()));
  entities.push_back(Entity(2, Point{40,40}, Size{20,20}, sf::RectangleShape()));
    
  while(w.isOpen()){
    sf::Event event;
    while(w.pollEvent(event)){
      switch(event.type){
      case sf::Event::Closed:
	w.close();
	break;
	
      case sf::Event::MouseButtonPressed:{
	  if(event.mouseButton.button == sf::Mouse::Left){
	    bool select = false;
	    int i = 0;
	    
	    for(Entity& e: entities){
	      if(e.pointInEntity(Point{event.mouseButton.x, event.mouseButton.y})){
		selectedEntities.push_back(i);
		select = true;
	      }  
	      i++;
	    }
	    if(!select){
	      selectedEntities.clear();
	    }
	    
	    std::sort(selectedEntities.begin(), selectedEntities.end());
	    selectedEntities.erase(unique(selectedEntities.begin(), selectedEntities.end()), selectedEntities.end());
	  }
	  
	  if(event.mouseButton.button == sf::Mouse::Right){
	    for(auto e: selectedEntities){
	      entities[e].setTargetPosition(Point{event.mouseButton.x, event.mouseButton.y});
	    }
	  }
	  
	  break;
	}
	
      default:
	break;
      }
    }
      
    w.clear(sf::Color::Green);
    for(auto& e: entities){
      e.update(entities);
      e.render(w);
    }
    w.display();
  }
  
  return 0;
}
