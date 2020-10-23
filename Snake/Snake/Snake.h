#ifndef SNAKE_H
#define SNAKE_H

#include "SnakeSegment.h"

class Snake
{
private:
	//Booleans
	bool m_isDead;
	bool m_hasCollectedFruit;
	bool m_isMoving;
	//Integers
	int m_numSegments;                       //The number of body segments to render
	int m_lengthIncrease;
	const int m_maxLength = Settings::Snake::m_maxLength;
	//Constants
	const int m_topBoundary = Settings::Level::m_topBoundary;
	const int m_bottomBoundary = Settings::Level::m_bottomBoundary;
	const int m_leftBoundary = Settings::Level::m_leftBoundary;
	const int m_rightBoundary = Settings::Level::m_rightBoundary;
	//Objects
	SnakeSegment m_bodySegments[Settings::Snake::m_maxLength];
	SnakeSegment& m_snakeHead;
	//Vector2
	Vector2 m_fruitPosition;
public:
	//Constructor
	Snake( );
	//Setters and Getters

	//Methods
	void checkForCollisions( );
	void checkForInput( );
	//Setters and Getters
	//fruitPosX
	void setFruitPos( Vector2 fruitPosition ){ m_fruitPosition.setPosition( fruitPosition.m_posX, fruitPosition.m_posY ); }
	Vector2  getFruitPos( ){ return m_fruitPosition; }
	//IsDead
	void setIsDead( bool shouldBeDead ){ m_isDead = shouldBeDead; }
	bool getIsDead( ){ return m_isDead; }
	//hasCollectedFruit
	void setCollectedFruit( bool collectedFruit ){ m_hasCollectedFruit = collectedFruit; }
	bool getCollectedFruit( ){ return m_hasCollectedFruit; }
	//Methods
	void unrenderSegments( );
	void renderSegments( );
	void resetSnake( ); 
	void update( );
	void updateTailSegmentPositions( );
};

#endif // !SNAKE_H
