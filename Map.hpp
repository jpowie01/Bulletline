#ifndef Map_hpp
#define Map_hpp

#include <vector>
#include "Obstacle.hpp"
using namespace std;

class Map {
private:
    vector <Obstacle*> listOfObstacles;

public:
    Map();
    ~Map();
    void add(Obstacle* obstacle);
    void draw(sf::RenderWindow& window);
};
#endif

