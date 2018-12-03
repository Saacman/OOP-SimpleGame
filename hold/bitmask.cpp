#include "bitmask.hpp"

BitMask::BitMask() : m_bits(0) { }

BitMask::BitMask(const BitMask& original) {
    //Copia de la mascara de bits que se manda
    m_bits = original.getMask();
}

//Metodo de acceso, retorna la mascara de bits
uint32_t BitMask::getMask() const {
    return m_bits;
}

//Limpia la mascara de bits
void BitMask::Clear() {
    m_bits = 0;
}

//Devuelve verdadero si bit en pos = 1, sino falso.
bool BitMask::getBit(int index) const {
    //retorna un valor boleano de la operación and, indica si hay un  bit en esa posición
    return (m_bits & (1 << index)) != 0;
}

// coloca un 1 en la posicion indicada
void BitMask::setBit(int index) {
    m_bits = m_bits | (1 << index);
}

// Establece el bit en la posición especificada en 1 o 0 (verdadero o falso).
void BitMask::setBit(int index, bool value) {
    // Se puede definir este metodo con dos metodos anteriores
    if (value) setBit(index);
    else clearBit(index);
}

//Limpia el bit con el complemento de index
void BitMask::clearBit(int index) {
    m_bits = m_bits & ~(1 << index);
}
