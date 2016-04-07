#include "Circle.hpp"

Circle::Circle() {
    this->_x = 0.0f;
    this->_y = 0.0f;
    this->_radius = 0.0f;
}

Circle::Circle(float _x, float _y, float _radius, sf::Color outlineColor, int outlineThickness, sf::Color fillColor) {
    this->_x = _x - _radius;
    this->_y = _y - _radius;
    this->_radius = _radius;
    this->_shape.setRadius(this->_radius);
    this->_shape.setPosition(this->_x, this->_y);
    this->_shape.setOutlineColor(outlineColor);
    this->_shape.setOutlineThickness(outlineThickness);
    this->_shape.setFillColor(fillColor);
}

float Circle::getX() {
    return this->_x;
}

float Circle::getY() {
    return this->_y;
}

float Circle::getRadius() {
    return this->_radius;
}

void Circle::setX(float _x) {
    this->_x = _x;
}

void Circle::setY(float _y) {
    this->_y = _y;
}

void Circle::setRadius(float _radius) {
    this->_radius = _radius;
}
