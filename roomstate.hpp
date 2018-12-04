#ifndef STATEROOM_HPP
#define STATEROOM_HPP

#include "window.hpp"
#include "r_path.hpp"
#include "state.hpp"
#include "box.hpp"
#include "player.hpp"
#include "animation.hpp"
#include "fsm.hpp"

// Clase de estado "habitación".
// Se deriva de la clase State e implementa un override de dichas class.

class RoomState : public State {
public:
    RoomState(ResourcePath& Path, FSM& fsm);

    void init() override;
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
    FSM& fsm;
    unsigned int switchToState;
};
#endif
