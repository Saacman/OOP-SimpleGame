#include "splashscreen.hpp"
SplashScreen::SplashScreen(ResourcePath& path, FSM& fsm, Window& window) : path(path), fsm(fsm),
window(window), switchToState(0), elapsed(0.f), duration(3.f) { }
//La duracion de la splash screen es 3 segundos

void SplashScreen::init() {
	// Inicializando los recursos de la splash screen

    splashTexture.loadFromFile(path.Get() + "splash.png");
    splashSprite.setTexture(splashTexture);
    sf::FloatRect spriteSize = splashSprite.getLocalBounds();

	// El origen del sprite es el centro de la imagen
    splashSprite.setOrigin(spriteSize.width * 0.5f,spriteSize.height * 0.5f);

    splashSprite.setScale(0.5f, 0.5f);

    sf::Vector2u wCenter = window.GetCentre();

	// Coloca el sprite al centro de la pantalla
    splashSprite.setPosition(wCenter.x, wCenter.y);
}

void SplashScreen::activate() {
	// Reinicia el contador al iniciar el estado
	elapsed= 0.f;
}

void SplashScreen::terminate() { }

void SplashScreen::SetSwitchToState(unsigned int id) {
	// Almacena el id del estado al que pasará al terminar
    switchToState = id;
}

void SplashScreen::Update(float dTime)
{
    elapsed += dTime;

    if(elapsed >= duration) fsm.SwitchTo(switchToState);
}

void SplashScreen::Draw(Window& window)
{
    window.Draw(splashSprite);
}
