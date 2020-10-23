#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <Windows.h>

class MusicManager
{
private:
	LPCWSTR m_mainMenuMusic;
	LPCWSTR m_inGameMusic;
	LPCWSTR m_deathMusic;
public:
	//Constructor
	MusicManager( );
	//Methods
	void playMainMenuMusic( );
	void playGameMusic( );
	void playDeathMusic( );
};

#endif // !SOUNDMANAGER_H
