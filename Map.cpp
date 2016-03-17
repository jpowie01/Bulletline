#include "Map.hpp"
#include "Obstacle.hpp"
#include <vector>
using namespace std;


Map::Map() {
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