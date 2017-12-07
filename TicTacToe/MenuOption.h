#pragma once

#ifndef MENUOPTION_H
#define MENUOPTION_H

#include "header.h"

class MenuOption
{
private:
	int m_xPos, m_yPos;
	std::string m_textString;
public:
	MenuOption(int xPos, int yPos, std::string textString);
	int GetXPos();
	int GetYPos();
	std::string GetText();
};



#endif