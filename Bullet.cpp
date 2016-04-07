#include "Bullet.hpp"
#include "Player.hpp"
#include "Map.hpp"

Bullet::Bullet() {
    this->_directionX = 0;
    this->_directionY = 0;
    this->_speed = 300;
    this->_player = NULL;
}

Bullet::Bullet(float x, float y, float directionX, float directionY, Player* player) : Circle(x, y, 2.0f, sf::Color::Black, 1, sf::Color(255, 140, 0)) {
    this->_directionX = directionX;
    this->_directionY = directionY;
    this->_speed = 300;
    this->_player = player;
}

bool Bullet::update(sf::Time lastFrame) {
    float movement = this->_speed * lastFrame.asSeconds();
    float movementX = movement * this->_directionX;
    float movementY = movement * this->_directionY;
    this->move(movementX, movementY);
    return this->_player->getMap()->checkCollision(this);
}

void Bullet::move(float x, float y) {
    this->_x += x;
    this->_y += y;
    this->_shape.setPosition(this->_x, this->_y);
}

void Bullet::draw(sf::RenderWindow& window) {
    window.draw(this->_shape);
}
