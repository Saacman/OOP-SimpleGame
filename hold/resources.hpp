#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <map>
#include <memory>
// Esta clase admnistra todos los recursos necesarios
// Texturas, Fuentes, Sonido.
// El objetivo es pasar por referencia un recurso en lugar #ifndef SYMBOL
// Cargarlo de nuevo cada vez que sea necesario
template<typename T>
class Resources {
public:
    int add(const std::string& filePath) {
        auto hold = elements.find(filePath);

        // Verificar si el recurso ya se encuentra en el map.
        // Si es así, etornar su ID
        if (hold != elements.end()) return hold->second.first;

        //Si la carga es incorrecta regresar un error
        std::shared_ptr<T> element = std::make_shared<T>();
        if(!element->loadFromFile(filePath)) return -1;

        // finalmente si no se entraron en los otros dos cas, se inserta en el map
        elements.insert(std::make_pair(filePath, std:: make_pair(currentID, element)));

        // Retornamos el ID asignado y lo incrementamos para el siguiente elemento
        return currentID++;
    }

    void remove(int id) {
        // Itera en los elementos de map. Si el id coincide, lo elimina del map.
        for (auto hold = elements.begin(); hold != elements.end(); ++hold) {
            if ( hold->second.first == id ) elements.erase(hold->first);
        }
    }

    std::shared_ptr<T> get(int id) {
        // Itera en los elementos de map. Si el id coincide, retorna un puntero al elemento.
        for (auto hold = elements.begin(); hold != elements.end(); ++hold) {
            if (hold->second.first == id ) return hold->second.second;
        }
        // Si no encuentra el elemento:
        return nullptr;
    }
private:
    int currentID;
    std::map<std::string, std::pair<int, std::shared_ptr<T>>> elements;
};
#endif
