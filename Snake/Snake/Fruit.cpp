
#include <stdlib.h>

#include "Fruit.h"

Fruit::Fruit( )
{
	m_characterAvatar = Settings::Fruit::m_fruitChar;
	m_textColour	  = Settings::Fruit::m_fruitColour;
	generateNewPosition( );
}

void Fruit::generateNewPosition( )
{
	//Generates a new set of coordinates for the fruit, between 1, 1 and 99, 24
	int newX = ( rand( ) % m_rightBoundary  - 1 ) + 1;
	int newY = ( rand( ) % m_bottomBoundary - 1 ) + 1;
	m_characterVector.setPosition( newX, newY );
}
