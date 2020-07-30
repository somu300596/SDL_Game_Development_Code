#ifndef __Enemy__
#define __Enemy__

#include "SDLGameObject.h"
#include "Player.h"
#include "GameObjectFactory.h"

class Enemy : public SDLGameObject
{
public:
	Enemy();
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams* pParams);
};

class EnemyCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Player();
	}
};

#endif