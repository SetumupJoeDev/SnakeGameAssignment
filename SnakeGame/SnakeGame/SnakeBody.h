#ifndef SNAKE_BODY_H
#define SNAKE_BODY_H

class SnakeBody 
{
private:
	//Chars
	char m_bodyAvatar;
	//Integers
	int m_xCoord;
	int m_yCoord;
public:
	SnakeBody();

	char getAvatar() { return m_bodyAvatar; }
	int  getXCoord() { return m_xCoord; }
	int  getYCoord() { return m_yCoord; }

	void update();
	void render();
};

#endif // !SNAKE_BODY_H
