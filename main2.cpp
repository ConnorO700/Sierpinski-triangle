// copyright 4/16/18 Connor O'Brien
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Circ.hpp"
int main(int argc, char *argv[]) {
  int n = atof(argv[1]);
  int h = atof(argv[2]);
  sf::RenderWindow window(sf::VideoMode(h, h), "CircleCross");
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    window.clear();
    Circ ci(n, sf::Vector2f(0, 0), h/2);
    window.draw(ci);
    window.display();
  }
}
