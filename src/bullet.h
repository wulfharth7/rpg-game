#pragma once
#include <SFML/Graphics.hpp>

class bullet
{
	public:
		bullet(int x, int y, const sf::Vector2f& position, const sf::Vector2f& target, int count);
		~bullet();

		void Draw(sf::RenderWindow& window);
		void update(float time);
		int get_count();
		void set_count(int count);
		
		float bullet_speed = 15.5f; //i'll make it private
		sf::Vector2f get_direction();
		sf::RectangleShape get_rectangleShape();

	private:
		sf::Vector2f direction;
		sf::RectangleShape rectangleShape;
		int count;
};

