#ifndef PLATFORM_HPP
#define PLATFORM_HPP
#include <SFML/Graphics.hpp>
//#include "collider.hpp"
#include "window.hpp"

class Box {
public:
    Box();
    Box(sf::Vector2f size, sf::Vector2f position);
    ~Box();

    void Draw(Window& window);
    //Collider GetCollider();
    sf::RectangleShape GetBody();
private:
    sf::RectangleShape body;
    //Collider collider;

};
#endif
