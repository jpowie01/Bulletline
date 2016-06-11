/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef Bullet_hpp
#define Bullet_hpp

#include <SFML/Graphics.hpp>
#include <stdio.h>

#include "Circle.hpp"
#include "../Definitions.hpp"

class Player;

class Bullet : public Circle {
private:
    float m_directionX, m_directionY;
    float m_speed;
    Player* m_player;

public:
    // Constructors
    Bullet();
    Bullet(float x, float y, float directionX, float directionY, Player* player);
    
    // Getters
    float getDirectionX();
    float getDirectionY();
    float getSpeed();
    Player* getPlayer();
    
    // Core
    bool update(sf::Time lastFrame);
    void move(float x, float y);
    void draw(sf::RenderWindow& window);
};

#endif
