#include "splashscreen.hpp"
SplashScreen::SplashScreen(ResourcePath& path, FSM& fsm, Window& window, Resources<sf::Texture>& textureAllocator)
 : path(path), fsm(fsm), window(window), textureAllocator(textureAllocator), duration(3.f), elapsed(0.f), switchToState(0) { }
//La duracion de la splash screen es 3 segundos

void SplashScreen::init() {
	// Inicializando los recursos de la splash screen
    int textureID = textureAllocator.add(path.Get() + "splash.png");
    if (textureID >= 0) {
        std::shared_ptr<sf::Texture> texture = textureAllocator.get(textureID);
        splashSprite.setTexture(*texture);

        sf::FloatRect spriteSize = splashSprite.getLocalBounds();
        // El origen del sprite es el centro de la imagen
        splashSprite.setOrigin(spriteSize.width * 0.5f,spriteSize.height * 0.5f);

        splashSprite.setScale(0.5f, 0.5f);
        sf::Vector2u wCenter = window.GetCentre();

    	// Coloca el sprite al centro de la pantalla
        splashSprite.setPosition(wCenter.x, wCenter.y);
    }
}

void SplashScreen::activate() {
	// Reinicia el contador al iniciar el estado
	elapsed= 0.f;
}

//PELIGRO: terminate se debe eliminar
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
