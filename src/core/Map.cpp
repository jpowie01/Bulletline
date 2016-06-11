/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "Map.hpp"
#include "Obstacle.hpp"
#include "CommonData.hpp"
#include <vector>

using namespace std;

//================================================================================
// Contructors
//================================================================================

Map::Map(CommonData* commonData) {
    // Create background
    background = sf::Sprite(commonData->gameBackground);

    // Creating borders for map
    Obstacle* upper = new Obstacle(0, 0, SCREEN_WIDTH, 20);
    Obstacle* left = new Obstacle(0, 0, 20, SCREEN_HEIGHT);
    Obstacle* right = new Obstacle(SCREEN_WIDTH-20, 0, 20, SCREEN_HEIGHT);
    Obstacle* lower = new Obstacle(0, SCREEN_HEIGHT-80, SCREEN_WIDTH, 80);

    // Adding borders
    addObstacle(upper);
    addObstacle(left);
    addObstacle(right);
    addObstacle(lower);

    // Main player
    mainPlayer = NULL;

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
    sf::Lock lock(this->bulletOperationsMutex);
    m_bullets.push_back(obstacle);
}

//================================================================================
// Getters
//================================================================================

int Map::playersSize() {
    return this->m_players.size();
}

Player* Map::getPlayerAtIndex(int index) {
    return this->m_players[index];
}

Player* Map::getPlayerWithID(int id) {
    for (int i = 0; i < this->m_players.size(); i++) {
        if (this->m_players[i]->getID() == id) {
            return this->m_players[i];
        }
    }
    return NULL;
}

//================================================================================
// Core
//================================================================================

bool Map::checkCollision(Player* player) {
    for (int i = 0; i < m_obstacles.size(); i++) {
        if (m_obstacles[i]->checkCollision(player)) {
            return true;
        }
    }
    return false;
}

bool Map::checkCollision(Bullet* bullet) {
    for (int i = 0; i < m_obstacles.size(); i++) {
        if (m_obstacles[i]->checkCollision(bullet)) {
            return true;
        }
    }
    for (int i = 0; i < m_players.size(); i++) {
        if (m_players[i] != bullet->getPlayer() && m_players[i]->checkCollision(bullet) && !m_players[i]->isDead()) {
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
    if (mainPlayer == NULL) {
        for (int i = 0; i < m_players.size(); i++) {
            if (m_players[i]->isMainPlayer()) {
                mainPlayer = m_players[i];
            }
        }
    }
    mainPlayer->setDirection(directionX, directionY);
    mainPlayer->update(this->m_lastFrame);

    // Update bullet positions
    for (int i = 0; i < m_bullets.size(); i++) {
        bool deleteBullet = m_bullets[i]->update(this->m_lastFrame);
        if (deleteBullet) {
            sf::Lock lock(this->bulletOperationsMutex);
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
    // Draw background
    window.draw(background);

    // Draw bullets
    {
        sf::Lock lock(this->bulletOperationsMutex);
        for (int i = 0; i < m_bullets.size(); i++) {
            m_bullets[i]->draw(window);
        }
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