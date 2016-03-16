#include "Player.hpp"

Player::Player() {
    this->_x = 0.0f;
    this->_y = 0.0f;
    this->_health = 100.0f;
    this->_speed = 60.0f;
    this->_radius = 15.0f;
    this->_shape.setRadius(this->_radius);
    this->_shape.setPosition(0.0f, 0.0f);
    this->_shape.setOutlineColor(sf::Color::Black);
    this->_shape.setOutlineThickness(2);
    this->_shape.setFillColor(sf::Color::Blue);
}

Player::Player(float x, float y) {
    this->_x = x;
    this->_y = y;
    this->_health = 100.0f;
    this->_speed = 60.0f;
    this->_radius = 15.0f;
    this->_shape.setRadius(this->_radius);
    this->_shape.setPosition(this->_x, this->_y);
    this->_shape.setOutlineColor(sf::Color::Black);
    this->_shape.setOutlineThickness(2);
    this->_shape.setFillColor(sf::Color::Blue);
}

Player::~Player() {
    // TODO: Add destructor
}

void Player::move(float x, float y) {
    this->_x += x;
    this->_y += y;
    this->_shape.setPosition(this->_x, this->_y);
    // TODO: Check collision
}

void Player::shot(float x, float y) {
    // TODO: Implement
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(this->_shape);
}

int Player::getSpeed() {
    return this->_speed;
}