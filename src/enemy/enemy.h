#pragma once
#include <SFML/Graphics.hpp>

class enemy
{
	public:
		enemy();
		~enemy();

		void Draw(sf::RenderWindow& window, sf::Shader& blurState);
		void update(sf::RenderWindow& window, float time);
		void load();
	
	private:
		sf::Texture texture;
		sf::Sprite sprite;
};

