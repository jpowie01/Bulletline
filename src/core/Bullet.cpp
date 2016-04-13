/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "Bullet.hpp"
#include "Player.hpp"
#include "Map.hpp"

//================================================================================
// Constructors
//================================================================================

Bullet::Bullet() {
    this->m_directionX = 0;
    this->m_directionY = 0;
    this->m_speed = BULLET_SPEED;
    this->m_player = NULL;
}

Bullet::Bullet(float x, float y, float directionX, float directionY, Player* player) : Circle(x, y, 2.0f, sf::Color::Black, 1, sf::Color(255, 140, 0)) {
    this->m_directionX = directionX;
    this->m_directionY = directionY;
    this->m_speed = BULLET_SPEED;
    this->m_player = player;
}

//================================================================================
// Core
//================================================================================

bool Bullet::update(sf::Time lastFrame) {
    float movement = this->m_speed * lastFrame.asSeconds();
    float movementX = movement * this->m_directionX;
    float movementY = movement * this->m_directionY;
    this->move(movementX, movementY);
    return this->m_player->getMap()->checkCollision(this);
}

void Bullet::move(float x, float y) {
    this->m_x += x;
    this->m_y += y;
    this->m_shape.setPosition(this->m_x, this->m_y);
}

void Bullet::draw(sf::RenderWindow& window) {
    window.draw(this->m_shape);
}
