#ifndef Map_hpp
#define Map_hpp

#include <vector>
#include "Player.hpp"
#include "Obstacle.hpp"
#include "Bullet.hpp"

using namespace std;

class Map {
private:
    vector <Player*> players;
    vector <Obstacle*> obstacles;
    vector <Bullet*> bullets;
    sf::Time _lastFrame;
    sf::Clock _clock;

public:
    Map();
    ~Map();
    void addPlayer(Player* player);
    void addObstacle(Obstacle* obstacle);
    void addBullet(Bullet* obstacle);
    bool checkCollision(Player* player);
    void update();
    void draw(sf::RenderWindow& window);
};
#endif

