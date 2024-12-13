#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <SFML/Graphics.hpp>

class Background {
private:
    sf::RectangleShape screen;
    sf::RectangleShape margin;
    sf::CircleShape frame;

public:
    Background();
    void initialize(const sf::Vector2f& screenSize, const sf::Color& frameColor);
    void draw(sf::RenderWindow& window);
};

#endif
