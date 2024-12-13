#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Kirby.hpp"
#include <iostream>

int main() {
    // Crear una ventana de 600x700 píxeles
    sf::RenderWindow window(sf::VideoMode(600, 700), "Tamagotchi Kirby");

    // Variable para controlar las opciones del menú
    int opcion = 1; // Inicialmente está en "Alimentar"
    sf::Clock delayClock;
    float delay = 0.5f; // Delay entre cambios de opciones

    // Crear instancia de Kirby y configurarlo en modo "chill"
    Kirby kirby("./assets/images/Kirby.png", 0.3f, true);
    kirby.setAnimationFrames("chill", 0.3f, true);

    // Ajustar la posición inicial de Kirby dentro de la pantalla
    kirby.setPosition(250, 250);

    // Cargar los audios
    sf::Music malimentar, mdormir, mjugar, msalir;
    if (!malimentar.openFromFile("./assets/music/come.ogg")) {
        std::cerr << "Error: No se pudo cargar el audio 'come.ogg'." << std::endl;
        return -1;
    }
    if (!mdormir.openFromFile("./assets/music/sape.ogg")) {
        std::cerr << "Error: No se pudo cargar el audio 'sape.ogg'." << std::endl;
        return -1;
    }
    if (!mjugar.openFromFile("./assets/music/pelea.ogg")) {
        std::cerr << "Error: No se pudo cargar el audio 'pelea.ogg'." << std::endl;
        return -1;
    }
    if (!msalir.openFromFile("./assets/music/sad-violin.ogg")) {
        std::cerr << "Error: No se pudo cargar el audio 'sad-violin.ogg'." << std::endl;
        return -1;
    }

    // Configuración del fondo y elementos
    sf::RectangleShape pantalla(sf::Vector2f(350, 250));
    pantalla.setFillColor(sf::Color(200, 200, 200));
    pantalla.setPosition(125, 175);

    sf::RectangleShape mpantalla(sf::Vector2f(358, 258));
    mpantalla.setFillColor(sf::Color::Black);
    mpantalla.setPosition(121, 171);

    sf::Font font;
    if (!font.loadFromFile("./assets/fonts/kirby-classic.ttf")) {
        std::cerr << "Error: No se pudo cargar la fuente." << std::endl;
        return -1;
    }

    // Menú en pantalla
    sf::Text alimentar, dormir, jugar, salir;
    alimentar.setFont(font);
    alimentar.setString("Alimentar");
    alimentar.setCharacterSize(15);
    alimentar.setPosition(130, 405);

    dormir.setFont(font);
    dormir.setString("Dormir");
    dormir.setCharacterSize(15);
    dormir.setPosition(250, 405);

    jugar.setFont(font);
    jugar.setString("Jugar");
    jugar.setCharacterSize(15);
    jugar.setPosition(350, 405);

    salir.setFont(font);
    salir.setString("Salir");
    salir.setCharacterSize(15);
    salir.setPosition(425, 405);

    sf::RectangleShape fmenu(sf::Vector2f(350, 25));
    fmenu.setFillColor(sf::Color(54, 54, 52));
    fmenu.setPosition(125, 400);

    // Base azul del Tamagotchi
    sf::CircleShape ovalo(250.f);
    ovalo.setScale(1.0f, 1.25f);
    ovalo.setFillColor(sf::Color(20, 96, 164));
    ovalo.setPosition(window.getSize().x / 2 - ovalo.getRadius(), window.getSize().y / 2 - ovalo.getRadius() * ovalo.getScale().y);

    // Botones S y D
    sf::CircleShape bsel(25);
    bsel.setPosition(175, 500);

    sf::CircleShape bder(25);
    bder.setPosition(375, 500);

    sf::Text S, D;
    S.setFont(font);
    S.setString("S");
    S.setCharacterSize(40);
    S.setFillColor(sf::Color::Black);
    S.setPosition(187, 500);

    D.setFont(font);
    D.setString("D");
    D.setCharacterSize(40);
    D.setFillColor(sf::Color::Black);
    D.setPosition(387, 500);

    // Bucle principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Cerrar la ventana si el usuario hace clic en el botón de cierre
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Controlar opciones con el botón D
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            bder.setFillColor(sf::Color(250, 126, 51));
            if (delayClock.getElapsedTime().asSeconds() >= delay) {
                opcion = (opcion % 4) + 1; // Cambia a la siguiente opción (cíclico)
                delayClock.restart();
            }
        } else {
            bder.setFillColor(sf::Color(255, 229, 64));
        }

        // Ejecutar acción con el botón S
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            bsel.setFillColor(sf::Color(250, 126, 51));
            switch (opcion) {
                
                case 1:
                    kirby.setAnimationFrames("eating", 0.1f, false); // Alimentar
                    kirby.setPosition(250, 250);
                    malimentar.play();
                    break;
                
                case 2:
                    kirby.setAnimationFrames("sleeping", 0.1f, false); // Dormir
                    kirby.setPosition(250, 250);
                    mdormir.play();
                    break;
                case 3:
                    kirby.setAnimationFrames("playing", 0.1f, true); // Jugar
                    kirby.setPosition(245, 260);
                    mjugar.play();
                    break;
                case 4:
                    msalir.play(); // Salir
                    while (msalir.getStatus() == sf::SoundSource::Playing) {}
                    window.close();
                    break;
            }
            
        } else {
            bsel.setFillColor(sf::Color(255, 229, 64));
        }

        // Actualizar la animación de Kirby
        kirby.update();
        
        // Resaltar opción actual
        alimentar.setFillColor(opcion == 1 ? sf::Color(250, 126, 51) : sf::Color(255, 229, 64));
        dormir.setFillColor(opcion == 2 ? sf::Color(250, 126, 51) : sf::Color(255, 229, 64));
        jugar.setFillColor(opcion == 3 ? sf::Color(250, 126, 51) : sf::Color(255, 229, 64));
        salir.setFillColor(opcion == 4 ? sf::Color(250, 126, 51) : sf::Color(255, 229, 64));

        // Dibujar todo en la ventana
        window.clear();
        window.draw(ovalo);             // Fondo azul ovalado
        window.draw(mpantalla);         // Márgenes de la pantalla
        window.draw(pantalla);          // Pantalla central
        window.draw(fmenu);             // Fondo del menú
        window.draw(alimentar);         // Texto: Alimentar
        window.draw(dormir);            // Texto: Dormir
        window.draw(jugar);             // Texto: Jugar
        window.draw(salir);             // Texto: Salir
        window.draw(bsel);              // Botón S
        window.draw(bder);              // Botón D
        window.draw(S);                 // Texto S
        window.draw(D);                 // Texto D
        kirby.draw(window);             // Dibujar a Kirby
        window.display();               // Mostrar todo
    }

    return 0;
}