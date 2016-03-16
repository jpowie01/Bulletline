#ifndef Player_hpp
#define Player_hpp

#include <SFML/Graphics.hpp>
#include <stdio.h>

class Player {
private:
    sf::CircleShape _shape;
    float _x, _y;
    int _speed;
    int _health;
    int _radius;

public:
    Player();
    Player(float x, float y);
    ~Player();
    void move(float x, float y);
    void shot(float x, float y);
    void draw(sf::RenderWindow& window);
    int getSpeed();
};

#endif
