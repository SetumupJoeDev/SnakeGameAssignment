#include <conio.h>
#include <fstream>

#include "Game.h"
#include "Resource.h"

Game::Game()
{
	m_currentScore = 0;
	m_currentGameState = GameStates::mainMenu;
	m_scoreFileToOpen = "HighScore.txt";
	m_highScoreFile.open(m_scoreFileToOpen);
	m_highScoreFile >> m_highScore;
	m_highScoreFile.close();
	m_snake.setPickupXPos(m_fruit.getPosX());
	m_snake.setPickupYPos(m_fruit.getPosY());
}

void Game::checkIsDead()
{
	if (m_snake.getIsDead()) 
	{
		//If the snake is dead, the game state is updated to display the correct text
		m_currentGameState = GameStates::playerDead;
		if(m_currentScore > m_highScore)
		{ 
			m_highScoreFile.open(m_scoreFileToOpen);				//If the player's score is more than the saved high score, the HighScore.txt file
			//m_highScoreFile << m_currentScore;					//is updated with the new score. (doesn't currently work for some reason)
			m_highScoreFile.close();
		}
	}
}

void Game::checkCollectedFruit()
{
	if(m_snake.getCollectedFruit())
	{
		m_currentScore += 10;
		m_fruit.generateNewPosition();
		m_snake.setPickupXPos(m_fruit.getPosX());
		m_snake.setPickupYPos(m_fruit.getPosY());
		m_snake.setCollectedFruit(false);
	}
}

void Game::renderMainMenu() 
{
	//Clears the screen of all text
	system("cls");
	//Prints some welcome text to inform the player how to proceed
	std::cout << "Welcome to Snake!\n";
	std::cout << "Press any key to begin!\n\n";
	std::cout << "High Score: " << m_highScore;
	//If the game detects keyboard input, the game starts
	if (_kbhit()) 
	{
		m_currentGameState = GameStates::gameRunning;
		//Discards the input from the buffer to prevent future input flags
		_getch();				
	}
}

void Game::runGame() 
{
	//Clears the screen of all text
	system("cls");
	//Draws the snake in the console
	m_snake.render();
	//Draws the fruit in the console
	m_fruit.render();
	//Runs the Snake's update function to render it on screen
	m_snake.update();
	//Checks to see if the snake has died this update
	checkIsDead();
	checkCollectedFruit();
}

void Game::renderDeathScreen() 
{
	//Clears all text from the screen
	system("cls");
	//Displays text on the screen to inform the player of how to proceed
	std::cout << "You died!";
	std::cout << "Your score was: " << m_currentScore << "\n\n";
	std::cout << "Press any key to play again!\n";
	if (m_snake.getIsDead()) { m_snake.resetSnake(); }
	//If the game detects keyboard input, the player is returned to the main menu
	if (_kbhit())
	{
		m_currentGameState = GameStates::mainMenu;
		m_currentScore = 0;
		//Discards the input from the buffer to prevent future input flags
		_getch();
	}
}

void Game::update() 
{
	while(true)
	{
		switch (m_currentGameState)
		{
		case GameStates::mainMenu:
			renderMainMenu();
			break;
		case GameStates::gameRunning:
			runGame();
			break;
		case GameStates::playerDead:
			renderDeathScreen();
			break;
		}
		Sleep(250);
	}
}