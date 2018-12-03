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
#include "enemy.hpp"
#include "fsm.hpp"
class GameState : public State {
public:
    GameState(ResourcePath& Path, FSM& fsm);

    void init() override;
    void terminate() override;
    void Update(float dTime) override;
    void Draw(Window& window) override;
    void SetSwitchToState(unsigned int id);

private:
    Player player;
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    sf::Texture backTexture;
    sf::Sprite backSprite;
    std::vector<Box> walls;
    // Box house1;
    // Box house2;
    // Box house3;
    // Box house4;
    ResourcePath& path;
    Enemy enemy1;
    FSM& fsm;
    unsigned int switchToState;
};
#endif
