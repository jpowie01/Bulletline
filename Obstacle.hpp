#ifndef Obstacle_hpp
#define Obstacle_hpp

#include <SFML/Graphics.hpp>

class Obstacle {
private:
    sf::RectangleShape _obstacle;
    float _x, _y; 
    float _width, _height;

public:
    Obstacle();
    ~Obstacle();
    Obstacle(float x, float y, float width, float height);
    void draw(sf::RenderWindow& window);
};

#endif

