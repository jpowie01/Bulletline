#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Circle {
protected:
    // Data
    float _x, _y, _radius;
    sf::CircleShape _shape;

public:
    // Constructors
    Circle();
    Circle(float _x, float _y, float _radius, sf::Color outlineColor, int outlineThickness, sf::Color fillColor);

    // Getters
    float getX();
    float getY();
    float getRadius();

    // Setters
    void setX(float _x);
    void setY(float _y);
    void setRadius(float _radius);
};

#endif
