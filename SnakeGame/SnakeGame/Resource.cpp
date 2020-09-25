#include <iostream>
#include <Windows.h>

#include "Resource.h"

void GoToXY(int x, int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { (SHORT)x, (SHORT)y };
	//Sets the position of the cursor in the console to the x and y values passed through in the method's arguments
	SetConsoleCursorPosition(hStdout, position);
}

void DrawChar(char c, int xCoord, int yCoord)
{
	//Moves the cursor to the x and y coordinates passed through in the method's arguments
	GoToXY(xCoord, yCoord);
	//Draws the character defined in the method's arguments at the X and Y coordinates defined in the method's arguments
	std::cout << c;
}