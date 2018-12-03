#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "SFML/Graphics.hpp"
#include "animation.hpp"
#include "window.hpp"
//#include "collider.hpp"
class Enemy {
public:
    Enemy();
    Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
    ~Enemy();

    void Update(float deltaTime);
    void Draw(Window& window);
    sf::Vector2f GetPosition();
    //Collider GetCollider();
private:

    sf::RectangleShape body;

    float speed;

    //Collider collider;
};

#endif
