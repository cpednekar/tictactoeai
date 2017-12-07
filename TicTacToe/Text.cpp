#include "Text.h"

Text::Text()
{
	m_rectSource.x = 0;
	m_rectSource.y = 0;
	m_rectSource.w = 8;
	m_rectSource.h = 8;

	m_rectTarget.x = 0;
	m_rectTarget.y = 0;
	m_rectTarget.w = 16;
	m_rectTarget.h = 16;

	m_fontSize = 16;
}

Text::~Text()
{
	delete FONT;
	FONT = NULL;
}

void Text::Draw(SDL_Renderer* renderer, std::string textString, int xOffset, int yOffset, int fontSize)
{
	this->m_fontSize = fontSize;

	unsigned int characterIndex = 0;
	for(characterIndex = 0; characterIndex < textString.size(); characterIndex++){
		m_rectSource.x = GetCharacterScreenPos(textString.at(characterIndex));

		m_rectTarget.x = xOffset + (m_fontSize * characterIndex);
		m_rectTarget.y = yOffset;
		m_rectTarget.w = m_fontSize;
		m_rectTarget.h = m_fontSize;
		FONT->Draw(renderer, m_rectSource, m_rectTarget);
	}
}

void Text::Draw(SDL_Renderer* renderer, std::string textString, int xOffset, int yOffset, int fontSize, int colorKeyR, int colorKeyG, int colorKeyB)
{
	this->m_fontSize = fontSize;

	unsigned int characterIndex = 0;
	for(characterIndex = 0; characterIndex < textString.size(); characterIndex++){
		SDL_SetTextureColorMod(FONT->GetImage(), colorKeyR, colorKeyG, colorKeyB);
		m_rectSource.x = GetCharacterScreenPos(textString.at(characterIndex));

		m_rectTarget.x = xOffset + (m_fontSize * characterIndex);
		m_rectTarget.y = yOffset;
		m_rectTarget.w = m_fontSize;
		m_rectTarget.h = m_fontSize;
		FONT->Draw(renderer, m_rectSource, m_rectTarget);
		SDL_SetTextureColorMod(FONT->GetImage(), 255, 255, 255);
	}
}


int Text::GetTextWidth(std::string textString, int fontSize)
{
	int textWidth = textString.size() * fontSize;
	return textWidth;
}

int Text::GetCharacterScreenPos(int asciiIndex)
{
	//Bitmap font contains only Capital characters.
	//Bitmap font has chars '+'(43) to 'Z'(90) in order from 2nd char onwards. 
	if(asciiIndex >= 43 && asciiIndex < 91){
		return ((asciiIndex - 43) * m_rectSource.w) + m_rectSource.w;
	}
	
	//v w x y z are mapped to input last 5 characters viz. ",_,play button,x,!
	if(asciiIndex >= 118 && asciiIndex < 123){
		return ((asciiIndex - 70) * m_rectSource.w) + m_rectSource.w;
	}

	//1st character is space.
	return 0;
}

void Text::SetFont(SDL_Renderer* renderer, std::string fileName)
{
	FONT = new CIMG(fileName, renderer, 255, 0, 255);		//Set pink pixels of font bitmap to transparent
}

