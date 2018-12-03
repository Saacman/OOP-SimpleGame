#ifndef APP_HPP
#define APP_HPP

#include "window.hpp"
#include "r_path.hpp"
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
private:
    Window window;

    sf::Clock clock;
    float dTime;

    ResourcePath path;
    FSM fsm;
};

#endif
