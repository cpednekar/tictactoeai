#include "Menu.h"
#include "CFG.h"

Menu::Menu()
{
	int m_iActiveMenuOption = 0;
	int NumOfMenuOption = 0;
}

Menu::~Menu()
{
	for(std::vector<MenuOption*>::iterator iter = m_listMenuOptions.begin(); iter != m_listMenuOptions.end(); iter++)
	{
		delete *iter;
		*iter = NULL;
	}
}

void Menu::UpdateActiveMenuOption(Directions direction)
{
	switch(direction)
	{
		case Direction_Up:
			m_iActiveMenuOption = ((m_iActiveMenuOption - 1 < 0) ? (m_iNumMenuOptions - 1) : (m_iActiveMenuOption - 1));
			break;
		case Direction_Down:
			m_iActiveMenuOption = ((m_iActiveMenuOption + 1 >= m_iNumMenuOptions) ? 0 : (m_iActiveMenuOption + 1));
			break;
		default:
			break;
	}
}

void Menu::Draw(SDL_Renderer* rR)
{
	for(std::vector<MenuOption*>::iterator iter = m_listMenuOptions.begin(); iter != m_listMenuOptions.end(); iter++)
	{
		if((*iter) == m_listMenuOptions[m_iActiveMenuOption]){
			CFG::textRenderer->Draw(rR, (*iter)->GetText(), (*iter)->GetXPos(), (*iter)->GetYPos(), 16, 255, 0, 0);
		}
		else{
			CFG::textRenderer->Draw(rR, (*iter)->GetText(), (*iter)->GetXPos(), (*iter)->GetYPos(), 16, 255, 255, 255);
		}
	}
	
}

