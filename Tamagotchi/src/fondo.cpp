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
bizq.setFillColor(sf::Color::Yellow);
bizq.setPosition(175.f,500.f);

//Botón seleccionar
sf::CircleShape bsel(25.f);
bsel.setFillColor(sf::Color::Yellow);
bsel.setPosition(275.f,550.f);

//Botón derecha
sf::CircleShape bder(25.f);
bder.setFillColor(sf::Color::Yellow);
bder.setPosition(375.f,500.f);

//Pantalla (Espacio donde se ve el juego)
sf::RectangleShape pantalla(sf::Vector2f(350.f, 250.f));
pantalla.setFillColor(sf::Color(0xc7ebbc));
pantalla.setPosition(125.f,175.f);


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
    //Pantalla
    window.draw(pantalla);
    //Botones
    window.draw(bizq);
    window.draw(bsel);
    window.draw(bder);
    // Mostrar la ventana
    window.display();
}
}