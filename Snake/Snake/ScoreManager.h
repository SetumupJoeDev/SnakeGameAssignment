#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <fstream>

#include "Vector2.h"

class ScoreManager
{
private:
	//Integers
	int m_currentScore;
	int m_highScore;
	int m_textColour;
	//Resources
	std::ifstream m_highScoreFileRead;
	std::ofstream m_highScoreFileWrite;
	//Strings
	std::string m_scoreFile;
	//Vectors
	Vector2 m_scorePosition;
	Vector2 m_highScorePosition;
public:
	//Constructor
	ScoreManager( );
	//Setters and Getters
	//Current Score
	void setCurrentScore( int newScore ){ m_currentScore = newScore; }
	int  getCurrentScore( ){ return m_currentScore; }
	//High Score
	void setHighScore( int newHighScore ){ m_highScore = newHighScore; }
	int  getHighScore( ){ return m_highScore; }
	//Methods
	void readHighScore( );
	void writeHighScore( int newHighScore );
	void displayScores( );
};

#endif // !SCOREMANAGER_H
