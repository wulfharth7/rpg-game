#include "enemy.h"
#include <iostream>
enemy::enemy()
{
}

enemy::~enemy()
{
}

void enemy::Draw(sf::RenderWindow& window, sf::Shader& blurState)
{
    window.draw(sprite, &blurState);
}

void enemy::update(sf::RenderWindow& window, float time)
{
}

void enemy::load()
{
    int X_spritesheet = 0;
    int Y_spritesheet = 0;
    if (texture.loadFromFile("assets/player/textures/spritesheet.png")) {
        std::cout << "player image loaded" << std::endl;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(X_spritesheet * 64, Y_spritesheet * 64, 64, 64));
    }
    else {
        std::cout << "player image couldn't load" << std::endl;
    }
}
