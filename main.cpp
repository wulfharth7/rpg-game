#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    sf::RectangleShape bullet(sf::Vector2f(50, 25));
    bullet.setPosition(sf::Vector2f(100, 100));

    if (playerTexture.loadFromFile("assets/player/textures/spritesheet.png")) {
        std::cout << "player image loaded" << std::endl;
        playerSprite.setTexture(playerTexture);

        int XIndex = 0;
        int YIndex = 0;

        playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));

    }
    else {
        std::cout << "player image couldn't load" << std::endl;
    }

    
    while (window.isOpen())
    {

        sf::Vector2f position = playerSprite.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(1, 0));
        } if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));
        } if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, -1));
        } if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, 1));
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i localPosition = sf::Mouse::getPosition(window);
            sf::Vector2f vec = sf::Vector2f(localPosition);
            sf::Vector2f direction = vec - bullet.getPosition();
            bullet.setPosition(bullet.getPosition() + direction*0.001f);
        }
        window.clear();
        window.draw(playerSprite);
        window.draw(bullet);
        window.display();
    }

}