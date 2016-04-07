#ifndef Bullet_hpp
#define Bullet_hpp

#include <SFML/Graphics.hpp>
#include <stdio.h>

#include "Circle.hpp"

class Player;

class Bullet : public Circle {
private:
    float _directionX, _directionY;
    float _speed;
    Player* _player;
public:
    Bullet();
    Bullet(float x, float y, float directionX, float directionY, Player* player);
    ~Bullet();
    bool update(sf::Time lastFrame);
    void move(float x, float y);
    void draw(sf::RenderWindow& window);
};

#endif
