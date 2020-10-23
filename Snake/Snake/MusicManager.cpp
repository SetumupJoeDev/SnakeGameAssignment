
#include "MusicManager.h"

MusicManager::MusicManager()
{
	m_mainMenuMusic = TEXT( "Powerup!.wav" );
	m_inGameMusic = TEXT( "Underclocked.wav" );
	m_deathMusic = TEXT( "DeathSound.wav" );
}

void MusicManager::playMainMenuMusic( )
{
	PlaySound( m_mainMenuMusic, NULL, SND_ASYNC | SND_FILENAME | SND_LOOP );
}

void MusicManager::playGameMusic( )
{
	PlaySound( m_inGameMusic, NULL, SND_ASYNC | SND_FILENAME | SND_LOOP );
}

void MusicManager::playDeathMusic( )
{
	PlaySound( m_deathMusic, NULL, SND_ASYNC | SND_FILENAME );
}
