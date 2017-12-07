#pragma once

#ifndef CIMG_H
#define CIMG_H

#include "header.h"
#include "Constants.h"

class CIMG
{
private:
	SDL_Texture* m_textureImage;
	SDL_Rect m_rectTarget;

public:
	CIMG(void);
	CIMG(std::string fileName, SDL_Renderer* renderer);
	CIMG(std::string fileName, SDL_Renderer* renderer, int colorKeyR, int colorKeyG, int colorKeyB);		//Sets color key for pixels of given color
	~CIMG(void);

	void Draw(SDL_Renderer* renderer, int xOffset, int yOffset);
	void Draw(SDL_Renderer * renderer, SDL_Rect rectSourceCrop, SDL_Rect rectDestination);
	void Draw(SDL_Renderer* renderer, int xOffset, int yOffset, FlipTypes* flipType);
	
	SDL_Texture* GetImage();
	void SetImage(std::string fileName, SDL_Renderer* renderer);
	void SetImage(std::string fileName, SDL_Renderer* renderer, int colorKeyR, int colorKeyG, int colorKeyB);
	SDL_Rect GetTargetRect();
};


#endif