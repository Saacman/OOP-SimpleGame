#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "SFML/Graphics.hpp"
#include "animation.hpp"
#include "window.hpp"
#include "collider.hpp"
class Player {
public:
    Player();
    Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
    ~Player();

    void Update(float deltaTime);
    void Draw(Window& window);
    sf::Vector2f GetPosition();
    //Collider GetCollider();
private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    unsigned int lastRow;
    bool moving;
};

#endif
