#pragma once
#include <SFML/Graphics.hpp>

class bullet
{
	public:
		bullet(int x, int y);
		~bullet();

		void Draw(sf::RenderWindow& window);
		void update(sf::RenderWindow& window, bool shooted,float time);
		void load();
		float bullet_speed = 1.0f; //i'll make it private
		sf::Vector2f get_direction();
		sf::RectangleShape get_rectangleShape();

	private:
		sf::Vector2f direction;
		sf::RectangleShape rectangleShape;
		int count;
};

