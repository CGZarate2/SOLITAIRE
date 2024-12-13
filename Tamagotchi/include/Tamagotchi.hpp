#ifndef TAMAGOTCHI_HPP
#define TAMAGOTCHI_HPP

#include "Kirby.hpp"
#include "Menu.hpp"
#include "AudioManager.hpp"

class Tamagotchi {
private:
    Kirby kirby;
    Menu menu;
    AudioManager audioManager;
    int currentState;

public:
    Tamagotchi();
    void initialize();
    void handleInput();
    void update();
    void draw(sf::RenderWindow& window);
};

#endif
