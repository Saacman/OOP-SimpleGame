#include "gamestate.hpp"

GameState::GameState(ResourcePath& path, Resources<sf::Texture>& textureAllocator)
 : path(path), textureAllocator(textureAllocator) {}

void GameState::init() {
    std::shared_ptr<Entity> player = std::make_shared<Entity>();
    std::shared_ptr<Entity> background = std::make_shared<Entity>();

    //Añadir textura al jugador
    auto sprite = player->AddComponent<Sprite>();
    sprite->SetTextureAllocator(&textureAllocator);
    sprite->Load(path.Get() + "player.png");
    sprite->setTextureRect(0,0,32,48);

    // Añadir control
    auto movement = player->AddComponent<PlayerControl>();
    movement->SetInput(&input);//no olvidar la posicionalidad de la entrada, de otra manera el personaje no se movera

    auto backsprite = background->AddComponent<Sprite>();
    backsprite->SetTextureAllocator(&textureAllocator);
    backsprite->Load(path.Get() + "background.png");

    player->transform->SetPosition(400, 300);
    // El orden en el que se añaden las entidades es el orden en que se dibujan
    entities.Add(background);
    entities.Add(player);
}
void GameState::terminate() { }

void GameState::ProcessInput() {
    input.Update();
}

void GameState::Update(float dTime) {
    entities.ProcessRemovals();
    entities.ProcessNewEntities();
    entities.Update(dTime);

}

void GameState::LateUpdate(float dTime) {
    entities.LateUpdate(dTime);
}
void GameState::Draw(Window& window) {
    entities.Draw(window);//Esto dibujará nuestra coleccion
}
