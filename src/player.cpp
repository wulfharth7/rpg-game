#include "player.h"
#include <iostream>
#include "bullet.h"

player::player():
    maxFireRate(150), fireRateTimer(0)
{
    
}

player::~player()
{
}

void player::Draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < bullets.size(); i++){
        bullets[i].Draw(window);
    };
    window.draw(playerSprite);
    
}

void player::update(sf::RenderWindow& window, float time)
{
    mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    //check walking
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
    //check walking
    fireRateTimer += time;
    //shoot
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fireRateTimer >= maxFireRate) {
        bullets.push_back(bullet(10,10,playerSprite.getPosition(),mousePos));
        int i = bullets.size() - 1;
        //bullets[i].update(window,time);
        fireRateTimer = 0;
    }
    //else {
        for (size_t i = 0; i < bullets.size(); i++)
        {
            bullets[i].update(time);

            //check collision
        }
        //bullet.update(window, false,time);
    //}
    //shoot
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
