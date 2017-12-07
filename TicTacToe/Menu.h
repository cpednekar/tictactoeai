#pragma once

#ifndef MENU_H
#define MENU_H

#include "MenuOption.h"

class Menu
{
private:

protected:

	enum Directions
	{
		Direction_Up,
		Direction_Down
	};

public:
	
	Menu();
	~Menu();

	std::vector<MenuOption*> m_listMenuOptions;		//List of menu options

	int m_iActiveMenuOption;
	int m_iNumMenuOptions;

	void UpdateActiveMenuOption(Directions direction);
	void Draw(SDL_Renderer* rR);
};

#endif