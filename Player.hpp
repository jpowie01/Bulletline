#ifndef Player_hpp
#define Player_hpp

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <cmath>

#include "Circle.hpp"

class Map;

class Player : public Circle {
private:
    bool _mainPlayer;
    int _speed;
    int _health;
    Map* _map;
    sf::Clock _lastShot;

public:
    Player();
    Player(bool mainPlayer, float x, float y, Map* map);
    bool isMainPlayer();
    int getSpeed();
    Map* getMap();
    void update(int directionX, int directionY, sf::Time lastFrame);
    void update(sf::Time lastFrame);
    void move(float x, float y);
    void shot(float mouseX, float mouseY);
    void draw(sf::RenderWindow& window);
};

#endif
