

#include "CharacterBase.h"
#include "Helpers.h"
#include "Settings.h"

CharacterBase::CharacterBase()
{
	m_characterAvatar = Settings::Snake::m_snakeChar;
	m_characterVector.setPosition( Settings::Snake::m_snakeStartPosX, Settings::Snake::m_snakeStartPosY );
	m_textColour = Settings::Snake::m_snakeColourOne;
	m_backgroundColour = Settings::Game::m_backgroundColour;
}

void CharacterBase::update( )
{

}

void CharacterBase::unrenderChar( )
{
	DrawChar( ' ', m_characterVector, m_backgroundColour );
}

void CharacterBase::renderChar( )
{
	DrawChar( m_characterAvatar, m_characterVector, m_textColour );
}