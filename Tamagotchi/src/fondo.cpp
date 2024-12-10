#include <SFML/Graphics.hpp>

int main()
{
sf::RenderWindow window(sf::VideoMode(600, 700), "Prueba");
//Localizar centro de ventana
sf::Vector2f center(window.getSize().x / 2.f, window.getSize().y / 2.f);


sf::CircleShape ovalo(250.f);
ovalo.setScale(1.0f, 1.25f);
ovalo.setFillColor(sf::Color::Blue);
//Posición del ovalo en el centro de la ventana
ovalo.setPosition(center.x - ovalo.getRadius(), center.y - ovalo.getRadius()* ovalo.getScale().y);

//Botón izquierda
sf::CircleShape bizq(25.f);
bizq.setFillColor(sf::Color(0xb2dff3));
bizq.setPosition(150.f,500.f);

//Botón derecha
sf::CircleShape bder(25.f);
bder.setFillColor(sf::Color(0xb2dff3));
bder.setPosition(450.f,500.f);


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
    //Óvalo
    window.draw(ovalo);
    //Botones
    window.draw(bizq);
    window.draw(bder);
    // Mostrar la ventana
    window.display();
}
}