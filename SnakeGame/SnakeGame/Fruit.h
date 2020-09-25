#ifndef FRUIT_H
#define FRUIT_H

#include "Resource.h"

class Fruit
{
private:
	//Chars
	char m_fruitAvatar;
	//Integers
	int m_xCoord;
	int m_yCoord;
public:
	Fruit();

	int getPosX() { return m_xCoord; }
	int getPosY() { return m_yCoord; }

	void render();
	void generateNewPosition();
};

#endif