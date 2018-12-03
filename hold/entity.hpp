#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <SFML/Graphics.hpp>


class Entity {
   // Objeto fisico
   public:
      Entity();
      void draw(Window &window );
      virtual ~Entity();

      sf::RectangleShape getRectangle() const;
      sf::RectangleShape& setRectangle();
   protected:
      sf::RectangleShape bbox;
      sf::Sprite sprite;
      sf::Text text;
};

#endif
