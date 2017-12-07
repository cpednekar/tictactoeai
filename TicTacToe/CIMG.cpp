#include "CIMG.h"

CIMG::CIMG()
{}

CIMG::CIMG(std::string fileName, SDL_Renderer* renderer)
{
	SetImage(fileName, renderer);
}

CIMG::CIMG(std::string fileName, SDL_Renderer* renderer, int colorKeyR, int colorKeyG, int colorKeyB)
{
	SetImage(fileName, renderer, colorKeyR, colorKeyG, colorKeyB);
}

CIMG::~CIMG()
{
	SDL_DestroyTexture(m_textureImage);
	m_textureImage = NULL;
}

void CIMG::Draw(SDL_Renderer* renderer, int xOffset, int yOffset)
{
	m_rectTarget.x = xOffset;
	m_rectTarget.y = yOffset;
	
	SDL_RenderCopy(renderer, m_textureImage, NULL, &m_rectTarget);
}

void CIMG::Draw(SDL_Renderer * renderer, SDL_Rect rectSource, SDL_Rect rectTarget)
{
	SDL_RenderCopy(renderer, m_textureImage, &rectSource, &rectTarget);
}

void CIMG::Draw(SDL_Renderer* renderer, int xOffset, int yOffset, FlipTypes* flipType)
{
	m_rectTarget.x = xOffset;
	m_rectTarget.y = yOffset;

	switch(*flipType)
	{
		case FlipType_Horizontal:
			SDL_RenderCopyEx(renderer, m_textureImage, NULL, &m_rectTarget, 180.0, NULL, SDL_FLIP_HORIZONTAL);
			break;
		case FlipType_Vertical:
			SDL_RenderCopyEx(renderer, m_textureImage, NULL, &m_rectTarget, 180.0, NULL, SDL_FLIP_VERTICAL);
			break;
		case FlipType_None:
			SDL_RenderCopy(renderer, m_textureImage, NULL, &m_rectTarget);
			break;
	}
}

void CIMG::SetImage(std::string fileName, SDL_Renderer* renderer)
{
	fileName = "files/images/" + fileName + ".bmp";
	SDL_Surface* loadedSurface = SDL_LoadBMP(fileName.c_str());

	m_textureImage = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	int width, height;

	SDL_QueryTexture(m_textureImage, NULL, NULL, &width, &height);

	m_rectTarget.x = 0;
	m_rectTarget.y = 0;
	m_rectTarget.w = width;
	m_rectTarget.h = height;

	SDL_FreeSurface(loadedSurface);
}

void CIMG::SetImage(std::string fileName, SDL_Renderer* renderer, int colorKeyR, int colorKeyG, int colorKeyB)
{
	fileName = "files/images/" + fileName + ".bmp";
	SDL_Surface* loadedSurface = SDL_LoadBMP(fileName.c_str());
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, colorKeyR, colorKeyG, colorKeyB));

	m_textureImage = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	int width, height;

	SDL_QueryTexture(m_textureImage, NULL, NULL, &width, &height);

	m_rectTarget.x = 0;
	m_rectTarget.y = 0;
	m_rectTarget.w = width;
	m_rectTarget.h = height;

	SDL_FreeSurface(loadedSurface);
}

SDL_Texture* CIMG::GetImage()
{
	return m_textureImage;
}

SDL_Rect CIMG::GetTargetRect()
{
	return m_rectTarget;
}
