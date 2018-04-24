// copyright 4/16/18 Connor O'Brien
#include <SFML/Graphics.hpp>
#include "Sierpinski.hpp"
int main(int argc, char *argv[]) {
  int n = atof(argv[1]);
  int h = atof(argv[2]);
  sf::RenderWindow window(sf::VideoMode(h, h), "Sierpinski");
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    window.clear();
    Sierpinski fi(n, sf::Vector2f(h/2, 0), sf::Vector2f(0, h), sf::Vector2f(h, h));//NOLINT()
    window.draw(fi);
    window.display();
  }
}
