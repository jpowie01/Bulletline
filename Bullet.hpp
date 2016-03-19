#ifndef Bullet_hpp
#define Bullet_hpp

#include <SFML/Graphics.hpp>
#include <stdio.h>

class Player;

class Bullet {
private:
    sf::CircleShape _shape;
    float _x, _y;
    float _directionX, _directionY;
    float _speed, _radius;
    Player* _player;
public:
    Bullet();
    Bullet(float x, float y, float directionX, float directionY, Player* player);
    ~Bullet();
    void update(sf::Time lastFrame);
    void move(float x, float y);
    void draw(sf::RenderWindow& window);
};

#endif
