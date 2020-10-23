#ifndef FRUIT_H
#define FRUIT_H

#include "CharacterBase.h"
#include "Settings.h"

class Fruit : public CharacterBase
{
private:
	const int m_topBoundary		= Settings::Level::m_topBoundary;
	const int m_bottomBoundary	= Settings::Level::m_bottomBoundary;
	const int m_leftBoundary	= Settings::Level::m_leftBoundary;
	const int m_rightBoundary	= Settings::Level::m_rightBoundary;
public:
	Fruit( );

	void generateNewPosition( );
};

#endif // !FRUIT_H
