#ifndef RESOURCE_PATH_HPP
#define RESOURCE_PATH_HPP

#include <string>
class ResourcePath {

// Esta clase retorna un String con la dirección de los recursos utilizados.

public:
    ResourcePath();
    //Obtiene el arreglo cadena de la ubicación raíz
    inline const std::string& Get()
    {
        return path;
    }
    // inline const std::string& GetTextures()
    // {
    //     return "Resources/Textures/";
    // }
private:
    std::string path;
};

#endif
