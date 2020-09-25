
#include "Resource.h"
#include "SnakeBody.h"

SnakeBody::SnakeBody()
{
	m_bodyAvatar = '#';
}

void SnakeBody::update()
{
	m_xCoord += m_xIncrease;
	m_yCoord += m_yIncrease;
}

void SnakeBody::render()
{
	DrawChar(m_bodyAvatar, m_xCoord, m_yCoord);
}