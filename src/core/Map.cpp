/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "Map.hpp"
#include "Obstacle.hpp"
#include <vector>

using namespace std;

//================================================================================
// Contructors
//================================================================================

Map::Map() {
    // Creating borders for map
    Obstacle* upper = new Obstacle(0, 0, 1200, 20);
    Obstacle* left = new Obstacle(0, 0, 20, 680);
    Obstacle* right = new Obstacle(1180, 0, 20, 680);
    Obstacle* lower = new Obstacle(0, 600, 1200, 80);

    // Adding borders
    addObstacle(upper);
    addObstacle(left);
    addObstacle(right);
    addObstacle(lower);

    // Reset the clock
    this->m_clock.restart();
    this->m_lastFrame = this->m_clock.getElapsedTime();
}

Map::~Map() {
    // Delete all obstacles
    while (this->m_obstacles.size() > 0) {
        this->m_obstacles.erase(this->m_obstacles.begin());
    }

    // Delete all bullets
    while (this->m_bullets.size() > 0) {
        this->m_bullets.erase(this->m_bullets.begin());
    }

    // Delete all players
    while (this->m_players.size() > 0) {
        this->m_players.erase(this->m_players.begin());
    }
}

//================================================================================
// Adding
//================================================================================

void Map::addPlayer(Player* player) {
    m_players.push_back(player);
}

void Map::addObstacle(Obstacle* obstacle) {
    m_obstacles.push_back(obstacle);
}

void Map::addBullet(Bullet* obstacle) {
    m_bullets.push_back(obstacle);
}

//================================================================================
// Core
//================================================================================

bool Map::checkCollision(Circle* circle) {
    for (int i = 0; i < m_obstacles.size(); i++) {
        if (m_obstacles[i]->checkCollision(circle)) {
            return true;
        }
    }
    return false;
}

void Map::update() {
    // Check user directions
    int directionX = 0, directionY = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) directionX -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) directionX += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) directionY -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) directionY += 1;

    // Update players positions
    for (int i = 0; i < m_players.size(); i++) {
        if (m_players[i]->isMainPlayer()) {
            m_players[i]->update(directionX, directionY, this->m_lastFrame);
        } else {
            m_players[i]->update(this->m_lastFrame);
        }
    }

    // Update bullet positions
    for (int i = 0; i < m_bullets.size(); i++) {
        bool deleteBullet = m_bullets[i]->update(this->m_lastFrame);
        if (deleteBullet) {
            delete m_bullets[i];
            m_bullets.erase(m_bullets.begin() + i);
            i--;
        }
    }

    // Reset the clock
    this->m_lastFrame = this->m_clock.getElapsedTime();
    this->m_clock.restart();
}

void Map::draw(sf::RenderWindow& window) {
    // Draw bullets
    for (int i = 0; i < m_bullets.size(); i++) {
        m_bullets[i]->draw(window);
    }

    // Draw obstacles
    for (int i = 0; i < m_obstacles.size(); i++) {
        m_obstacles[i]->draw(window);
    }
    
    // Draw players
    for (int i = 0; i < m_players.size(); i++) {
        m_players[i]->draw(window);
    }
}