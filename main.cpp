#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "src/bullet.h"
#include "src/player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1700, 800), "SFML works!");
    window.setMouseCursorVisible(false);
    sf::Texture texture;
    texture.loadFromFile("assets/mouse/textures/cursor.png");
    sf::Sprite sprite(texture);
    sprite.scale(sf::Vector2f(0.65, 0.65));

    player player;
    player.load();
    sf::Clock clock;
    sf::Time timer;
    float time;
    window.setFramerateLimit(200);
    while (window.isOpen())
    {
        sprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        timer = clock.restart();
        time = timer.asMilliseconds();
        window.clear(sf::Color::White);
        player.update(window,time);
        player.Draw(window);
        window.draw(sprite);
        window.display();
    }
}