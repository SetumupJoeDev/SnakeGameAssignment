#ifndef MENURENDERER_H
#define MENURENDERER_H

#include <iostream>
#include <string.h>

#include "Vector2.h"

class MenuRenderer
{
private:
	//Enums
	enum class menuOptions{ playClassic, playAdventure, clearScore, quitGame };
	menuOptions m_currentMenuOption;
	//Integers
	int m_defaultTextColour;
	int m_highlightedTextColour;
	//Strings
	std::string m_titleText;
	std::string m_welcomeText;
	std::string m_optionOneText;
	std::string m_optionTwoText;
	std::string m_optionThreeText;
	std::string m_optionFourText;
	//Vectors
	Vector2 m_menuTitlePosition;
	Vector2 m_welcomeTextPosition;
	Vector2 m_highScorePosition;
	Vector2 m_menuOptionOnePosition;
	Vector2 m_menuOptionTwoPosition;
	Vector2 m_menuOptionThreePosition;
	Vector2 m_menuOptionFourPosition;
	//Methods
	void renderTitleAndWelcome( );
	void renderMenuOptions( );
public:
	//Constructor
	MenuRenderer( );
	//Setters and Getters
	void setCurrentOption( int newOption ){ m_currentMenuOption = (menuOptions )newOption; }
	//Methods
	void renderMainMenu( );
};

#endif