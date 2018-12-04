#ifndef PLATFORM_HPP
#define PLATFORM_HPP
#include <SFML/Graphics.hpp>
#include "window.hpp"

// Clase de Caja. Con ella podemos definir paredes, o cajas de cambio de estado.

class Box {
public:
    Box();
    Box(sf::Vector2f size, sf::Vector2f position);
    ~Box();
    void Draw(Window& window);
    sf::RectangleShape GetBody();
private:
    sf::RectangleShape body;


};
#endif
