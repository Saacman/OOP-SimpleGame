#ifndef COLLIDER_HPP
#define COLLIDER_HPP
#include<SFML/Graphics.hpp>
class Collider{

public:
   Collider(sf::RectangleShape& body);
   ~Collider();

   void Move(float dx, float dy);
   bool CheckCollider(Collider other,float push);

   sf::Vector2f GetPosition();
   sf::Vector2f GetHalfSize ();

private:
    sf::RectangleShape& body;

};
#endif
