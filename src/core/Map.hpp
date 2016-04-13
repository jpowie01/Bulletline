/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef Map_hpp
#define Map_hpp

#include <vector>
#include "Circle.hpp"
#include "Player.hpp"
#include "Obstacle.hpp"
#include "Bullet.hpp"
#include "../Definitions.hpp"

using namespace std;

class Map {
private:
    vector <Player*> m_players;
    vector <Obstacle*> m_obstacles;
    vector <Bullet*> m_bullets;
    sf::Time m_lastFrame;
    sf::Clock m_clock;

public:
    // Constructors
    Map();
    ~Map();
    
    // Adding
    void addPlayer(Player* player);
    void addObstacle(Obstacle* obstacle);
    void addBullet(Bullet* obstacle);
    
    // Core
    bool checkCollision(Circle* player);
    void update();
    void draw(sf::RenderWindow& window);
};
#endif

