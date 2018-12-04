#ifndef ANIM_HPP
#define ANIM_HPP

#include <SFML/Graphics.hpp>
// Clase de animación. Asigna el sprite correcto al jugador iterando
// A través de el sprite sheet. Solo se realiza el cambio al pasar el tiempo
// establecido y obtener una animación uniforme,
class  Animation {
public:
    Animation();
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    ~Animation();
    void Update(int row, float deltaTime, bool moving);
    sf::IntRect getRect();

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
    sf::IntRect uvRect;
    float switchTime;
    float totalTime;
};
#endif
