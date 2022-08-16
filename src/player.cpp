#include "player.h"
#include <iostream>
#include "bullet.h"
void shoot(sf::RenderWindow& window, sf::Vector2f direction, bullet& bullet);
void walk(sf::Sprite playerSprite, int X_spritesheet, int Y_spritesheet);

player::player()
{

}

player::~player()
{
}

void player::Draw(sf::RenderWindow& window)
{
    window.draw(playerSprite);
}

void player::update(sf::RenderWindow& window, sf::Vector2f direction, bullet& bullet, float time)
{
    sf::Vector2f position = playerSprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        X_spritesheet = X_spritesheet++;
        Y_spritesheet = 3;
        if (X_spritesheet >= 8) {
            X_spritesheet = 0;
        }
        playerSprite.setTextureRect(sf::IntRect(X_spritesheet * 64, Y_spritesheet * 64, 64, 64));

        sf::Vector2f position = playerSprite.getPosition();
        playerSprite.setPosition(position + sf::Vector2f(0.075, 0) * time * player_speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        X_spritesheet = X_spritesheet++;
        Y_spritesheet = 1;
        if (X_spritesheet >= 8) {
            X_spritesheet = 0;
        }
        playerSprite.setTextureRect(sf::IntRect(X_spritesheet * 64, Y_spritesheet * 64, 64, 64));
        sf::Vector2f position = playerSprite.getPosition();
        playerSprite.setPosition(position + sf::Vector2f(-0.075, 0) * time * player_speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        X_spritesheet = X_spritesheet++;
        Y_spritesheet = 0;
        if (X_spritesheet >= 8) {
            X_spritesheet = 0;
        }
        playerSprite.setTextureRect(sf::IntRect(X_spritesheet * 64, Y_spritesheet * 64, 64, 64));
        sf::Vector2f position = playerSprite.getPosition();
        playerSprite.setPosition(position + sf::Vector2f(0, -0.075) * time * player_speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        X_spritesheet = X_spritesheet++;
        Y_spritesheet = 2;
        if (X_spritesheet >= 8) {
            X_spritesheet = 0;
        }
        playerSprite.setTextureRect(sf::IntRect(X_spritesheet * 64, Y_spritesheet * 64, 64, 64));
        sf::Vector2f position = playerSprite.getPosition();
        playerSprite.setPosition(position + sf::Vector2f(0, 0.075) * time * player_speed);
    }
    /*else {
        X_spritesheet = 0;
        playerSprite.setTextureRect(sf::IntRect(X_spritesheet * 64, Y_spritesheet * 64, 64, 64));
    }*/
    //shoot
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        bullet.update(window, true,time);
    }
    else {
        bullet.update(window, false,time);
    }
    bullet.Draw(window); //ill create a list for bullets
}

void player::load()
{
    if (playerTexture.loadFromFile("assets/player/textures/spritesheet.png")) {
        std::cout << "player image loaded" << std::endl;
        playerSprite.setTexture(playerTexture);
        playerSprite.setTextureRect(sf::IntRect(X_spritesheet * 64, Y_spritesheet * 64, 64, 64));
    }
    else {
        std::cout << "player image couldn't load" << std::endl;
    }
}

void shoot(sf::RenderWindow& window, sf::Vector2f direction, bullet& bullet)
{
    
}

void walk(sf::Sprite playerSprite, int X_spritesheet, int Y_spritesheet) {
    
}
