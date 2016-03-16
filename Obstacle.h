#ifndef Obstacle_h
#define Obstacle_h

#include <SFML/Graphics.hpp>

class Obstacle
{
private:
	sf::RectangleShape _obstacle;
	float _x, _y; 
	float _width, _lenght;

public:
	Obstacle();
	~Obstacle();
	Obstacle(float x, float y, float width, float lenght);
	void draw(sf::RenderWindow& window );
};

#endif

