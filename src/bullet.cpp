#include "bullet.h"

bullet::bullet(int x, int y)
{
	rectangleShape.setSize(sf::Vector2f(x, y));
	rectangleShape.setPosition(sf::Vector2f(10,10));
	rectangleShape.setFillColor(sf::Color::Yellow);
}

bullet::~bullet()
{
}

void bullet::Draw(sf::RenderWindow& window)
{
	window.draw(rectangleShape);
}

void bullet::update(sf::RenderWindow& window,bool shooted)
{
	if (shooted == true) {
		sf::Vector2f localPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		sf::Vector2f vec = sf::Vector2f(localPosition);

		direction = rectangleShape.getPosition();
		direction = localPosition - rectangleShape.getPosition();
		rectangleShape.setPosition(rectangleShape.getPosition() + direction * 0.0003f);
	}
	else {
		rectangleShape.setPosition(rectangleShape.getPosition() + direction * 0.0003f);
	}
	
}

void bullet::load()
{
}

sf::Vector2f bullet::get_direction()
{
	return direction;
}

sf::RectangleShape bullet::get_rectangleShape()
{
	return rectangleShape;
}
