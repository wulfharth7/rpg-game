#include "Game.h"
#include <iostream>
#include <vector>


Game::Game():
	gameWindow(sf::VideoMode(1700, 800), "SFML App")
{
}

Game::~Game()
{
}

void Game::initialize()
{
	mouseTexture.loadFromFile("assets/mouse/textures/cursor.png");
	mouseSprite.setTexture(mouseTexture);
	gameWindow.setMouseCursorVisible(false);
	mouseSprite.scale(sf::Vector2f(0.5, 0.5));
	player.load();
	gameWindow.setFramerateLimit(200);
}

void Game::update()
{
	mouseSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(gameWindow)));
	timer = clock.restart();
	time = timer.asMilliseconds();
	player.update(gameWindow, time);
}

void Game::render()
{
	gameWindow.clear(sf::Color::White);
	player.Draw(gameWindow);
	gameWindow.draw(mouseSprite);
	gameWindow.display();
}

void Game::run()
{
	while (gameWindow.isOpen()) {
		update();
		render();
	}
}
