#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "src/bullet.h"
#include "src/player.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1700, 800), "SFML works!");
    player player;
    player.load();
    bullet bullet(50, 50);
    sf::Clock clock;
    sf::Time timer;
    float time;
    window.setFramerateLimit(200);
    while (window.isOpen())
    {
        timer = clock.restart();
        time = timer.asMilliseconds();
        window.clear(sf::Color::White);
        player.update(window,bullet.get_direction(),bullet,time);
        player.Draw(window);
        window.display();
    }

}