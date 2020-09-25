
#include "Fruit.h"
#include <stdlib.h>

Fruit::Fruit()
{
	m_fruitAvatar = 'a';
	generateNewPosition();
}

void Fruit::render()
{
	DrawChar(m_fruitAvatar, m_xCoord, m_yCoord);
}

void Fruit::generateNewPosition() 
{
	m_xCoord = (rand() % 49) + 1;
	m_yCoord = (rand() % 49) + 1;
}