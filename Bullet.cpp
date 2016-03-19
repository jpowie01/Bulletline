#include "Bullet.hpp"

Bullet::Bullet() {
    this->_x = 0;
    this->_y = 0;
    this->_directionX = 0;
    this->_directionY = 0;
    this->_speed = 300;
    this->_radius = 2;
    this->_shape.setRadius(this->_radius);
    this->_shape.setPosition(0.0f, 0.0f);
    this->_shape.setOutlineColor(sf::Color::Black);
    this->_shape.setOutlineThickness(1);
    this->_shape.setFillColor(sf::Color(255, 140, 0));
    this->_player = NULL;
}

Bullet::Bullet(float x, float y, float directionX, float directionY, Player* player) {
    this->_x = x;
    this->_y = y;
    this->_directionX = directionX;
    this->_directionY = directionY;
    this->_speed = 300;
    this->_radius = 2;
    this->_shape.setRadius(this->_radius);
    this->_shape.setPosition(x, y);
    this->_shape.setOutlineColor(sf::Color::Black);
    this->_shape.setOutlineThickness(1);
    this->_shape.setFillColor(sf::Color(255, 140, 0));
    this->_player = player;
}

Bullet::~Bullet() {}

void Bullet::update(sf::Time lastFrame) {
    float movement = this->_speed * lastFrame.asSeconds();
    float movementX = movement * this->_directionX;
    float movementY = movement * this->_directionY;
    this->move(movementX, movementY);
}

void Bullet::move(float x, float y) {
    this->_x += x;
    this->_y += y;
    this->_shape.setPosition(this->_x, this->_y);
}

void Bullet::draw(sf::RenderWindow& window) {
    window.draw(this->_shape);
}
