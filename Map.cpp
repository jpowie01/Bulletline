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
    add(upper);
    add(left);
    add(right);
    add(lower);
}


Map::~Map() {
}

void Map::add(Obstacle* obstacle) {
    listOfObstacles.push_back(obstacle);
}

bool Map::checkCollision(Player& player) {
    bool out = false;
    for (int i = 0; i < listOfObstacles.size(); i++) {
        if (listOfObstacles[i]->checkCollision(player)) {
            out = true;
            break;
        }
    }
    return out;
}

void Map::draw(sf::RenderWindow& window) {
    for (int i = 0; i < listOfObstacles.size(); i++) {
        listOfObstacles[i]->draw(window);
    }
}