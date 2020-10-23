#include <conio.h>
#include <iostream>

#include "Resource.h"
#include "Snake.h"

Snake::Snake( )
{
	resetSnake( );
}

void Snake::readInput( )
{
	m_keyPressed = _getch( );
	//Reads the ascii value of the key pressed and saves it to a local variable
	int asciiValue = m_keyPressed;
	if ( asciiValue == 72 && m_yIncrease != 1 )
	{
		m_xIncrease = 0;						//If the key pressed was UP, the snake's x coordinate increase is set to 0 so that it will only move
		m_yIncrease = -1;						//vertically, and its y coordinate increase is set to -1 so that it will move upwards. Its avatar
		m_snakeAvatar = '^';					//Is changed to ^ to show the direction it is facing is up
	}
	else if ( asciiValue == 80 && m_yIncrease != -1 )
	{
		m_xIncrease = 0;						//If the key pressed was DOWN, the snake's x coordinate increase is set to 0 so that it will only move
		m_yIncrease = 1;						//vertically, and its y coordinate increase is set to 1 so that it will move downwards. Its avatar
		m_snakeAvatar = 'v';					//Is changed to v to show the direction it is facing is down
	}
	else if ( asciiValue == 75 && m_xIncrease != 1 )
	{
		m_xIncrease = -1;						//If the key pressed was LEFT, the snake's y coordinate increase is set to 0 so that it will only move
		m_yIncrease = 0;						//horizontally, and its x coordinate increase is set to -1 so that it will move left. Its avatar
		m_snakeAvatar = '<';					//Is changed to < to show the direction it is facing is left
	}
	else if ( asciiValue == 77 && m_xIncrease != -1 )
	{
		m_xIncrease = 1;						//If the key pressed was RIGHT, the snake's x coordinate increase is set to 0 so that it will only move
		m_yIncrease = 0;						//vertically, and its y coordinate increase is set to -1 so that it will move upwards. Its avatar
		m_snakeAvatar = '>';					//Is changed to ^ to show the direction it is facing
	}
	if ( m_numBodySegments > 0 )
	{
		for ( int i = 1; i <= m_numBodySegments; i++ )
		{
			m_bodySegments[i - 1].setXIncrease( m_xIncrease );
			m_bodySegments[i - 1].setYIncrease( m_yIncrease );
		}
	}
}

void Snake::update( )
{
	//Adds the value of m_xIncrease to the x coordinate of the snake to move it horizontally
	m_xCoord += m_xIncrease;
	//Adds the value of m_xIncrease to the x coordinate of the snake to move it vertically
	m_yCoord += m_yIncrease;
	if ( m_numBodySegments > 0 )
	{
		for ( int i = 1; i <= m_numBodySegments; i++ )
		{
			m_bodySegments[i - 1].update( );
		}
	}
	//Checks to see if there is any input at all before trying to determine what key has been pressed
	if ( _kbhit( ) )
	{
		readInput( );
	}
	//Checks to see if the snake has collided with the walls, a pickup, or itself
	checkCollisions( );
}

void Snake::render( )
{
	//Draws the snake's avatar in the correct position on the screen
	DrawChar( m_snakeAvatar, m_xCoord, m_yCoord );
	if ( m_numBodySegments > 0 )
	{
		for ( int i = 1; i <= m_numBodySegments; i++ )
		{
			m_bodySegments[i - 1].render( );
		}
	}
}

void Snake::resetSnake( )
{
	m_snakeAvatar = '^';
	m_xCoord = 30;
	m_yCoord = 25;
	m_xIncrease = 0;
	m_yIncrease = -1;
	m_isDead = false;
	m_hasCollectedFruit = false;
	m_numBodySegments = 0;
}

void Snake::checkCollisions( )
{
	//If the snake reaches any coordinates outside of the bounding box, it dies and the player loses
	if ( m_xCoord <= 1 || m_xCoord >= 50 || m_yCoord <= 1 || m_yCoord >= 50 )
	{
		m_isDead = true;
	}
	if ( m_xCoord == m_pickupXCoord && m_yCoord == m_pickupYCoord )
	{
		m_numBodySegments++;
		m_hasCollectedFruit = true;
	}
}
