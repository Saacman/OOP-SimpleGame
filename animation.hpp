#ifndef ANIM_HPP
#define ANIM_HPP

#include <SFML/Graphics.hpp>

class  Animation {
public:
    Animation();
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    ~Animation();

    void Update(int row, float deltaTime);

    sf::IntRect getRect();

   private:
      sf::Vector2u imageCount;
      sf::Vector2u currentImage;
      sf::IntRect uvRect;
      float switchTime;
      float totalTime;
};

#endif
