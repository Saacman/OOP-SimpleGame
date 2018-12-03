#ifndef INPUT_HPP
#define INPUT_HPP

#include "SFML/Graphics.hpp"
#include "bitmask.hpp"

class Input {
public:
    enum class Key {
        None = 0,
        Left = 1,
        Right = 2,
        Up = 3,
        Down = 4,
        Esc = 5
    };
    bool isKPressed(Key code); // Retorna true si la tecla esta presionada
    bool isKDown(Key code); // Retorna true si la tecla fue presionada
    bool isKUp(Key code); // Retorna true si la tecla dejo de ser presionada
    void Update();
private:
    BitMask m_keys;
    BitMask m_lastKeys;
};
#endif
