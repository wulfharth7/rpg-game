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
	if (m_gameState == GameState::PLAY) {
		shaderBlur.setUniform("blur_radius", 0.0f);
		timer = clock.restart();
		time = timer.asMilliseconds();
		player.update(gameWindow, time);
		newState = GameState::PAUSE;
		player.eventManager(m_gameState, newState, time); //stack of states could be better i guess, but the game isnt big so i wasn't sure and searched an easier way.
		mouseSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(gameWindow)));
	}
	else if (m_gameState == GameState::PAUSE) {
		timer = clock.restart();
		time = timer.asMilliseconds();
		newState = GameState::PLAY;
		player.eventManager(m_gameState, newState, time);//stack of states could be better i guess, but the game isnt big so i wasn't sure and searched an easier way.
		//clean here
		shaderBlur.loadFromFile("C:/Users/erknn/source/repos/game-engine/src/data/blur.frag", sf::Shader::Type::Fragment);
		shaderBlur.setUniform("blur_radius", 0.04f);
		//clean here
	};
}

void Game::render(GameState& m_gameState)
{
	gameWindow.clear(sf::Color::White);
	player.Draw(gameWindow,shaderBlur);
	gameWindow.draw(mouseSprite,&shaderBlur);
	if (m_gameState == GameState::PAUSE) {
		
	}else if (m_gameState == GameState::MENU) {

	}
	gameWindow.display();
}

void Game::run()
{
	GameState m_gameState = GameState::PLAY;
	while (gameWindow.isOpen()){
		update(m_gameState);
		render(m_gameState);
	}
}
