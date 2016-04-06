#ifndef Player_hpp
#define Player_hpp

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <cmath>

class Map;

class Player {
private:
    sf::CircleShape _shape;
    bool _mainPlayer;
    float _x, _y;
    int _speed;
    int _health;
    int _radius;
    Map* _map;

public:
    Player();
    Player(bool mainPlayer, float x, float y, Map* map);
    ~Player();
    bool isMainPlayer();
    int getSpeed();
    int getRadius();
    float getPositionX();
    float getPositionY();
    void update(int directionX, int directionY, sf::Time lastFrame);
    void update(sf::Time lastFrame);
    void move(float x, float y);
    void shot(float x, float y);
    void draw(sf::RenderWindow& window);
};

#endif
