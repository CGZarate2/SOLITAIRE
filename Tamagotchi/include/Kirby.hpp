#ifndef KIRBY_HPP
#define KIRBY_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include <string>

class Kirby {
private:
    sf::Sprite sprite;  // Sprite de Kirby
    sf::Texture texture;  // Textura del sprite
    sf::Clock clock;  // Reloj para controlar la animación
    float frameTime;  // Tiempo entre frames
    int currentFrame;  // Frame actual de la animación
    bool isCyclic;  // Si la animación es cíclica o no
    std::vector<sf::IntRect> animationFrames;  // Frames actuales de la animación
    std::map<std::string, std::vector<sf::IntRect>> animations;  // Mapeo de animaciones

public:
    // Constructor
    Kirby(const std::string& texturePath, float frameTime, bool isCyclic);

    // Métodos
    void setAnimationFrames(const std::string& mood, float frameTime, bool isCyclic);
    void setPosition(float x, float y);
    void centerInWindow(const sf::Vector2f& windowSize);
    void update();
    void draw(sf::RenderWindow& window);

    // Getter para los límites del sprite
    sf::FloatRect getGlobalBounds() const;
};

#endif