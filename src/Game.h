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

		void checkCollision();
		void addToListOfHitbox(sf::FloatRect& hitbox, std::vector<sf::FloatRect>& hitboxList);

	private:
		GameState newState;

		sf::RenderWindow gameWindow;
		sf::Texture mouseTexture;
		sf::Sprite mouseSprite;

		std::vector<sf::FloatRect> hitboxList;
		sf::Shader shaderBlur;
		sf::Clock clock;
		sf::Time timer;
		player player;
		float time;
};

