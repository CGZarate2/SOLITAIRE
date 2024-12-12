#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
//Variable para switch-case   
int opcion = 1;
//Delay para validar el cambio en opcion dentro de switch-case
sf::Clock delayClock;
    float delay = 0.5f; //Segundos

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

//Pantalla (Espacio donde se ve el juego)
sf::RectangleShape pantalla(sf::Vector2f(350, 250));
    pantalla.setFillColor(sf::Color(200, 200, 200));
    pantalla.setPosition(125,175);
//Márgenes de pantalla
sf::RectangleShape mpantalla(sf::Vector2f(358, 258));
    mpantalla.setFillColor(sf::Color::Black);
    mpantalla.setPosition(121,171);

// Menú en la pantalla
sf::Text alimentar;
    alimentar.setFont(font);
    alimentar.setString("Alimentar");
    alimentar.setCharacterSize(15);
    alimentar.setPosition(130,405);
sf::Text dormir;
    dormir.setFont(font);
    dormir.setString("Dormir");
    dormir.setCharacterSize(15);
    dormir.setPosition(250,405);
sf::Text jugar;
    jugar.setFont(font);
    jugar.setString("Jugar");
    jugar.setCharacterSize(15);
    jugar.setPosition(350,405);
sf::Text salir;
    salir.setFont(font);
    salir.setString("Salir");
    salir.setCharacterSize(15);
    salir.setPosition(425,405);

//Fondo de menú en pantalla
sf::RectangleShape fmenu(sf::Vector2f(350, 25));
    fmenu.setFillColor(sf::Color(54, 54, 52));
    fmenu.setPosition(125,400);

// Texto botón S
sf::Text S;
    S.setFont(font);
    S.setString("S");
    S.setCharacterSize(40);
    S.setFillColor(sf::Color::Black);
    S.setPosition(187,500);

// Texto botón D
sf::Text D;
    D.setFont(font);
    D.setString("D");
    D.setCharacterSize(40);
    D.setFillColor(sf::Color::Black);
    D.setPosition(387,500);

//Base azul del Tamagotchi
sf::CircleShape ovalo(250.f);
    ovalo.setScale(1.0f, 1.25f);
    ovalo.setFillColor(sf::Color(20, 96, 164));
//Posición del ovalo en el centro de la ventana
    ovalo.setPosition(center.x - ovalo.getRadius(), center.y - ovalo.getRadius()* ovalo.getScale().y);

//Botón seleccionar
sf::CircleShape bsel(25);
    bsel.setPosition(175,500);

//Botón derecha
sf::CircleShape bder(25);
    bder.setPosition(375,500);


while (window.isOpen())
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        // Verificar si se ha cerrado la ventana
        if (event.type == sf::Event::Closed){
            window.close();
        }
    }

    //Acciones según el valor de opcion
    switch(opcion){
        case 1://Alimentar
            alimentar.setFillColor(sf::Color(250, 126, 51));
            dormir.setFillColor(sf::Color(255, 229, 64));
            jugar.setFillColor(sf::Color(255, 229, 64));
            salir.setFillColor(sf::Color(255, 229, 64));
            //Cambio de color de botones al ser presionados
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                bsel.setFillColor(sf::Color(250, 126, 51));
            } else {
                bsel.setFillColor(sf::Color(255, 229, 64));
            }
                
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                bder.setFillColor(sf::Color(250, 126, 51));
                if(delayClock.getElapsedTime().asSeconds() >= delay){
                    opcion++;
                    delayClock.restart();
                }
            } else {
                bder.setFillColor(sf::Color(255, 229, 64));
            }
            break;
        case 2://Dormir
            dormir.setFillColor(sf::Color(250, 126, 51));
            alimentar.setFillColor(sf::Color(255, 229, 64));
            jugar.setFillColor(sf::Color(255, 229, 64));
            salir.setFillColor(sf::Color(255, 229, 64));
            //Cambio de color de botones al ser presionados
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                bsel.setFillColor(sf::Color(250, 126, 51));
            } else {
                bsel.setFillColor(sf::Color(255, 229, 64));
            }
                
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                bder.setFillColor(sf::Color(250, 126, 51));
                if(delayClock.getElapsedTime().asSeconds() >= delay){
                    opcion++;
                    delayClock.restart();
                }
            } else {
                bder.setFillColor(sf::Color(255, 229, 64));
            }
            break;
        case 3://Jugar
            jugar.setFillColor(sf::Color(250, 126, 51));
            alimentar.setFillColor(sf::Color(255, 229, 64));
            dormir.setFillColor(sf::Color(255, 229, 64));
            salir.setFillColor(sf::Color(255, 229, 64));
            //Cambio de color de botones al ser presionados
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                bsel.setFillColor(sf::Color(250, 126, 51));
            } else {
                bsel.setFillColor(sf::Color(255, 229, 64));
            }
                
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                bder.setFillColor(sf::Color(250, 126, 51));
                if(delayClock.getElapsedTime().asSeconds() >= delay){
                    opcion++;
                    delayClock.restart();
                }
            } else {
                bder.setFillColor(sf::Color(255, 229, 64));
            }
            break;
        case 4://Salir
            salir.setFillColor(sf::Color(250, 126, 51));
            alimentar.setFillColor(sf::Color(255, 229, 64));
            dormir.setFillColor(sf::Color(255, 229, 64));
            jugar.setFillColor(sf::Color(255, 229, 64));
            //Cambio de color de botones al ser presionados
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                bsel.setFillColor(sf::Color(250, 126, 51));
                window.close();
            } else {
                bsel.setFillColor(sf::Color(255, 229, 64));
            }
                
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                bder.setFillColor(sf::Color(250, 126, 51));
                if(delayClock.getElapsedTime().asSeconds() >= delay){
                    opcion++;
                    delayClock.restart();
                }
            } else {
                bder.setFillColor(sf::Color(255, 229, 64));
            }
            break;
        default://Si no es 1,2,3 ó 4
        alimentar.setFillColor(sf::Color(255, 229, 64));
        dormir.setFillColor(sf::Color(255, 229, 64));
        jugar.setFillColor(sf::Color(255, 229, 64));
        salir.setFillColor(sf::Color(255, 229, 64));
        opcion = 1;
    }

    // Limpiar la ventana
    window.clear();
    //Óvalo
    window.draw(ovalo);
    //Pantalla
    window.draw(mpantalla);
    window.draw(pantalla);
    window.draw(fmenu);
    window.draw(alimentar);
    window.draw(dormir);
    window.draw(jugar);
    window.draw(salir);
    
    //Botones
    window.draw(bsel);
    window.draw(bder);
    //Texto botones
    window.draw(S);
    window.draw(D);
    // Mostrar la ventana
    window.display();
}
}