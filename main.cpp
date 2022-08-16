#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    sf::RectangleShape bullet(sf::Vector2f(50, 25));
    bullet.setPosition(sf::Vector2f(50, 50));
    sf::Vector2f direction;
    int XIndex = 0;
    int YIndex = 0;

    if (playerTexture.loadFromFile("assets/player/textures/spritesheet.png")) {
        std::cout << "player image loaded" << std::endl;
        playerSprite.setTexture(playerTexture);

        
        playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));

    }
    else {
        std::cout << "player image couldn't load" << std::endl;
    }

    
    while (window.isOpen())
    {

        sf::Vector2f position = playerSprite.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            XIndex = XIndex++;
            YIndex = 3;
            if (XIndex >= 8) {
                XIndex = 0;
            }
            playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));

            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0.075, 0));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            XIndex = XIndex++;
            YIndex = 1;
            if (XIndex >= 8) {
                XIndex = 0;
            }
            playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(-0.075, 0));
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            XIndex = XIndex++;
            YIndex = 0;
            if (XIndex >= 8) {
                XIndex = 0;
            }
            playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, -0.075));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            XIndex = XIndex++;
            YIndex = 2;
            if (XIndex >= 8) {
                XIndex = 0;
            }
            playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, 0.075));
        }
        else {
            XIndex = 0;
            playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2f localPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            //sf::Vector2f vec = sf::Vector2f(localPosition);
            direction = bullet.getPosition();
            direction = localPosition - bullet.getPosition();
            bullet.setPosition(bullet.getPosition() + direction* 0.0003f);
        }
        else {
            bullet.setPosition(bullet.getPosition() + direction * 0.0003f);
        }
        window.clear();
        window.draw(playerSprite);
        window.draw(bullet);
        window.display();
    }

}