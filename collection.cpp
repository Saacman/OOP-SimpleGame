#include "collection.hpp"
// Añadir una entidad a la colección
void Collection::Add(std::shared_ptr<Entity> entity)
{
    newEntities.push_back(entity);
}

// Iterar en los miembros de la colección para actualizarlos
void Collection::Update(float dTime)
{
    for(const auto& ent : entities)
    {
        ent->Update(dTime);
    }
}

void Collection::LateUpdate(float dTime)
{
    for(const auto& ent : entities)
    {
        ent->LateUpdate(dTime);
    }
}

// Iterar en los miembros de la colección para dibujarlos en la ventana
void Collection::Draw(Window& window)
{
    for(const auto& ent : entities)
    {
        ent->Draw(window);
    }
}

// Procesar las nuevas entidades de manera provisional.
void Collection::ProcessNewEntities()
{
    if (newEntities.size() > 0) {
        for (const auto& ent : newEntities) ent->Awake();

        for (const auto& ent : newEntities) ent->Start();

        entities.assign(newEntities.begin(), newEntities.end()); //Asignar los nuevos contenidos al vector

        newEntities.clear();
    }
}
// Eliminar las entidades de acuerdo a la bandera
void Collection::ProcessRemovals()
{
    auto iterator = entities.begin();
    while (iterator != entities.end())
    {
        auto ent = **iterator;

        if (ent.IsForRemoval())
        {
            iterator = entities.erase(iterator);
        }
        else
        {
            ++iterator;
        }
    }
}
