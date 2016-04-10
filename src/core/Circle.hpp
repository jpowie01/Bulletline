/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Circle {
protected:
    // Data
    float m_x, m_y, m_radius;
    sf::CircleShape m_shape;

public:
    // Constructors
    Circle();
    Circle(float x, float y, float radius, sf::Color outlineColor, int outlineThickness, sf::Color fillColor);

    // Getters
    float getX();
    float getY();
    float getRadius();

    // Setters
    void setX(float x);
    void setY(float y);
    void setRadius(float radius);
};

#endif
