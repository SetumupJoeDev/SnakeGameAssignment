#ifndef SNAKE_H
#define SNAKE_H

#include "SnakeBody.h"

class Snake
{
private:
	//Booleans
	bool m_isDead;
	bool m_hasCollectedFruit;
	//Characters
	char m_snakeAvatar;
	char m_keyPressed;
	//Integers
	int m_xCoord;
	int m_yCoord;
	int m_pickupXCoord;
	int m_pickupYCoord;
	int m_xIncrease;
	int m_yIncrease;
	int m_numBodySegments;
	//Objects
	SnakeBody m_bodySegments [1000];
public:
	Snake();
	//Setters & Getters
	bool getIsDead() { return m_isDead; }
	bool getCollectedFruit() { return m_hasCollectedFruit; }
	void setCollectedFruit(bool hasCollected) { m_hasCollectedFruit = hasCollected; }
	void setPickupXPos(int posX) { m_pickupXCoord = posX; }
	void setPickupYPos(int posY) { m_pickupYCoord = posY; }
	//Methods
	void update();
	void render();
	void readInput();
	void checkCollisions();
	void resetSnake();
};

#endif