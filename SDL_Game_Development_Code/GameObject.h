#ifndef __GameObject__
#define __GameObject__

#include "SDL.h"
#include "SDL_Image.h"

#include "TextureManager.h"
#include "LoaderParams.h"

#include <string>
#include <map>

class GameObject
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
protected:
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};

#endif