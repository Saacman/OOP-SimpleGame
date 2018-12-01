#include  "entity.hpp"


Entity::Entity() : forRemoval(false) {
    transform = AddComponent<Transform>();//Cambia la posición del sprite por intervalos
}


void Entity::Awake() {
    for(auto& c : components) c->Awake();
}



void Entity::Start() {
    for(auto& c : components) c->Start();
}


void Entity::Update(float timeDelta) {
    for(auto& c : components) c->Update(timeDelta);
}

void Entity::LateUpdate(float timeDelta) {
    for(auto& c : components) c->LateUpdate(timeDelta);
}

void Entity::Draw(Window& window) {
    for(auto& c : components) c->Draw(window);
}

bool Entity::IsForRemoval() {
    return forRemoval;

}
void Entity::Remove() {
    forRemoval = true;
}
