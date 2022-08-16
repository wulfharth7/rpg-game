#pragma once
#include <SFML/Graphics.hpp>
#include "bullet.h"

class player
{
	public:
		player();
		~player();

		void Draw(sf::RenderWindow& window);
		void update(sf::RenderWindow& window,sf::Vector2f direction, bullet& bullet, float time);
		void load();
		float player_speed = 1.0f; //i'll make it private
		sf::Sprite get_texture();
		int get_x_sheet();
		int get_y_sheet();

	private:
		sf::Texture playerTexture;
		sf::Sprite playerSprite;
		int X_spritesheet = 0;
		int Y_spritesheet = 0;
};

