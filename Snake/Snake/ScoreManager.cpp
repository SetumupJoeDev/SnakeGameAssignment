
#include "ScoreManager.h"

ScoreManager::ScoreManager( )
{
	m_currentScore = 0;
	m_highScore = 0;
	m_scoreFile = "HighScore.txt";
	readHighScore( );
}

void ScoreManager::readHighScore( )
{
	//Reads the contents of the high score file and assigns its value to m_highScore
	m_highScoreFileRead.open( m_scoreFile );
	m_highScoreFileRead >> m_highScore;
	m_highScoreFileRead.close( );
}

void ScoreManager::writeHighScore( int newHighScore )
{
	//Writes the value of newHighScore to the high score file
	m_highScoreFileWrite.open( m_scoreFile );
	m_highScoreFileWrite << newHighScore;
	m_highScoreFileWrite.close( );
}
