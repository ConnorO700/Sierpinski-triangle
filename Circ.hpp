// copyright 4/16/18 Connor O'Brien
#pragma once

class Circ: public sf::Drawable{
public:
  Circ();
  Circ(int n, sf::Vector2f center,int r);
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
  sf::CircleShape round;
  Circ *ptop;
  Circ *pleft;
  Circ *pright;
  Circ *pbot; 
}; 
