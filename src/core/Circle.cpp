/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "Circle.hpp"

//================================================================================
// Constructors
//================================================================================

Circle::Circle() {
    this->m_x = 0.0f;
    this->m_y = 0.0f;
    this->m_radius = 0.0f;
}

Circle::Circle(float x, float y, float radius, sf::Color outlineColor, float outlineThickness, sf::Color fillColor) {
    this->m_x = x - radius;
    this->m_y = y - radius;
    this->m_radius = radius;
    this->m_shape.setRadius(radius);
    this->m_shape.setPosition(x, y);
    this->m_shape.setOutlineColor(outlineColor);
    this->m_shape.setOutlineThickness(outlineThickness);
    this->m_shape.setFillColor(fillColor);
}

//================================================================================
// Getters
//================================================================================

float Circle::getX() {
    return this->m_x;
}

float Circle::getY() {
    return this->m_y;
}

float Circle::getRadius() {
    return this->m_radius;
}

//================================================================================
// Setters
//================================================================================

void Circle::setX(float x) {
    this->m_x = x;
    this->m_shape.setPosition(this->m_x, this->m_y);
}

void Circle::setY(float y) {
    this->m_y = y;
    this->m_shape.setPosition(this->m_x, this->m_y);
}

void Circle::setPosition(float x, float y) {
    this->m_x = x;
    this->m_y = y;
    this->m_shape.setPosition(this->m_x, this->m_y);
}

void Circle::setRadius(float radius) {
    this->m_radius = radius;
}

void Circle::setColor(sf::Color color) {
    this->m_shape.setFillColor(color);
}

//================================================================================
// Collisions
//================================================================================

bool Circle::checkCollision(Circle* circle) {
    float differenceX = circle->getX() + circle->getRadius() - this->getX() - this->getRadius();
    float differenceY = circle->getY() + circle->getRadius() - this->getY() - this->getRadius();
    float distance = sqrt(differenceX * differenceX + differenceY * differenceY);
    if (distance <= circle->getRadius() + this->getRadius()) {
        return true;
    } else {
        return false;
    }
}
