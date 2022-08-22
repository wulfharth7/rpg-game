#include "player.h"
#include <iostream>
#include "bullet.h"

int count = 12;
player::player():
    maxFireRate(250), fireRateTimer(0), spriteSheetRate(100), spriteSheetTimer(0)
{
}

player::~player()
{
}

void player::Draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < bullets.size(); i++){
        if (bullets[i].get_count() > 0) {
            bullets[i].Draw(window);
            if (bullets[i].distance > 15500) {
               bullets.erase(bullets.begin() + i);
            }
        }
    };
    window.draw(playerSprite);
}

void player::update(sf::RenderWindow& window, float time, GameState& m_gameState)
{  
    fireRateTimer += time;
    spriteSheetTimer += time;

    eventManager(m_gameState);
    move(time);
    shoot(time, window);    
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

void player::move(float time)
{
    sf::Vector2f position = playerSprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            changeSprite('D', time);
            playerSprite.setTextureRect(sf::IntRect(X_spritesheet * 64, Y_spritesheet * 64, 64, 64));
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0.075, 0) * time * player_speed);
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            changeSprite('A',time);
            playerSprite.setTextureRect(sf::IntRect(X_spritesheet * 64, Y_spritesheet * 64, 64, 64));
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(-0.075, 0) * time * player_speed);
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            changeSprite('W', time);
            playerSprite.setTextureRect(sf::IntRect(X_spritesheet * 64, Y_spritesheet * 64, 64, 64));
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, -0.075) * time * player_speed);
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            changeSprite('S', time);
            playerSprite.setTextureRect(sf::IntRect(X_spritesheet * 64, Y_spritesheet * 64, 64, 64));
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, 0.075) * time * player_speed);
        }
    }
    else {
        changeSprite('x', time);
        playerSprite.setTextureRect(sf::IntRect(X_spritesheet * 64, Y_spritesheet * 64, 64, 64));
    }

}

void player::shoot(float time, sf::RenderWindow& window)
{ 
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fireRateTimer >= maxFireRate) {
        mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        bullets.push_back(bullet(10, 10, playerSprite.getPosition(), mousePos, count));
        count--;
        if (count <= 0) {
            count = 0;
            bullets.clear();
        }
        int i = bullets.size() - 1;
        fireRateTimer = 0;
    }
    for (size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i].update(time);
        bullets[i].movementTimer += time;
        bullets[i].distance = bullets[i].movementTimer * bullets[i].bullet_speed;
        //check collision
    }
}

void player::changeSprite(char direction,float time)
{
    if (direction == 'W') {
        if (spriteSheetTimer >= spriteSheetRate) {
            X_spritesheet = X_spritesheet++;
            Y_spritesheet = 0;
            if (X_spritesheet >= 8) {
                X_spritesheet = 0;
            }
            spriteSheetTimer = 0;
        }
    }else if (direction == 'A') {
        if (spriteSheetTimer >= spriteSheetRate) {
            X_spritesheet = X_spritesheet++;
            Y_spritesheet = 1;
            if (X_spritesheet >= 8) {
                X_spritesheet = 0;
            }
            spriteSheetTimer = 0;
        }
    }else if (direction == 'S') {
        if (spriteSheetTimer >= spriteSheetRate) {
            X_spritesheet = X_spritesheet++;
            Y_spritesheet = 2;
            if (X_spritesheet >= 8) {
                X_spritesheet = 0;
            }
            spriteSheetTimer = 0;
        }
    }else if (direction == 'D') {
        if (spriteSheetTimer >= spriteSheetRate) {
            X_spritesheet = X_spritesheet++;
            Y_spritesheet = 3;
            if (X_spritesheet >= 8) {
                X_spritesheet = 0;
            }
            spriteSheetTimer = 0;
        }
    }
    else {
        X_spritesheet = 0;
    }

}

void player::eventManager(GameState& m_gameState)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        m_gameState = GameState::PAUSE;
    }
}
