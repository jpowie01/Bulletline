#include "Player.hpp"

Player::Player() {
    this->_health = 100.0f;
    this->_speed = 100.0f;
    this->_radius = 15.0f;
    this->_x = 0.0f - this->_radius;
    this->_y = 0.0f - this->_radius;
    this->_shape.setRadius(this->_radius);
    this->_shape.setPosition(0.0f, 0.0f);
    this->_shape.setOutlineColor(sf::Color::Black);
    this->_shape.setOutlineThickness(2);
    this->_shape.setFillColor(sf::Color::Blue);
}

Player::Player(float x, float y) {
    this->_health = 100.0f;
    this->_speed = 100.0f;
    this->_radius = 15.0f;
    this->_x = x - this->_radius;
    this->_y = y - this->_radius;
    this->_shape.setRadius(this->_radius);
    this->_shape.setPosition(this->_x, this->_y);
    this->_shape.setOutlineColor(sf::Color::Black);
    this->_shape.setOutlineThickness(2);
    this->_shape.setFillColor(sf::Color::Blue);
}

Player::~Player() {
    // TODO: Add destructor
}

int Player::getSpeed() {
    return this->_speed;
}

int Player::getRadius() {
    return this->_radius;
}

float Player::getPositionX() {
    return this->_x;
}

float Player::getPositionY() {
    return this->_y;
}

void Player::move(float x, float y) {
    this->_x += x;
    this->_y += y;
    this->_shape.setPosition(this->_x, this->_y);
}

void Player::shot(float x, float y) {
    // TODO: Implement
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(this->_shape);
}