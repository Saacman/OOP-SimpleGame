#include "window.hpp"

//Constructor con el nombre de la ventana
Window::Window(const std::string& Name) : m_target( sf::VideoMode(800,600), Name, sf::Style::Default ) {
    // Window es un objeto no copiable
    //m_target = sf::RenderWindow( sf::VideoMode(800,600), Name, sf::Style::Titlebar );
    m_target.setVerticalSyncEnabled(true);
}

//Verifica si se debe cerrar la ventana
void Window::Update() {
    sf::Event event;
    //pollEvent regresa el estado en que se encuentra el evento
    if( m_target.pollEvent(event)){
        //Sale cuando el evento esta cerrado
        if (event.type == sf::Event::Closed) m_target.close();
    }
    // Salir al presionar esc
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) m_target.close();

}

//Deja la ventana en blanco, la limpia
void Window::BeginDraw() {
    m_target.clear(sf::Color::White);
}

//Metodo de mutación que carga el dibujable
void Window::Draw(const sf::Drawable& drawable) {
    m_target.draw(drawable);
}

//Función que muestra los dibujos en pantalla
void Window::EndDraw() {
    m_target.display();
}

//Función de consulta-retorna la bandera de abierto
bool Window::IsOpen() const {
    return m_target.isOpen();
}

//Función que regresa el centro de la ventana
sf::Vector2u Window::GetCentre() const
{
    sf::Vector2u size = m_target.getSize();

    return sf::Vector2u(size.x / 2, size.y / 2);
}
