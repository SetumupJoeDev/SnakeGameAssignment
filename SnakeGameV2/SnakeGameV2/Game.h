#ifndef GAME_H
#define GAME_H

#include <fstream>

class Game
{
private:
	//Enums
	enum class GameStates{ mainMenu, gameRunning, gameOver };
	enum GameStates m_currentGameState;
	//Integers
	int m_currentScore;
	int m_highScore;
	//Objects
	//Resources
	std::ifstream m_highScoreFile;
	//Strings
	std::string m_scoreFilename;
public:
	Game( );

	void renderGameOver( );
	void renderMenu( );
	void runGame( );
	void update( );
};

#endif // !GAME_H
