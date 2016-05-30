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

using namespace std;

class Player : public Circle {
private:
    int m_ID;
    int m_teamID;
    bool m_mainPlayer;
    int m_speed, m_health;
    int m_directionX, m_directionY;
    string m_name;
    Map* m_map;
    sf::Clock m_lastShot;

public:
    // Constuctor
    Player();
    Player(bool mainPlayer, float x, float y, Map* map);

    // Getters
    int getID();
    int getTeamID();
    int getSpeed();
    int getHealth();
    int getDirectionX();
    int getDirectionY();
    string getName();
    Map* getMap();
    bool isMainPlayer();

    // Setters
    void setID(int ID);
    void setTeamID(int teamID);
    void setName(string name);
    void setDirection(int directionX, int directionY);
    
    // Core
    void update(sf::Time lastFrame);
    void move(float x, float y);
    void shot(float mouseX, float mouseY);
    void draw(sf::RenderWindow& window);
};

#endif
