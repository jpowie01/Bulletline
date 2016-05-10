/*
* Counter Strike 2D
*
* (c) 2016 Jakub Powierza & Karolina Olszewska
*
*/

#include "Label.hpp"
#include "../helpers/ResourcePath.hpp"

//================================================================================
// Constructors
//================================================================================

Label::Label() {
    this->m_text = "";
    this->m_fontSize = 0;
    this->m_positionX = 0;
    this->m_positionY = 0;
    this->m_color = sf::Color::White;

    // Load font
    if (!m_font.loadFromFile(resourcePath() + "assets/fonts/Arial.ttf")) {
        printf("Failed to load font file (Arial.ttf)");
        return;
    }

    // Set label
    m_label.setFont(m_font);
    m_label.setString(this->m_text);
    m_label.setCharacterSize(this->m_fontSize);
    m_label.setPosition(this->m_positionX, this->m_positionY);
    m_label.setColor(this->m_color);
}

Label::Label(string text, int fontSize, int positionX, int positionY, sf::Color color) {
    this->m_text = text;
    this->m_fontSize = fontSize;
    this->m_positionX = positionX;
    this->m_positionY = positionY;
    this->m_color = color;

    // Load font
    if (!m_font.loadFromFile(resourcePath() + "assets/fonts/Arial.ttf")) {
        printf("Failed to load font file (Arial.ttf)");
        return;
    }

    // Set label
    m_label.setFont(m_font);
    m_label.setString(this->m_text);
    m_label.setCharacterSize(this->m_fontSize);
    m_label.setPosition(this->m_positionX, this->m_positionY);
    m_label.setColor(this->m_color);
}

//================================================================================
// Core
//================================================================================

void Label::draw(sf::RenderWindow& window) {
    window.draw(m_label);
}
