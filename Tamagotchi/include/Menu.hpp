#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Menu {
private:
    std::vector<std::string> options;       // Opciones del menú
    std::vector<sf::Text> menuTexts;        // Textos que se mostrarán en el menú
    sf::Font font;                          // Fuente para los textos del menú
    sf::Vector2f position;                  // Posición inicial del menú
    float spacing;                          // Espaciado entre las opciones
    int selectedIndex;                      // Índice de la opción seleccionada

public:
    // Constructor
    Menu(const std::vector<std::string>& options, const sf::Vector2f& position, float spacing);

    // Métodos
    void initialize(const std::vector<std::string>& options, const sf::Vector2f& position, float spacing);
    void highlightOption(int index); // Resalta una opción específica
    void draw(sf::RenderWindow& window); // Dibuja el menú en la ventana
};

#endif
