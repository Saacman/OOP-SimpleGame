#ifndef SPLASH_HPP
#define SPLASH_HPP

#include<SFML/Graphics.hpp>
#include "state.hpp"
#include "fsm.hpp"
#include "r_path.hpp"
#include "resources.hpp"

class SplashScreen : public State
{
public:
    SplashScreen(ResourcePath& path, FSM& fsm, Window& window, Resources<sf::Texture>& textureAllocator);

    void init() override;
    void terminate() override;
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
    Resources<sf::Texture>& textureAllocator;
    float duration;//Queremos mostrar el estado para ponerlo durante una cantidad de tiempo

    float elapsed;//cuantos estados han sido actualmente visibles

    unsigned int switchToState;//El estado que nosotros queremos transferir cuando el tiempo espira ya
};

#endif
