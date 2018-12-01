#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>

class Window {
public:
    Window(const std::string& Name);


    void Update();

    void BeginDraw();
    void Draw(const sf::Drawable& drawable);
    void EndDraw();
    bool IsOpen() const;
    sf::Vector2u GetCentre() const;
private:
    sf::RenderWindow m_target;
};
#endif
