#include "MenuRenderer.h"

#include "Helpers.h"
#include "Settings.h"
#include "Vector2.h"

MenuRenderer::MenuRenderer( )
{
	//Text Colours
	m_highlightedTextColour = Settings::Menu::TextColours::m_highlightedColour;
	//Text Contents
	m_titleText = Settings::Menu::TextToDisplay::m_titleText;
	m_welcomeText = Settings::Menu::TextToDisplay::m_welcomeText;
	m_optionOneText = Settings::Menu::TextToDisplay::m_optionOneText;
	m_optionTwoText = Settings::Menu::TextToDisplay::m_optionTwoText;
	m_optionThreeText = Settings::Menu::TextToDisplay::m_optionThreeText;
	m_optionFourText = Settings::Menu::TextToDisplay::m_optionFourText;
	//Text Positions
	m_menuTitlePosition.setPosition( Settings::Menu::TextPositions::m_titleX, Settings::Menu::TextPositions::m_titleY );
	m_welcomeTextPosition.setPosition( Settings::Menu::TextPositions::m_welcomeX, Settings::Menu::TextPositions::m_welcomeY );
	m_menuOptionOnePosition.setPosition( Settings::Menu::TextPositions::m_optionOneX, Settings::Menu::TextPositions::m_optionOneY );
	m_menuOptionTwoPosition.setPosition( Settings::Menu::TextPositions::m_optionTwoX, Settings::Menu::TextPositions::m_optionTwoY );
	m_menuOptionThreePosition.setPosition( Settings::Menu::TextPositions::m_optionThreeX, Settings::Menu::TextPositions::m_optionThreeY );
	m_menuOptionFourPosition.setPosition( Settings::Menu::TextPositions::m_optionFourX, Settings::Menu::TextPositions::m_optionFourY );
}

void MenuRenderer::renderTitleAndWelcome( )
{
	//Draws the game's title and welcome text in their positions on screen
	DrawString( m_titleText, m_menuTitlePosition );
	DrawString( m_welcomeText, m_welcomeTextPosition );
}

void MenuRenderer::renderMenuOptions( )
{
	switch ( m_currentMenuOption )
	{
	case MenuRenderer::menuOptions::playClassic:
	{
		//Draws the menu options, with option one highlighted
		DrawString( m_optionOneText, m_menuOptionOnePosition, m_highlightedTextColour );
		ChangeHandleColour( );
		DrawString( m_optionTwoText, m_menuOptionTwoPosition );
		DrawString( m_optionThreeText, m_menuOptionThreePosition );
		DrawString( m_optionFourText, m_menuOptionFourPosition );
		break;
	}
	case MenuRenderer::menuOptions::playAdventure:
	{
		//Draws the menu options, with option two highlighted
		DrawString( m_optionOneText, m_menuOptionOnePosition );
		DrawString( m_optionTwoText, m_menuOptionTwoPosition, m_highlightedTextColour );
		ChangeHandleColour( );
		DrawString( m_optionThreeText, m_menuOptionThreePosition );
		DrawString( m_optionFourText, m_menuOptionFourPosition );
		break;
	}
	case MenuRenderer::menuOptions::clearScore:
	{
		//Draws the menu options, with option three highlighted
		DrawString( m_optionOneText, m_menuOptionOnePosition );
		DrawString( m_optionTwoText, m_menuOptionTwoPosition );
		DrawString( m_optionThreeText, m_menuOptionThreePosition, m_highlightedTextColour );
		ChangeHandleColour( );
		DrawString( m_optionFourText, m_menuOptionFourPosition );
		break;
	}
	case MenuRenderer::menuOptions::quitGame:
	{
		//Draws the menu options, with option four highlighted
		DrawString( m_optionOneText, m_menuOptionOnePosition );
		DrawString( m_optionTwoText, m_menuOptionTwoPosition );
		DrawString( m_optionThreeText, m_menuOptionThreePosition );
		DrawString( m_optionFourText, m_menuOptionFourPosition, m_highlightedTextColour );
		ChangeHandleColour( );
		break;
	}
	default:
	{
		//Prints an error message if none of the previous conditions are met
		std::cout << "Something has gone wrong. Please contact and administrator.";
		break;
	}
	}
}

void MenuRenderer::renderMainMenu( )
{
	renderTitleAndWelcome( );
	renderMenuOptions( );
}
