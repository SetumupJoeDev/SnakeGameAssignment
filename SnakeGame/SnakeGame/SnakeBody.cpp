
#include "Resource.h"
#include "SnakeBody.h"

SnakeBody::SnakeBody()
{
	m_bodyAvatar = '#';
}

void SnakeBody::update()
{
	
}

void SnakeBody::render()
{
	DrawChar(m_bodyAvatar, m_xCoord, m_yCoord);
}