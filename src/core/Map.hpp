/*
 * Bulletline
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

class CommonData;

class Map {
private:
    sf::Mutex bulletOperationsMutex;
    vector <Player*> m_players;
    vector <Obstacle*> m_obstacles;
    vector <Bullet*> m_bullets;
    sf::Time m_lastFrame;
    sf::Clock m_clock;
    CommonData* commonData;
    sf::Sprite background;

public:
    // Constructors
    Map(CommonData* commonData);
    ~Map();
    
    // Adding
    void addPlayer(Player* player);
    void addObstacle(Obstacle* obstacle);
    void addBullet(Bullet* obstacle);

    // Getters
    int playersSize();
    Player* mainPlayer;
    Player* getPlayerAtIndex(int index);
    Player* getPlayerWithID(int id);

    // Core
    bool checkCollision(Player* player);
    bool checkCollision(Bullet* bullet);
    void update();
    void draw(sf::RenderWindow& window);
};
#endif

