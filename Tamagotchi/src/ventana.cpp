#include <SFML/Graphics.hpp>

int main()
{
sf::RenderWindow window(sf::VideoMode(400, 600), "Prueba");

sf::CircleShape shape(100.f);
shape.setFillColor(sf::Color(0xd2d1e2));
//Localizar centro de ventana
sf::Vector2f center(window.getSize().x / 2.f, window.getSize().y / 2.f);
// Origen de shape en el centro
shape.setOrigin(shape.getRadius(), shape.getRadius());
//Posición de shape en el centro de ventana
shape.setPosition(center);


while (window.isOpen())
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        // Verificar si se ha cerrado la ventana
        if (event.type == sf::Event::Closed)
            window.close();
    }

    // Limpiar la ventana
    window.clear();

    // Dibujar la forma en la ventana
    window.draw(shape);

    // Mostrar la ventana
    window.display();
}
}