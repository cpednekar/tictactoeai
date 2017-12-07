#include "Player.h"

Player::Player(std::string name, Symbols symbol)
{
	m_name = name;
	m_symbol = symbol;
}

Player::~Player()
{}

void Player::SetSymbol(Symbols symbol)
{
	m_symbol = symbol;
}

Symbols* Player::GetSymbol()
{
	return &m_symbol;
}


std::string Player::ToString()
{
	return (m_name + " " + "<" + ((m_symbol == Symbol_X) ? "X" : "O") + ">" );
}