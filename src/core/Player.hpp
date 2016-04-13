/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef Player_hpp
#define Player_hpp

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <cmath>

#include "Circle.hpp"
#include "../Definitions.hpp"

class Map;

class Player : public Circle {
private:
    bool m_mainPlayer;
    int m_speed, m_health;
    Map* m_map;
    sf::Clock m_lastShot;

public:
    // Constuctor
    Player();
    Player(bool mainPlayer, float x, float y, Map* map);

    // Getters
    int getSpeed();
    int getHealth();
    Map* getMap();
    bool isMainPlayer();
    
    // Core
    void update(int directionX, int directionY, sf::Time lastFrame);
    void update(sf::Time lastFrame);
    void move(float x, float y);
    void shot(float mouseX, float mouseY);
    void draw(sf::RenderWindow& window);
};

#endif
