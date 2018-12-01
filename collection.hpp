#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include <memory>
#include <vector>
#include "entity.hpp"
// Clase a través de la cual se administra
// todas las entidades en el estado de juego
class Collection {
public:
    void Add(std::shared_ptr<Entity> entity);

    void Update(float dTime);
    void LateUpdate(float dTime);
    void Draw(Window& window);

    void ProcessNewEntities();
    void ProcessRemovals();

private:
    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<std::shared_ptr<Entity>> newEntities;
    // Se definen dos colecciones, en la primera se tienen todos los objetos a procesar
    // En la segunda las entidades nuevas, posteriormente se pasan a la primera
};
#endif
