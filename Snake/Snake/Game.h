#ifndef GAME_H
#define GAME_H

#include <fstream>

#include "Fruit.h"
#include "BoundaryManager.h"
#include "ScoreManager.h"
#include "Snake.h"
#include "MenuRenderer.h"
#include "MusicManager.h"
#include "Vector2.h"

class Game
{
	//Variables
private:
	//Booleans
	bool m_hasRenderedWalls;
	bool m_stillPlaying;
	//Enums
	enum class GameStates{mainMenu, gameRunning, deathScreen };
	enum class MenuOptions{playClassic, playAdventure, clearHighScore, quitGame };
	enum GameStates m_currentGameState;
	enum MenuOptions m_currentMenuOption;
	//Integers
	int m_fruitScoreIncrease;
	int m_sleepTimer;
	//Objects
	Fruit m_fruit;
	BoundaryManager m_boundaryManager;
	ScoreManager m_scoreManager;
	Snake m_snake;
	MenuRenderer m_menuRenderer;
	MusicManager m_musicManager;
	//Vectors
	Vector2 m_currentScorePosition;
	Vector2 m_currentTextPosition;
	//Methods
public:
	//Constructor
	Game( );
	//Setters and getters

	//Methods
	void checkHasCollectedFruit( );
	void checkHasDied( );
	void mainLoop( );
	void renderMainMenu( );
	void renderMenuOptions( );
	void runGame( );
	void renderGameOver( );
	void renderScore( );
	void renderHighScore( );
};

#endif
