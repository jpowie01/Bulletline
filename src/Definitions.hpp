/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef Definitions_hpp
#define Definitions_hpp

// Graphics definitions
#define ANTIALIASING_LEVEL  8

// Core definitions
#define GAME_TITLE          "Bulletline"
#define AUTHOR_1            "Jakub Powierza"
#define AUTHOR_2            "Karolina Olszewska"
#define SCREEN_WIDTH        1200
#define SCREEN_HEIGHT       680

// Player settings
#define PLAYER_SPEED        150
#define PLAYER_HEALTH       100
#define PLAYER_STARTING_POSITION_X  400.0f
#define PLAYER_STARTING_POSITION_Y  200.0f

// Team settings
#define BLUE_TEAM           0
#define RED_TEAM            1

// Bullet settings
#define BULLET_SPEED        300

// Button settings
#define DEFAULT_BUTTON_COLOR  sf::Color::White
#define BUTTON_POSITION_X  50
#define BUTTON_POSITION_Y  SCREEN_HEIGHT - 100
#define NEXT_BUTTON_POSITION_X  SCREEN_WIDTH - 150

// Label settings
#define DEFAULT_LABEL_COLOR  sf::Color::White

// Network connection (temporary until there won't be menu for that)
#define SERVER_HOST         "127.0.0.1"
#define SERVER_PORT         54000

// Network headers
#define NETWORK_PLAYER_INTRODUCTION_HEADER              1
#define NETWORK_JOINED_GAME_HEADER                      2
#define NETWORK_PLAYER_JOINED_HEADER                    3
#define NETWORK_START_GAME_HEADER                       4
#define NETWORK_PLAYER_UPDATE_HEADER                    5
#define NETWORK_ALL_PLAYERS_UPDATE_HEADER               6
#define NETWORK_PLAYER_SHOT_HEADER                      7
#define NETWORK_NEW_BULLET_HEADER                       8
#define NETWORK_PLAYER_IS_DEAD_HEADER                   9
#define NETWORK_END_OF_THE_GAME_HEADER                  10

// Screens
#define NUMBER_OF_SCREENS   5
#define EXIT                -1
#define MAIN_MENU           0
#define PLAYER_MENU         1
#define GAME                2
#define AUTHORS_MENU        3
#define WAITING_MENU        4

#define STARTING_SCREEN     MAIN_MENU

#endif
