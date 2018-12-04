#include "box.hpp"

Box::Box() { }

// El constructor recibe la dimesión y las coordenadas de posición del origen
// (Esquina superior izquierda)
Box::Box(sf::Vector2f size, sf::Vector2f position){
    body.setSize(size);
    body.setPosition(position);

}

Box::~Box() { }

// Dibuja el cuerpo de la caja
void Box::Draw(Window& window) {
    window.Draw(body);
}

// Retorna el cuerpo de la caja. Útil para acceder a los metodos de los dibujables de sfml
sf::RectangleShape Box::GetBody() {
    return body;
}
