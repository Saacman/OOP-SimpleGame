#ifndef SPLASH_HPP
#define SPLASH_HPP

#include<SFML/Graphics.hpp>
#include "state.hpp"
#include "fsm.hpp"
#include "r_path.hpp"

// Estado que se muestra al inicio del juego durante 3 segundos.

class SplashScreen : public State
{
public:
    SplashScreen(ResourcePath& path, FSM& fsm, Window& window);

    void init() override;
    void activate() override;

    void SetSwitchToState(unsigned int id);

    void Update(float dTime) override;
    void Draw(Window& window) override;

private:
    sf::Texture splashTexture;
    sf::Sprite splashSprite;
    ResourcePath& path;
    FSM& fsm;
    Window& window;
    unsigned int switchToState;
    float elapsed;
    float duration;
};

#endif
