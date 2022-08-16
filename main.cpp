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

    while (window.isOpen())
    {
        window.clear(sf::Color::White);
        player.update(window,bullet.get_direction(),bullet);
        player.Draw(window);
        window.display();
    }

}