#include <SFML/Graphics.hpp>

int main(){
  sf::RenderWindow w(sf::VideoMode(200,200), "AIB5000 Proto");
  
  while(w.isOpen()){
    sf::Event event;
    while(w.pollEvent(event)){
      switch(event.type){
      case sf::Event::Closed:
	w.close();
	break;

      default:
	break;
      }
    }

    w.clear();
    w.display();
  }

  return 0;
}
