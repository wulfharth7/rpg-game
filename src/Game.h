#pragma once
#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "player.h"
#include "gameState.h"

class Game
{
	public:
		Game();
		~Game();

		void initialize();
		void update(GameState& m_gameState);
		void render();
		void run();

	private:
		sf::RenderWindow gameWindow;
		sf::Texture mouseTexture;
		sf::Sprite mouseSprite;//(mouseTexture);

		sf::Clock clock;
		sf::Time timer;
		player player;
		float time;
};

