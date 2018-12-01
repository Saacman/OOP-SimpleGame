#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>
#include "window.hpp"
#include "r_path.hpp"
#include "input.hpp"
#include "fsm.hpp"
#include "splashscreen.hpp"
#include "gamestate.hpp"

class App {
public:
    App();

    void Update();
    void LateUpdate();
    void Draw();

    bool IsRunning() const;
    void GetdTime();
    void CaptureInput();
private:
    Window window;
    Resources<sf::Texture> textureAllocator;
    sf::Clock clock;
    float dTime;

    ResourcePath path;
    FSM fsm;
};

#endif
