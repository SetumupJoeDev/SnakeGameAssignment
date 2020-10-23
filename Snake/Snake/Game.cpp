
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <Windows.h>

#include "Game.h"
#include "Helpers.h"
#include "Settings.h"

Game::Game( )
{
	m_currentGameState = GameStates::mainMenu;
	m_currentMenuOption = MenuOptions::playClassic;
	m_fruitScoreIncrease = Settings::Game::m_fruitScoreIncrease;
	m_sleepTimer = Settings::Game::m_sleepTimer;
	//Passes the position of the fruit into the Snake so it can detect collisions
	m_snake.setFruitPos( m_fruit.getVector() );
	//Sets this boolean to false so that the walls will be rendered
	m_hasRenderedWalls = false;
	//Sets the position of the score text
	m_currentScorePosition.setPosition( 25, 0 );
	//Plays the main menu music
	m_musicManager.playMainMenuMusic( );
	//Sets this boolean to true so that the game will continue to run until the player quits
	m_stillPlaying = true;
}

void Game::renderMainMenu( )
{
	//Prints some welcome text to inform the player how to proceed
	m_menuRenderer.renderMainMenu( );
	renderHighScore( );
	//If the game detects keyboard input, it checks what key was pressed
	if ( _kbhit( ) )
	{
		//Checks to see what key was pressed
		char inputChar = _getch( );
		int asciiCode = ( int ) inputChar;
		switch ( asciiCode )
		{
		case 72:
		{
			//If the UP arrow was pressed, and the current menu option is not the top one, the menu selection moves up
			if ( ( int ) m_currentMenuOption > 0 )
			{
				int optionInt = ( int ) m_currentMenuOption - 1;
				m_currentMenuOption = (MenuOptions)optionInt;
				m_menuRenderer.setCurrentOption( optionInt );
				m_menuRenderer.renderMainMenu( );
			}
			break;
		}
		case 80:
		{
			//If the DOWN arrow was pressed, and the current menu option is not the bottom one, the menu selection moves down
			if ( ( int ) m_currentMenuOption < 3 )
			{
				int optionInt = ( int ) m_currentMenuOption + 1;
				m_currentMenuOption = ( MenuOptions ) optionInt;
				m_menuRenderer.setCurrentOption( optionInt );
				m_menuRenderer.renderMainMenu( );
			}
			break;
		}
		case 13:
		{
			//Checks to see which menu option is currently selected and acts accordingly
			switch ( m_currentMenuOption )
			{
			case Game::MenuOptions::playClassic:
			{
				//If the current option is playClassic, the classic game mode is executed
				m_currentGameState = GameStates::gameRunning;
				//Clears all text from the screen
				system( "cls" );
				//The game's background music is played
				m_musicManager.playGameMusic( );
				break;
			}
			case Game::MenuOptions::playAdventure:
			{
				//Adventure mode goes here
				break;
			}
			case Game::MenuOptions::clearHighScore:
			{
				//Resets the saved high score to 0
				m_scoreManager.writeHighScore( 0 );
				m_scoreManager.readHighScore( );
				renderHighScore( );
				break;
			}
			case Game::MenuOptions::quitGame:
			{
				//Closes the game
				m_stillPlaying = false;
			}
			default:
				break;
			}
		}
		default:
			break;
		}
	}
}

void Game::renderScore( )
{
	DrawString( "Score: " + std::to_string(m_scoreManager.getCurrentScore()), m_currentScorePosition, 15 );
}

void Game::renderHighScore( )
{
	//Renders the high score in the relevant position on screen
	m_currentTextPosition.setPosition( 45, 5 );
	DrawString( "High Score: " + std::to_string( m_scoreManager.getHighScore( ) ), m_currentTextPosition, 15 );
}

void Game::runGame( )
{
	//Un-renders the snake from the console
	m_snake.unrenderSegments( );
	//Runs the Snake's update function to move it around the play area, and update its tail segments
	m_snake.update( );
	//Renders the snake in the console
	m_snake.renderSegments( );
	if ( !m_hasRenderedWalls )
	{
		//Renders the walls
		m_boundaryManager.renderBasicWalls( );
		m_hasRenderedWalls = true;
	}
	//Draws the fruit in the console
	m_fruit.unrenderChar( );
	m_fruit.renderChar( );
	renderScore( );
}

void Game::renderGameOver( )
{
	int playerScore = m_scoreManager.getCurrentScore( );
	int highScore = m_scoreManager.getHighScore( );
	//Displays text on the screen to inform the player of how to proceed
	std::cout << "You died!";
	std::cout << "Your score was: " << playerScore << "\n\n";
	std::cout << "Press any key to play again!\n";
	if ( playerScore > highScore )
	{
		m_scoreManager.writeHighScore( playerScore );
		m_scoreManager.readHighScore( );
	}
	//If the game detects keyboard input, the player is returned to the main menu
	if ( _kbhit( ) )
	{
		m_currentGameState = GameStates::mainMenu;
		m_musicManager.playMainMenuMusic( );
		m_scoreManager.setCurrentScore( 0 );
		//Discards the input from the buffer to prevent future input flags
		char dumpChar = _getch( );
		//Clears all text from the screen
		system( "cls" );
	}
}

void Game::checkHasCollectedFruit( )
{
	if ( m_snake.getCollectedFruit( ) )
	{
		m_scoreManager.setCurrentScore( m_scoreManager.getCurrentScore( ) + 10 );
		std::cout << '\a';
		m_fruit.generateNewPosition( );
		//Passes the new position of the fruit to the snake, so that it can detect when the snake head has collided with it
		m_snake.setFruitPos( m_fruit.getVector( ) );
		m_snake.setCollectedFruit( false );
	}
}

void Game::checkHasDied( )
{
	if ( m_snake.getIsDead( ) )
	{
		m_currentGameState = GameStates::deathScreen;
		m_musicManager.playDeathMusic( );
		ChangeHandleColour( 15 );
		m_snake.resetSnake( );
		m_hasRenderedWalls = false;
	}
}

void Game::mainLoop( )
{
	while ( m_stillPlaying )
	{
		switch ( m_currentGameState )
		{
			case GameStates::mainMenu:
			{
				//Clears all text from the screen
				system( "cls" );
				renderMainMenu( );
				break;
			}
			case GameStates::gameRunning:
			{
				runGame( );
				checkHasDied( );
				checkHasCollectedFruit( );
				break;
			}
			case GameStates::deathScreen:
			{
				//Clears all text from the screen
				system( "cls" );
				renderGameOver( );
				break;
			}
		}
		Sleep( m_sleepTimer );
	}
}
