#ifndef STATEAPP_HPP
#define STATEAPP_HPP

#include "window.hpp"
#include "r_path.hpp"
//#include "input.hpp"
#include "state.hpp"
#include "box.hpp"
#include "player.hpp"
#include "animation.hpp"
//#include "collider.hpp"
class GameState : public State {
public:
    GameState(ResourcePath& Path);

    void init() override;
    void terminate() override;
    void Update(float dTime) override;
    void Draw(Window& window) override;

private:
    Player player;
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    sf::Texture backTexture;
    sf::Sprite backSprite;
    Box house1;
    Box house2;
    Box house3;
    Box house4;
    ResourcePath& path;
};
#endif
