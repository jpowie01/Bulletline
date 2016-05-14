/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef Definitions_hpp
#define Definitions_hpp

// Graphics definitions
#define ANTIALIASING_LEVEL  8

// Core definitions
#define GAME_TITLE          "Counter Strike 2D"
#define AUTHOR_1            "Jakub Powierza"
#define AUTHOR_2            "Karolina Olszewska"
#define SCREEN_WIDTH        1200
#define SCREEN_HEIGHT       680

// Player settings
#define PLAYER_SPEED        150
#define PLAYER_HEALTH       100
#define PLAYER_STARTING_POSITION_X  400.0f
#define PLAYER_STARTING_POSITION_Y  200.0f

// Bullet settings
#define BULLET_SPEED        300

// Button settings
#define DEFAULT_BUTTON_COLOR  sf::Color::White

// Label settings
#define DEFAULT_LABEL_COLOR  sf::Color::White

// Network connection (temporary until there won't be menu for that)
#define SERVER_HOST         "192.168.0.12"
#define SERVER_PORT         54000

// Network headers
#define PLAYER_HEADER       1

// Screens
#define NUMBER_OF_SCREENS   3
#define EXIT                -1
#define MAIN_MENU           0
#define GAME                1
#define AUTHORS_MENU        2

#define STARTING_SCREEN     MAIN_MENU

#endif
