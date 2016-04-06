#include "Map.hpp"
#include "Obstacle.hpp"
#include <vector>

using namespace std;

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
    this->_clock.restart();
    this->_lastFrame = this->_clock.getElapsedTime();
}


Map::~Map() {}

void Map::addPlayer(Player* player) {
    players.push_back(player);
}

void Map::addObstacle(Obstacle* obstacle) {
    obstacles.push_back(obstacle);
}

void Map::addBullet(Bullet* obstacle) {
    bullets.push_back(obstacle);
}

bool Map::checkCollision(Player* player) {
    for (int i = 0; i < obstacles.size(); i++) {
        if (obstacles[i]->checkCollision(player)) {
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
    for (int i = 0; i < players.size(); i++) {
        if (players[i]->isMainPlayer()) {
            players[i]->update(directionX, directionY, this->_lastFrame);
        } else {
            players[i]->update(this->_lastFrame);
        }
    }

    // Update bullet positions
    for (int i = 0; i < bullets.size(); i++) {
        bullets[i]->update(this->_lastFrame);
    }

    // Reset the clock
    this->_lastFrame = this->_clock.getElapsedTime();
    this->_clock.restart();
}

void Map::draw(sf::RenderWindow& window) {
    // Draw players
    for (int i = 0; i < players.size(); i++) {
        players[i]->draw(window);
    }

    // Draw obstacles
    for (int i = 0; i < obstacles.size(); i++) {
        obstacles[i]->draw(window);
    }

    // Draw bullets
    for (int i = 0; i < bullets.size(); i++) {
        bullets[i]->draw(window);
    }
}