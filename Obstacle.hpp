#ifndef Obstacle_hpp
#define Obstacle_hpp

#include <cmath>
#include <SFML/Graphics.hpp>
#include "Circle.hpp"
#include "Player.hpp"
#include "Bullet.hpp"

class Obstacle {
private:
    sf::RectangleShape _obstacle;
    float _x, _y; 
    float _width, _height;

public:
    Obstacle();
    Obstacle(float x, float y, float width, float height);
    bool checkCollision(Circle* circle);
    void draw(sf::RenderWindow& window);
};

#endif

