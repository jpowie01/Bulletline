#include "Player.hpp"
#include "Map.hpp"

Player::Player() {
    this->_mainPlayer = false;
    this->_health = 100.0f;
    this->_speed = 150.0f;
    this->_radius = 15.0f;
    this->_x = 0.0f - this->_radius;
    this->_y = 0.0f - this->_radius;
    this->_shape.setRadius(this->_radius);
    this->_shape.setPosition(0.0f, 0.0f);
    this->_shape.setOutlineColor(sf::Color::Black);
    this->_shape.setOutlineThickness(2);
    this->_shape.setFillColor(sf::Color::Blue);
    this->_map = NULL;
}

Player::Player(bool mainPlayer, float x, float y, Map* map) {
    this->_mainPlayer = mainPlayer;
    this->_health = 100.0f;
    this->_speed = 150.0f;
    this->_radius = 15.0f;
    this->_x = x - this->_radius;
    this->_y = y - this->_radius;
    this->_shape.setRadius(this->_radius);
    this->_shape.setPosition(this->_x, this->_y);
    this->_shape.setOutlineColor(sf::Color::Black);
    this->_shape.setOutlineThickness(2);
    this->_shape.setFillColor(sf::Color::Blue);
    this->_map = map;
    this->_lastShot.restart();
}

Player::~Player() {}

bool Player::isMainPlayer() {
    return this->_mainPlayer;
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

Map* Player::getMap() {
    return this->_map;
}

void Player::update(int directionX, int directionY, sf::Time lastFrame) {
    // Calculate player movement
    float movement = this->_speed * lastFrame.asSeconds();

    // Resolve walking in both directions
    if (directionX && directionY) {
        movement = sqrt(movement);
    }

    // Check collisions in both directions
    this->move(directionX * movement, 0.0f);
    if (this->_map->checkCollision(this)) {
        this->move(-directionX * movement, 0.0f);
    }
    this->move(0.0f, directionY * movement);
    if (this->_map->checkCollision(this)) {
        this->move(0.0f, -directionY * movement);
    }
}

void Player::update(sf::Time lastFrame) {
    // Make player predictions about direction
}

void Player::move(float x, float y) {
    this->_x += x;
    this->_y += y;
    this->_shape.setPosition(this->_x, this->_y);
}

void Player::shot(float mouseX, float mouseY) {
    if (this->_lastShot.getElapsedTime().asSeconds() < sf::seconds(0.08f).asSeconds()) return;
    float x = mouseX - this->_x - this->_radius;
    float y = mouseY - this->_y - this->_radius;
    float length = sqrt(x*x + y*y);
    x /= length;
    y /= length;
    Bullet* bullet = new Bullet(this->_x + this->_radius, this->_y + this->_radius, x, y, this);
    this->_map->addBullet(bullet);
    this->_lastShot.restart();
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(this->_shape);
}