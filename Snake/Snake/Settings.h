#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>
#include <string.h>

namespace Settings
{
	namespace Snake
	{
		//Length Settings
		const int m_snakeStartLength = 4;
		const int m_snakeLengthModifier = 4;
		const int m_maxLength = 100;
		//Speed Settings
		const int m_snakeStartSpeedX = 0;
		const int m_snakeStartSpeedY = 0;
		//Position Settings
		const int m_snakeStartPosX = 12;
		const int m_snakeStartPosY = 12;
		//Colour Settings
		const int m_snakeColourOne = 2;
		const int m_snakeColourTwo = 10;
		//Character Settings
		const char m_snakeChar = ( char ) 178;
	}

	namespace Fruit
	{
		const char m_fruitChar = ( char ) 64;
		const int m_fruitColour = 4;
	}

	namespace Game
	{
		const int m_sleepTimer = 100;
		const int m_fruitScoreIncrease = 10;
		const int m_backgroundColour = 0;
	}

	namespace Level
	{
		const int m_topBoundary = 1;
		const int m_bottomBoundary = 26;
		const int m_leftBoundary = 1;
		const int m_rightBoundary = 101;
		const int m_wallColour = 1;
	}

	namespace Menu
	{
		namespace TextPositions
		{
			//Title Text Position
			const int m_titleX = 40;
			const int m_titleY = 1;
			//Welcome Text Position
			const int m_welcomeX = 39;
			const int m_welcomeY = 3;
			//High Score position
			const int m_highScoreX = 45;
			const int m_highScoreY = 5;
			//Menu Option One position
			const int m_optionOneX = 43;
			const int m_optionOneY = 7;
			//Menu Option Two Position
			const int m_optionTwoX = 42;
			const int m_optionTwoY = 9;
			//Menu Option Three Position
			const int m_optionThreeX = 44;
			const int m_optionThreeY = 11;
			//Menu Option Four Position
			const int m_optionFourX = 47;
			const int m_optionFourY = 13;
		}
		namespace TextToDisplay
		{
			//Game Title Text
			const std::string m_titleText		= "Welcome to SERPENT SURGE!";
			//Welcome Text
			const std::string m_welcomeText		= "Select any option to begin!";
			//Option One Text
			const std::string m_optionOneText	= "1. Play Classic Mode";
			//Option Two Text
			const std::string m_optionTwoText	= "2. Play Adventure Mode";
			//Option Three Text
			const std::string m_optionThreeText = "3. Clear High Score";
			//Option Four Text
			const std::string m_optionFourText	= "4. Quit Game";
		}
		namespace TextColours
		{
			//Default Text Colour
			const int m_defaultColour = 15;
			//Highlighted Text Colour
			const int m_highlightedColour = 23;
		}
	}
}

#endif // !SETTINGS_H
