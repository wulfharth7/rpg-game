#include "Game.h"
#include <iostream>
#include <vector>
#include "gameState.h"

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

void Game::update(GameState& m_gameState)
{
	switch (m_gameState) {
		case GameState::PLAY:
			mouseSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(gameWindow)));
			timer = clock.restart();
			time = timer.asMilliseconds();
			player.update(gameWindow, time, m_gameState);
			break;
		case GameState::PAUSE:
			//
			break;
		case GameState::MENU:
			//
			break;
	};
	
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
	GameState m_gameState = GameState::PLAY;
	while (gameWindow.isOpen()) {
		update(m_gameState);
		render();
	}
}
