#ifndef PLATFORM_HPP
#define PLATFORM_HPP
#include <SFML/Graphics.hpp>
#include "collider.hpp"
#include "window.hpp"

class Platform {
public:
    Platform();
    Platform(sf::Vector2f size, sf::Vector2f position);
    ~Platform();

    void Draw(Window& window);
    Collider GetCollider();

private:
    sf::RectangleShape body;

};
#endif
