/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "Player.hpp"
#include "Map.hpp"
#include "Bullet.hpp"

//================================================================================
// Contructors
//================================================================================

Player::Player() : Circle() {
    // Data
    this->m_dead = false;
    this->m_mainPlayer = false;
    this->m_health = PLAYER_HEALTH;
    this->m_speed = PLAYER_SPEED;
    this->m_map = NULL;
    
    // Create health bar
    this->healthBarBackground.setFillColor(sf::Color(60, 60, 60));
    this->healthBarBackground.setOutlineColor(sf::Color::Black);
    this->healthBarBackground.setOutlineThickness(1.0f);
    this->healthBarBackground.setSize(sf::Vector2f(30, 4));
    this->healthBarStatus.setFillColor(sf::Color::Red);
    this->healthBarStatus.setSize(sf::Vector2f(30, 4));
}

Player::Player(bool mainPlayer, float x, float y, Map* map) : Circle(x, y, 15.0f, sf::Color::Black, 2, sf::Color::Blue) {
    // Data
    this->m_dead = false;
    this->m_mainPlayer = mainPlayer;
    this->m_health = PLAYER_HEALTH;
    this->m_speed = PLAYER_SPEED;
    this->m_map = map;
    this->m_lastShot.restart();
    
    // Create health bar
    this->healthBarBackground.setFillColor(sf::Color(60, 60, 60));
    this->healthBarBackground.setOutlineColor(sf::Color::Black);
    this->healthBarBackground.setOutlineThickness(1.0f);
    this->healthBarBackground.setSize(sf::Vector2f(30, 4));
    this->healthBarStatus.setFillColor(sf::Color::Red);
    this->healthBarStatus.setSize(sf::Vector2f(30, 4));
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

int Player::getDirectionX() {
    return this->m_directionX;
}

int Player::getDirectionY() {
    return this->m_directionY;
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

bool Player::isDead() {
    return this->m_dead;
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

void Player::setHealth(int health) {
    this->m_health = health;
    if (this->m_health <= 0) {
        this->m_health = 0;
        this->setDead();
    }
}

void Player::setName(string name) {
    this->m_name = name;
}

void Player::setDirection(int directionX, int directionY) {
    this->m_directionX = directionX;
    this->m_directionY = directionY;
}

void Player::setDead() {
    this->m_dead = true;
}

//================================================================================
// Core
//================================================================================

void Player::update(sf::Time lastFrame) {
    // Calculate player movement
    float movement = this->m_speed * lastFrame.asSeconds();

    // Resolve walking in both directions
    if (this->m_directionX && this->m_directionY) {
        movement = sqrt(movement);
    }

    // Check collisions in both directions
    this->move(this->m_directionX * movement, 0.0f);
    if (this->m_map->checkCollision(this)) {
        this->move(-this->m_directionX * movement, 0.0f);
    }
    this->move(0.0f, this->m_directionY * movement);
    if (this->m_map->checkCollision(this)) {
        this->move(0.0f, -this->m_directionY * movement);
    }
}

void Player::move(float x, float y) {
    this->m_x += x;
    this->m_y += y;
    this->m_shape.setPosition(this->m_x, this->m_y);
}

Bullet* Player::shot(float mouseX, float mouseY) {
    if (this->isDead()) return NULL;
    if (this->m_lastShot.getElapsedTime().asSeconds() < sf::seconds(0.08f).asSeconds()) return NULL;
    float x = mouseX - this->m_x - this->m_radius;
    float y = mouseY - this->m_y - this->m_radius;
    float length = sqrt(x*x + y*y);
    x /= length;
    y /= length;
    Bullet* bullet = new Bullet(this->m_x + this->m_radius, this->m_y + this->m_radius, x, y, this);
    this->m_map->addBullet(bullet);
    this->m_lastShot.restart();
    return bullet;
}

void Player::draw(sf::RenderWindow& window) {
    if (!this->isDead()) {
        // Draw player
        window.draw(this->m_shape);
        
        // Draw health bar under each player
        healthBarBackground.setPosition(getX(), getY() - 11.0f);
        healthBarStatus.setPosition(getX(), getY() - 11.0f);
        healthBarStatus.setSize(sf::Vector2f(getHealth() / 100.0f * 30.f, 4));
        window.draw(healthBarBackground);
        window.draw(healthBarStatus);
    }
}