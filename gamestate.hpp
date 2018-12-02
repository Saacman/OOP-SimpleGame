#ifndef STATEAPP_HPP
#define STATEAPP_HPP

#include "window.hpp"
#include "r_path.hpp"
//#include "input.hpp"
#include "state.hpp"
//#include "platform.hpp"
//#include "resources.hpp"
#include "player.hpp"
#include "animation.hpp"
class GameState : public State {
public:
    GameState(ResourcePath& path);

    void init() override;
    void terminate() override;

    void ProcessInput() override;
    void Update(float dTime) override;
    void Draw(Window& window) override;

private:
    Player player;
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    sf::Texture backTexture;
    sf::Sprite backSprite;

    ResourcePath& path;
    //Input input;
};
#endif
