#ifndef GAME_H
#define GAME_H

#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

#include "Snake.h"
#include "Fruit.h"

class Game
{
private:
	//Objects
	Snake m_snake;													//The player's snake object
	Fruit m_fruit;													//The collectable fruit object
	//Integers
	int m_currentScore;												//The player's current score
	int m_highScore;												//The high score, read from HighScore.txt
	//Strings
	std::string m_scoreFileToOpen;									//The name of the .txt file to read the high score from
	//Enums
	enum class GameStates{ mainMenu, gameRunning, playerDead};		//An enum used to determine which state the game is in, and what screen to render
	enum GameStates m_currentGameState;
	//Resources
	std::ifstream m_highScoreFile;									//The file that the game's high score is saved in
public:
	Game();

	void update();
	void renderMainMenu();
	void runGame();
	void renderDeathScreen();
	void checkIsDead();
	void checkCollectedFruit();
};

#endif