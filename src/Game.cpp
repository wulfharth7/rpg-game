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
			timer = clock.restart();
			time = timer.asMilliseconds();
			player.update(gameWindow, time);
			newState = GameState::PAUSE;
			player.eventManager(m_gameState, newState,time); //stack of states could be better i guess, but the game isnt big so i wasn't sure and searched an easier way.
			mouseSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(gameWindow)));
			break;
		case GameState::PAUSE:
			timer = clock.restart();
			time = timer.asMilliseconds();
			newState = GameState::PLAY;
			player.eventManager(m_gameState, newState,time);//stack of states could be better i guess, but the game isnt big so i wasn't sure and searched an easier way.
			break;
		case GameState::MENU:
			break;
	};
}

void Game::render(GameState& m_gameState)
{
	if (m_gameState == GameState::PLAY) {
		gameWindow.clear(sf::Color::White);
		player.Draw(gameWindow);
		gameWindow.draw(mouseSprite);
		gameWindow.display();
	}else if (m_gameState == GameState::PAUSE) {

	}else if (m_gameState == GameState::MENU) {

	}
}

void Game::run()
{
	GameState m_gameState = GameState::PLAY;
	while (gameWindow.isOpen()){
		update(m_gameState);
		render(m_gameState);
	}
}
