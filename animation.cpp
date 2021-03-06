#include "animation.hpp"

// Constructor por defecto
Animation::Animation() : switchTime(0.0), totalTime(0.0) {}

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) :
imageCount(imageCount), switchTime(switchTime), totalTime(0.0f){
    currentImage.x=0;
    uvRect.width  = texture -> getSize().x / float(imageCount.x);
    uvRect.height = texture -> getSize().y / float(imageCount.y);
}

// Destructor
Animation::~Animation(){ }

// Update actualiza el frame de acuerdo a la posición recibida, el tiempo transcurrido
// y la bandera de movimiento.
void Animation::Update(int row, float deltaTime, bool moving){
    currentImage.y = row;
    totalTime += deltaTime;
    if(totalTime >= switchTime){
        totalTime -= switchTime;
        currentImage.x++;
        if (currentImage.x >= imageCount.x) currentImage.x = 0;
    }
    if (!moving) currentImage.x = 0;
    uvRect.top  = currentImage.y * uvRect.height;
    uvRect.left = currentImage.x * abs(uvRect.width);

}

// Retorna el rectangulo entero sobre el que trabaja
sf::IntRect Animation::getRect() {
    return uvRect;
}
