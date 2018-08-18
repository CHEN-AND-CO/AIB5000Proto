#include "Villager.hpp"
#include "TownCenter.hpp"

int main(){
  sf::RenderWindow w(sf::VideoMode(800,600), "AIB5000 Proto");
  std::vector<std::shared_ptr<Entity>> entities;
  std::vector<int> selectedEntities;
  
  w.setFramerateLimit(60);

  //auto ptr = std::make_shared<TownCenter>(TownCenter(sf::Color::Blue, Point{100,100}))
  entities.push_back(std::make_shared<TownCenter>(TownCenter(sf::Color::Blue, Point{100,100})));
  entities.push_back(std::make_shared<Villager>(Villager(sf::Color::Blue, Point{50,50})));
  
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
	  
	  for(auto e: entities){
	    if(e->pointInEntity(Point{event.mouseButton.x, event.mouseButton.y})){
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
	    entities[e]->setTargetPosition(Point{event.mouseButton.x, event.mouseButton.y});
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
      e->update(entities);
      e->render(w);
    }
    w.display();
  }
  
  return 0;
}
