#pragma once

#ifndef TEXT_H
#define TEXT_H

#include "header.h"
#include "CIMG.h"

class Text
{
private:
	CIMG* FONT;

	SDL_Rect m_rectSource;
	SDL_Rect m_rectTarget;

	int m_fontSize;
	
	int GetCharacterScreenPos(int asciiIndex);

public:
	Text();
	~Text();

	void Draw(SDL_Renderer* renderer, std::string textString, int xOffset, int yOffset, int fontSize = 16);
	void Draw(SDL_Renderer* renderer, std::string textString, int xOffset, int yOffset, int fontSize = 16, int colorKeyR = 255, int colorKeyG = 255, int colorKeyB = 255);

	int GetTextWidth(std::string textString, int fontSize = 16);

	void SetFont(SDL_Renderer* renderer, std::string fileName);
};


#endif