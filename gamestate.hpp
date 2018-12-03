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
    void SetSwitchToState(unsigned int id) override;

private:
    Player player;
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    sf::Texture backTexture;
    sf::Sprite backSprite;
    std::vector<Box> walls;
    std::vector<Box> switchBox;
    ResourcePath& path;
    Enemy enemy1;
    FSM& fsm;
    unsigned int switchToState;
};
#endif
