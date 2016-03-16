#include "Obstacle.h"
#include <SFML/Graphics.hpp>


Obstacle::Obstacle() {
	this->_obstacle.setSize(sf::Vector2f(0.0f, 0.0f));
	this->_obstacle.setPosition(sf::Vector2f(0.0f, 0.0f));
	this->_obstacle.setOutlineColor(sf::Color::White);
	this->_obstacle.setFillColor(sf::Color::White);
	this->_x = 0.0f;
	this->_y = 0.0f;
	this->_width = 0.0f;
	this->_lenght = 0.0f;
}


Obstacle::~Obstacle() {
	//TO DO: Add destructor
}

Obstacle::Obstacle(float x, float y, float width, float lenght) {
	this->_obstacle.setSize(sf::Vector2f(width, lenght));
	this->_obstacle.setPosition(sf::Vector2f(x, y));
	this->_obstacle.setOutlineColor(sf::Color::White);
	this->_obstacle.setFillColor(sf::Color::White);
	this->_x = x;
	this->_y = y;
	this->_width = width;
	this->_lenght = lenght;
}

void Obstacle::draw(sf::RenderWindow& window) {
	window.draw(this->_obstacle);
}