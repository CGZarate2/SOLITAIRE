#include <SFML/Graphics.hpp>

int main()
{
sf::RenderWindow window(sf::VideoMode(600, 700), "Tamagotchi");
//Localizar centro de ventana
sf::Vector2f center(window.getSize().x / 2.f, window.getSize().y / 2.f);

//Fuente del texto
sf::Font font;
    if (!font.loadFromFile("./assets/fonts/kirby-classic.ttf"))
    {
        // Manejar el error si no se puede cargar la fuente
        return -1;
    }

// Texto botón A
sf::Text A;
    A.setFont(font);
    A.setString("A");
    A.setCharacterSize(40);
    A.setFillColor(sf::Color::Black);
    A.setPosition(187.f,500.f);

// Texto botón S
sf::Text S;
    S.setFont(font);
    S.setString("S");
    S.setCharacterSize(40);
    S.setFillColor(sf::Color::Black);
    S.setPosition(287.f,550.f);

// Texto botón D
sf::Text D;
    D.setFont(font);
    D.setString("D");
    D.setCharacterSize(40);
    D.setFillColor(sf::Color::Black);
    D.setPosition(387.f,500.f);

//Base azul del Tamagotchi
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
    //Color cuando sea presionado
    //bsel.setFillColor(sf::Color(0Xffae57));
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
    //Texto botones
    window.draw(A);
    window.draw(S);
    window.draw(D);
    // Mostrar la ventana
    window.display();
}
}