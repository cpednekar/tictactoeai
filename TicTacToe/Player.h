#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "header.h"
#include "Constants.h"

class Player
{
private:
	std::string m_name;
	Symbols m_symbol;
public:
	Player(std::string name, Symbols symbol);
	~Player();
	void SetSymbol(Symbols symbol);
	Symbols* GetSymbol();
	std::string ToString();
};


#endif