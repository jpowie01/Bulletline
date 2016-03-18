#include "Obstacle.hpp"
#include <SFML/Graphics.hpp>

Obstacle::Obstacle() {
    this->_obstacle.setSize(sf::Vector2f(0.0f, 0.0f));
    this->_obstacle.setPosition(sf::Vector2f(0.0f, 0.0f));
    this->_obstacle.setOutlineColor(sf::Color::White);
    this->_obstacle.setFillColor(sf::Color::White);
    this->_x = 0.0f;
    this->_y = 0.0f;
    this->_width = 0.0f;
    this->_height = 0.0f;
}

Obstacle::~Obstacle() {
}

Obstacle::Obstacle(float x, float y, float width, float height) {
    this->_obstacle.setSize(sf::Vector2f(width, height));
    this->_obstacle.setPosition(sf::Vector2f(x, y));
    this->_obstacle.setOutlineColor(sf::Color::Black);
    this->_obstacle.setFillColor(sf::Color(92,92,92));
    this->_x = x;
    this->_y = y;
    this->_width = width;
    this->_height = height;
}

void Obstacle::draw(sf::RenderWindow& window) {
    window.draw(this->_obstacle);
}