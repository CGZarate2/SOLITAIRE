#include "Menu.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Menu::Menu(const std::vector<std::string>& options, const sf::Vector2f& position, float spacing)
    : options(options), position(position), spacing(spacing), selectedIndex(0) {
    if (!font.loadFromFile("./assets/fonts/kirby-classic.ttf")) {
        std::cerr << "Error: No se pudo cargar la fuente." << std::endl;
        return;
    }

    for (size_t i = 0; i < options.size(); ++i) {
        sf::Text optionText;
        optionText.setFont(font);
        optionText.setString(options[i]);
        optionText.setCharacterSize(15);
        optionText.setPosition(position.x, position.y + i * spacing);
        optionText.setFillColor(i == selectedIndex ? sf::Color(250, 126, 51) : sf::Color(255, 229, 64));
        menuTexts.push_back(optionText);
    }
}

void Menu::initialize(const std::vector<std::string>& options, const sf::Vector2f& position, float spacing) {
    this->options = options;
    this->position = position;
    this->spacing = spacing;
    selectedIndex = 0;
    menuTexts.clear();

    for (size_t i = 0; i < options.size(); ++i) {
        sf::Text optionText;
        optionText.setFont(font);
        optionText.setString(options[i]);
        optionText.setCharacterSize(15);
        optionText.setPosition(position.x, position.y + i * spacing);
        optionText.setFillColor(i == selectedIndex ? sf::Color(250, 126, 51) : sf::Color(255, 229, 64));
        menuTexts.push_back(optionText);
    }
}

void Menu::highlightOption(int index) {
    if (index < 0 || index >= static_cast<int>(menuTexts.size())) {
        return;
    }

    menuTexts[selectedIndex].setFillColor(sf::Color(255, 229, 64)); // Restablecer color anterior
    selectedIndex = index;
    menuTexts[selectedIndex].setFillColor(sf::Color(250, 126, 51)); // Resaltar nuevo
}

void Menu::draw(sf::RenderWindow& window) {
    for (const auto& text : menuTexts) {
        window.draw(text);
    }
}