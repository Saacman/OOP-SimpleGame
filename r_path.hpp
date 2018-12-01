#ifndef RESOURCE_PATH_HPP
#define RESOURCE_PATH_HPP

#include <string>
class ResourcePath {
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
