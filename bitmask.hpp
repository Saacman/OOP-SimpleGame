#ifndef BITMASK_HPP
#define BITMASK_HPP

#include <stdint.h>

// Mascara de Bits-
// Cadena de bits en la que podemos almacenar valores booleanos en cada posición.

class BitMask {
public:
    BitMask();
    BitMask(const BitMask& original);

    uint32_t getMask() const;
    void Clear(); // Vacia la mascara

    // Metodos para obtener y modificar bits especificos
    bool getBit(int index) const;
    void setBit(int index); //modifica el bit en la posicion indicada
    void setBit(int index, bool value); //modifica el bit al valor booleano dado
    void clearBit(int index);
private:
    uint32_t m_bits;
};
#endif
