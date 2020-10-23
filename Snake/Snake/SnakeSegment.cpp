
#include "SnakeSegment.h"

SnakeSegment::SnakeSegment( )
{
	m_characterVector.setPosition( 12, 13 );
	m_xVelocity = 0;
	m_yVelocity = 0;
}

void SnakeSegment::update( )
{
	//Moves the segment by increasing its X or Y position by the value of xVelocity and yVelocity
	m_characterVector.setPosition( m_characterVector.m_posX + m_xVelocity, m_characterVector.m_posY + m_yVelocity );
}
