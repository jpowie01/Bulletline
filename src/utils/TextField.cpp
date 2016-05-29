/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "TextField.hpp"
#include "../helpers/ResourcePath.hpp"

//================================================================================
// Constructors
//================================================================================

TextField::TextField() {
    this->m_label = new Label("", 50, 0, 0, NULL);
    this->m_positionX = 0;
    this->m_positionY = 0;
    m_inputFlag = false;

    // Text field
    m_textField.setPosition(m_positionX, m_positionY);
    m_textField.setSize(sf::Vector2f(400, 50));
    m_textField.setFillColor(sf::Color::White);
    m_textField.setOutlineColor(sf::Color::Black);
    m_textField.setOutlineThickness(5);
}

TextField::TextField(float positionX, float positionY, CommonData* commonData) {
    this->m_label = new Label("", 50, positionX + 5, positionY - 7, commonData);
    this->m_label->setColor(sf::Color::Black);
    this->m_positionX = positionX;
    this->m_positionY = positionY;
    m_inputFlag = false;

    // Text field
    m_textField.setPosition(m_positionX, m_positionY);
    m_textField.setSize(sf::Vector2f(400, 50));
    m_textField.setFillColor(sf::Color::White);
    m_textField.setOutlineColor(sf::Color::Black);
    m_textField.setOutlineThickness(5);
}

//================================================================================
// Core
//================================================================================

void TextField::draw(sf::RenderWindow &window) {
    window.draw(m_textField);
    m_label->draw(window);
}

bool TextField::cursorInRange(sf::Vector2i position) {
    if (this->m_textField.getGlobalBounds().contains(position.x, position.y)) {
        return true;
    }
    return false;
}

string TextField::getText() {
    return this->m_label->getString();
}

void TextField::setText(string text) {
    this->m_label->setString(text);
}

void TextField::setOutline(sf::Color color) {
    this->m_textField.setOutlineColor(color);
}
