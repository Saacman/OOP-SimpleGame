#ifndef STATEAPP_HPP
#define STATEAPP_HPP

#include "window.hpp"
#include "r_path.hpp"
#include "state.hpp"
#include "box.hpp"
#include "player.hpp"
#include "animation.hpp"
#include "fsm.hpp"

// Clase del "primer nivel" o primer pantalla de juego.
// Se deriva de state para ser administrada por la fsm
// En ella se declaran e inicializan los elementos del estado

class GameState : public State {
public:
    GameState(ResourcePath& Path, FSM& fsm);

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
