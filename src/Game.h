#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "player/bullet.h"
#include "player/player.h"
#include "gameState.h"

class Game
{
	public:
		Game();
		~Game();

		void initialize();
		void update(GameState& m_gameState);
		void render(GameState& m_gameState);
		void run();

	private:
		sf::RenderWindow gameWindow;
		sf::Texture mouseTexture;
		sf::Sprite mouseSprite;

		sf::Shader shaderBlur;
		sf::Clock clock;
		sf::Time timer;
		player player;
		float time;
		GameState newState;
};

