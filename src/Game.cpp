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
	mouseSprite.scale(sf::Vector2f(0.5, 0.5));

	gameWindow.setMouseCursorVisible(false);
	gameWindow.setFramerateLimit(200);
	player.load();
	
	shaderBlur.loadFromFile("C:/Users/erknn/source/repos/game-engine/src/data/blur.frag", sf::Shader::Type::Fragment);

}

void Game::update(GameState& m_gameState)
{
	timer = clock.restart();
	time = timer.asMilliseconds();
	mouseSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(gameWindow)));

	if (m_gameState == GameState::PLAY) { //when its in the play mode
		newState = GameState::PAUSE;
		shaderBlur.setUniform("blur_radius", 0.0f);//move these away from here

		player.update(gameWindow, time);
		player.eventManager(m_gameState, newState, time); //stack of states could be better i guess, but the game isnt big so i wasn't sure and searched an easier way.
	}
	else if (m_gameState == GameState::PAUSE) { //when its in the pause mode
		newState = GameState::PLAY;
		shaderBlur.setUniform("blur_radius", 0.04f);//move it away from here
		player.eventManager(m_gameState, newState, time);//stack of states could be better i guess, but the game isnt big so i wasn't sure and searched an easier way.
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
