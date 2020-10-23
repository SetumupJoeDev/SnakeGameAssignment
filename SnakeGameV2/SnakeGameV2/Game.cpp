#include "Game.h"

#include <iostream>
#include <Windows.h>

Game::Game( )
{
	m_currentScore = 0;
	m_currentGameState = GameStates::mainMenu;
	m_scoreFilename = "HighScore.txt";
	m_highScoreFile.open( m_scoreFilename );
	m_highScoreFile >> m_highScore;
	m_highScoreFile.close( );
}

void Game::renderGameOver( )
{
	//Clears all text from the screen
	system( "cls" );
	//Displays text on the screen to inform the player of how to proceed
	std::cout << "You died!";
	std::cout << "Your score was: " << m_currentScore << "\n\n";
	std::cout << "Press any key to play again!\n";
}

void Game::renderMenu( )
{
	//Clears the screen of all text
	system( "cls" );
	//Prints some welcome text to inform the player how to proceed
	std::cout << "Welcome to Snake!\n";
	std::cout << "Press any key to begin!\n\n";
	std::cout << "High Score: " << m_highScore;
}

void Game::runGame( )
{
	system( "cls" );
	std::cout << "The game will go here, I promise!\n";
}

void Game::update( )
{
	while ( true )
	{
		switch ( m_currentGameState )
		{
		case GameStates::mainMenu:
			renderMenu( );
			break;
		case GameStates::gameRunning:
			runGame( );
			break;
		case GameStates::gameOver:
			renderGameOver( );
			break;
		}
		Sleep( 250 );
	}
}
