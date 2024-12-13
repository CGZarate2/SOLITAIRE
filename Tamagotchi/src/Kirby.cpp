#include "Kirby.hpp"
#include <iostream>

// Constructor
Kirby::Kirby(const std::string& texturePath, float frameTime, bool isCyclic)
    : frameTime(frameTime), currentFrame(0), isCyclic(isCyclic)
{
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error: No se pudo cargar la textura desde " << texturePath << std::endl;
        return;
    }
    sprite.setTexture(texture);
    sprite.setScale(3.0f, 3.0f); // Escala de zoom predeterminada

    // Definir las animaciones
    animations["chill"] = {
        sf::IntRect(5, 0, 24, 32),  // Frame 1
        sf::IntRect(29, 0, 24, 32)  // Frame 2
    };

    animations["eating"] = {
        sf::IntRect(5, 130, 25, 32),  // Frame 1
        sf::IntRect(29, 130, 25, 32), // Frame 2
        sf::IntRect(54, 130, 25, 32), // Frame 3
        sf::IntRect(79, 130, 25, 32), // Frame 4
        sf::IntRect(103, 130, 25, 32) // Frame 5
    };

    animations["sleeping"] = {
        sf::IntRect(7, 155, 30, 32),  // Frame 1
        sf::IntRect(32, 155, 30, 32), // Frame 2
        sf::IntRect(59, 155, 25, 32), // Frame 3
        sf::IntRect(86, 155, 25, 32), // Frame 4
        sf::IntRect(113, 155, 25, 32), // Frame 5
        sf::IntRect(140, 155, 33, 35), // Frame 6
        sf::IntRect(168, 155, 25, 32), // Frame 7
        sf::IntRect(197, 155, 30, 32)  // Frame 8
    };

    animations["playing"] = {
        sf::IntRect(5, 255, 30, 32),  // Frame 1
        sf::IntRect(35, 255, 30, 32), // Frame 2
        sf::IntRect(62, 255, 30, 32), // Frame 3
        sf::IntRect(90, 255, 30, 28), // Frame 4
        sf::IntRect(121, 255, 30, 28), // Frame 5
        sf::IntRect(151, 255, 30, 25), // Frame 6
        sf::IntRect(181, 255, 30, 32)  // Frame 7
    };
}

// Configurar los frames de animación
void Kirby::setAnimationFrames(const std::string& mood, float frameTime, bool isCyclic) {
    auto it = animations.find(mood);
    if (it != animations.end()) {
        animationFrames = it->second; // Asignar los frames
        currentFrame = 0;             // Reiniciar al primer frame
        this->frameTime = frameTime;  // Actualizar la velocidad de animación
        this->isCyclic = isCyclic;    // Configurar si es cíclico
        sprite.setTextureRect(animationFrames[currentFrame]); // Configurar el primer frame
    } else {
        std::cerr << "Estado desconocido: " << mood << std::endl;
    }
}

// Establecer posición
void Kirby::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

// Centrar Kirby en la ventana
void Kirby::centerInWindow(const sf::Vector2f& windowSize) {
    sf::FloatRect bounds = sprite.getGlobalBounds(); // Obtener límites del sprite
    float x = (windowSize.x - bounds.width) / 2;
    float y = (windowSize.y - bounds.height) / 2;
    sprite.setPosition(x, y); // Ajustar posición
}

// Obtener límites del sprite
sf::FloatRect Kirby::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}

// Actualizar la animación
void Kirby::update() {
    if (clock.getElapsedTime().asSeconds() >= frameTime && !animationFrames.empty()) {
        if (isCyclic) {
            currentFrame = (currentFrame + 1) % animationFrames.size(); // Siguiente frame cíclico
        } else if (currentFrame < animationFrames.size() - 1) {
            currentFrame++; // Avanza hasta el último frame
        }

        sprite.setTextureRect(animationFrames[currentFrame]); // Actualizar el frame
        clock.restart();                                     // Reinicia el reloj
    }
}

// Dibujar a Kirby
void Kirby::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
