// copyright 4/16/18 Connor O'Brien
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Sierpinski.hpp"
void Sierpinski::filledTriangle(double x, double y, double s) {
  // it looks nicer without filling it
}
Sierpinski::Sierpinski(int n, sf::Vector2f top, sf::Vector2f left, sf::Vector2f right) {//NOLINT()
  if (n < 0) {
    ptop = NULL;
    pleft = NULL;
    pright = NULL;
  } else {
    poly.setPointCount(3);
    poly.setPoint(0, top);
    poly.setPoint(1, left);
    poly.setPoint(2, right);
    poly.setOutlineColor(sf::Color::Blue);
    poly.setOutlineThickness(1);
    sf::Vector2f midbottom((left.x+right.x)/2, (left.y+right.y)/2);
    sf::Vector2f midleft((top.x+left.x)/2, (top.y+left.y)/2);
    sf::Vector2f midright((top.x+right.x)/2, (top.y+right.y)/2);
    Sierpinski *temp1 = new Sierpinski(n-1, top, midleft, midright);
    Sierpinski *temp2 = new Sierpinski(n-1, midleft, left, midbottom);
    Sierpinski *temp3 = new Sierpinski(n-1, midright, midbottom, right);
    ptop = temp1;
    pleft = temp2;
    pright = temp3;
  }
}
void Sierpinski::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  if ((ptop != NULL) || (pleft != NULL) || (pright != NULL)) {
    target.draw(poly);
    target.draw(*ptop);
    target.draw(*pleft);
    target.draw(*pright);
  }
}
