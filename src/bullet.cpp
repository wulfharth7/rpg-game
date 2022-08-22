#include "bullet.h"
#include <iostream>


bullet::bullet(int x, int y, const sf::Vector2f& position, const sf::Vector2f& target,int count)
{
	this->count = count;
	rectangleShape.setSize(sf::Vector2f(x, y));
	rectangleShape.setPosition(position.x+30,position.y+30);
	rectangleShape.setFillColor(sf::Color::Blue);

	sf::Vector2f trial = target - position;
	sf::Vector2f betterVector;
	float m = std::sqrt(trial.x * trial.x + trial.y * trial.y);
	betterVector.x = trial.x / m;
	betterVector.y = trial.y / m;
	direction.x = betterVector.x;
	direction.y = betterVector.y;
}

bullet::~bullet()
{
}

void bullet::Draw(sf::RenderWindow& window)
{
	window.draw(rectangleShape);
}

void bullet::update(float time)
{
	rectangleShape.setPosition(rectangleShape.getPosition() + direction * 0.03f * time * bullet_speed);
}

int bullet::get_count()
{
	return count;
}

void bullet::set_count(int count)
{
	this->count = count;
}

sf::Vector2f bullet::get_direction()
{
	return direction;
}

sf::RectangleShape bullet::get_rectangleShape()
{
	return rectangleShape;
}
