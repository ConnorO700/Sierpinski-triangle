// copyright 4/16/18 Connor O'Brien
#pragma once


class Sierpinski: public sf::Drawable{
public:
  Sierpinski();
  void filledTriangle(double x, double y, double s);
  Sierpinski(int n, sf::Vector2f top, sf::Vector2f left,sf::Vector2f right);
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
  int de;
  sf::ConvexShape poly;
  Sierpinski *ptop;
  Sierpinski *pleft;
  Sierpinski *pright;
}; 
