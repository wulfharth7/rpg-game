#pragma once
#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "../gameState.h"

class player
{
	public:
		player();
		~player();

		void Draw(sf::RenderWindow& window, sf::Shader& blurState);
		void update(sf::RenderWindow& window, float time);
		void load();
		void move(float time);
		void shoot(float time, sf::RenderWindow& window);
		void changeSprite(char direction, float time);
		void eventManager(GameState& m_gameState, GameState& newState, float time);
		float player_speed = 2.5f; //i'll make it private
		sf::Vector2f mousePos;

	private:
		sf::RectangleShape boundingRectangle;
		sf::Texture playerTexture;
		sf::Sprite playerSprite;
		int X_spritesheet = 0;
		int Y_spritesheet = 0;
		std::vector<bullet> bullets;
		float maxFireRate;
		double fireRateTimer;
		float spriteSheetRate;
		float spriteSheetTimer;
		float eventRate;
		float eventTimer;
};

