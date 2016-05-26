/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "Player.hpp"
#include "Map.hpp"

//================================================================================
// Contructors
//================================================================================

Player::Player() : Circle() {
    this->m_mainPlayer = false;
    this->m_health = PLAYER_HEALTH;
    this->m_speed = PLAYER_SPEED;
    this->m_map = NULL;
}

Player::Player(bool mainPlayer, float x, float y, Map* map) : Circle(x, y, 15.0f, sf::Color::Black, 2, sf::Color::Blue) {
    this->m_mainPlayer = mainPlayer;
    this->m_health = PLAYER_HEALTH;
    this->m_speed = PLAYER_SPEED;
    this->m_map = map;
    this->m_lastShot.restart();
}

//================================================================================
// Getters
//================================================================================

int Player::getID() {
    return this->m_ID;
}

int Player::getTeamID() {
    return this->m_teamID;
}

int Player::getSpeed() {
    return this->m_speed;
}

int Player::getHealth() {
    return this->m_health;
}

string Player::getName() {
    return this->m_name;
}

Map* Player::getMap() {
    return this->m_map;
}

bool Player::isMainPlayer() {
    return this->m_mainPlayer;
}

//================================================================================
// Getters
//================================================================================

void Player::setID(int ID) {
    this->m_ID = ID;
}

void Player::setTeamID(int teamID) {
    this->m_teamID = teamID;
}

void Player::setName(string name) {
    this->m_name = name;
}

//================================================================================
// Core
//================================================================================

void Player::update(int directionX, int directionY, sf::Time lastFrame) {
    // Calculate player movement
    float movement = this->m_speed * lastFrame.asSeconds();

    // Resolve walking in both directions
    if (directionX && directionY) {
        movement = sqrt(movement);
    }

    // Check collisions in both directions
    this->move(directionX * movement, 0.0f);
    if (this->m_map->checkCollision(this)) {
        this->move(-directionX * movement, 0.0f);
    }
    this->move(0.0f, directionY * movement);
    if (this->m_map->checkCollision(this)) {
        this->move(0.0f, -directionY * movement);
    }
}

void Player::update(sf::Time lastFrame) {
    // Make player predictions about direction
}

void Player::move(float x, float y) {
    this->m_x += x;
    this->m_y += y;
    this->m_shape.setPosition(this->m_x, this->m_y);
}

void Player::shot(float mouseX, float mouseY) {
    if (this->m_lastShot.getElapsedTime().asSeconds() < sf::seconds(0.08f).asSeconds()) return;
    float x = mouseX - this->m_x - this->m_radius;
    float y = mouseY - this->m_y - this->m_radius;
    float length = sqrt(x*x + y*y);
    x /= length;
    y /= length;
    Bullet* bullet = new Bullet(this->m_x + this->m_radius, this->m_y + this->m_radius, x, y, this);
    this->m_map->addBullet(bullet);
    this->m_lastShot.restart();
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(this->m_shape);
}