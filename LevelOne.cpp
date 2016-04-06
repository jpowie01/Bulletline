#include "LevelOne.hpp"
#include "Obstacle.hpp"

LevelOne::LevelOne() {
    // Create all obstacles on map - level one
    Obstacle* obstacle1 = new Obstacle(100, 120, 40, 100); // x, y, width, height
    Obstacle* obstacle2 = new Obstacle(20, 300, 100, 40); 
    Obstacle* obstacle3 = new Obstacle(240, 350, 40, 120);
    Obstacle* obstacle4 = new Obstacle(140, 450, 140, 40);
    Obstacle* obstacle5 = new Obstacle(300, 20, 40, 150);
    Obstacle* obstacle6 = new Obstacle(550, 150, 140, 40);
    Obstacle* obstacle7 = new Obstacle(550, 150, 40, 140);
    Obstacle* obstacle8 = new Obstacle(430, 450, 40, 150);
    Obstacle* obstacle9 = new Obstacle(850, 20, 40, 120);
    Obstacle* obstacle10 = new Obstacle(900, 420, 40, 180);
    Obstacle* obstacle11 = new Obstacle(1000, 300, 220, 40);
    Obstacle* obstacle12 = new Obstacle(1030, 450, 80, 80);
    Obstacle* obstacle13 = new Obstacle(1000, 100, 90, 120);
    Obstacle* obstacle14 = new Obstacle(600, 500, 180, 40);
    Obstacle* obstacle15 = new Obstacle(700, 400, 40, 100);

    // Add all obstacles
    this->addObstacle(obstacle1);
    this->addObstacle(obstacle2);
    this->addObstacle(obstacle3);
    this->addObstacle(obstacle4);
    this->addObstacle(obstacle5);
    this->addObstacle(obstacle6);
    this->addObstacle(obstacle7);
    this->addObstacle(obstacle8);
    this->addObstacle(obstacle9);
    this->addObstacle(obstacle10);
    this->addObstacle(obstacle11);
    this->addObstacle(obstacle12);
    this->addObstacle(obstacle13);
    this->addObstacle(obstacle14);
    this->addObstacle(obstacle15);

    // Creating example bullets
    Bullet* bullet1 = new Bullet(500.0f, 300.0f, 1.0f, 0.0f, NULL);
    Bullet* bullet2 = new Bullet(500.0f, 300.0f, 0.0f, 1.0f, NULL);
    Bullet* bullet3 = new Bullet(500.0f, 300.0f, -1.0f, 0.0f, NULL);
    Bullet* bullet4 = new Bullet(500.0f, 300.0f, 0.0f, -1.0f, NULL);
    Bullet* bullet5 = new Bullet(500.0f, 300.0f, 0.7f, 0.7f, NULL);
    Bullet* bullet6 = new Bullet(500.0f, 300.0f, 0.7f, -0.7f, NULL);
    Bullet* bullet7 = new Bullet(500.0f, 300.0f, -0.7f, 0.7f, NULL);
    Bullet* bullet8 = new Bullet(500.0f, 300.0f, -0.7f, -0.7f, NULL);

    // Adding example bullets
    addBullet(bullet1);
    addBullet(bullet2);
    addBullet(bullet3);
    addBullet(bullet4);
    addBullet(bullet5);
    addBullet(bullet6);
    addBullet(bullet7);
    addBullet(bullet8);
}

LevelOne::~LevelOne() {}
