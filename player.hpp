#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "SFML/Graphics.hpp"
#include "animation.hpp"
#include "window.hpp"
#include "bitmask.hpp"

// Clase del jugador.
// Define la lógica de la animación e implementa métodos necesarios.

class Player {
public:
    Player();
    Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
    ~Player();

    void Update(float deltaTime);
    void Draw(Window& window);
    sf::Vector2f GetPosition();
    sf::RectangleShape GetBody();
    unsigned int GetDirection();
    void CantMove(int index);
    void CanMove();
    bool Action();

private:

    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    unsigned int direction;
    bool moving;
    BitMask canMove;
    bool action;

};

#endif
