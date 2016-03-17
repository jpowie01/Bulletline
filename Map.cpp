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

void Map::draw(sf::RenderWindow& window) {
    for (int i = 0; i < listOfObstacles.size(); i++) {
        listOfObstacles[i]->draw(window);
    }
}
