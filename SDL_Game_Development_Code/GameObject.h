#ifndef __GameObject__
#define __GameObject__

#include "SDL.h"
#include "SDL_Image.h"

#include "TextureManager.h"

#include <string>
#include <map>

class GameObject
{
public:
	
	virtual void load(int x, int y, int width, int height, std::string textureID);
	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();

protected:
	
	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};

#endif