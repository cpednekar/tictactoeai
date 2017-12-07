#include "MenuOption.h"

MenuOption::MenuOption(int xPos, int yPos, std::string textString)
{
	m_xPos = xPos;
	m_yPos = yPos;
	m_textString = textString;
}

int MenuOption::GetXPos()
{
	return m_xPos;
}

int MenuOption::GetYPos()
{
	return m_yPos;
}

std::string MenuOption::GetText()
{
	return m_textString;
}