#include <SFML/Graphics.hpp>
#include "Kirby.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tamagotchi Kirby");

    // Crear instancia de Kirby
    Kirby kirby("assets/images/Kirby.png");

    // Configurar animación inicial
    kirby.setAnimationFrames("playing", 0.2f, true); // Animación "Playing" más rápida y cíclica

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Cambiar animación con teclas
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::C)
                    kirby.setAnimationFrames("chill", 0.3f, true); // Animación "Chill", velocidad normal y cíclica
                else if (event.key.code == sf::Keyboard::E)
                    kirby.setAnimationFrames("eating", 0.4f, true); // Animación "Eating", más lenta y cíclica
                else if (event.key.code == sf::Keyboard::S)
                    kirby.setAnimationFrames("sleeping", 0.5f, false); // Animación "Sleeping", lenta y no cíclica
                else if (event.key.code == sf::Keyboard::P)
                    kirby.setAnimationFrames("playing", 0.2f, true); // Animación "Playing", rápida y cíclica
            }
        }

        // Actualizar animación
        kirby.update();

        // Dibujar a Kirby
        window.clear(sf::Color::Black);
        kirby.draw(window);
        window.display();
    }

    return 0;
}