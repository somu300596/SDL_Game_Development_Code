#ifndef __Game__
#define __Game__

#include "SDL.h"
#include "SDL_Image.h"

#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

#include <iostream>
#include <vector>

class Game
{
public:

	Game() {}
	~Game() {}

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();

	bool running() { return m_bRunning; }

private:

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
	std::vector<GameObject*> m_gameObjects;
	
	int m_currentFrame;

	bool m_bRunning;
};

#endif // __Game__