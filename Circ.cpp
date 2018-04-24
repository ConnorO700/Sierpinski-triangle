// copyright 4/16/18 Connor O'Brien
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Circ.hpp"
Circ::Circ(int n, sf::Vector2f center, int r) {
  if (n < 0) {
    ptop = NULL;
    pleft = NULL;
    pright = NULL;
    pbot = NULL;
  } else {
    round.setRadius(r);
    round.setOutlineColor(sf::Color::Red);
    round.setOutlineThickness(1);
    round.setPosition(center.x, center.y);
    sf::Vector2f up(center.x+r/2, center.y);
    sf::Vector2f left(center.x, center.y+(r/2));
    sf::Vector2f right(center.x+r, center.y+(r/2));
    sf::Vector2f down(center.x+r/2, center.y+r);
    Circ *temp1 = new Circ(n-1, up, r/2);  // top
    Circ *temp2 = new Circ(n-1, left, r/2);  // left
    Circ *temp3 = new Circ(n-1, right, r/2);  // right
    Circ *temp4 = new Circ(n-1, down, r/2);  // bottom
    ptop = temp1;
    pleft = temp2;
    pright = temp3;
    pbot = temp4;
  }
}
void Circ::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  if ((ptop != NULL) || (pleft != NULL) || (pright != NULL) || (pbot != NULL)) {
    target.draw(round);
    target.draw(*ptop);
    target.draw(*pleft);
    target.draw(*pright);
    target.draw(*pbot);
  }
}
