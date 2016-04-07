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

bool Obstacle::checkCollision(Circle* circle) {
    float x = circle->getX();
    float y = circle->getY();
    int r = circle->getRadius();

    float distanceX = fabs(x - this->_width/2 - this->_x + r);
    float distanceY = fabs(y - this->_height/2 - this->_y + r);

    if (distanceX > this->_width/2 + r) return false;
    if (distanceY > this->_height/2 + r) return false;

    if (distanceX <= this->_width/2) return true;
    if (distanceY <= this->_height/2) return true;

    float cornerDistance = (distanceX - this->_width/2) * (distanceX - this->_width/2) +
                           (distanceY - this->_height/2) * (distanceY - this->_height/2);

    return (cornerDistance <= r * r);
}

void Obstacle::draw(sf::RenderWindow& window) {
    window.draw(this->_obstacle);
}