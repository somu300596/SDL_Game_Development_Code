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

	~Game() {}

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit() { m_bRunning = false; }

	bool running() { return m_bRunning; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

private:

	Game() {}
	
	// create the s_pInstance member variable
	static Game* s_pInstance;
	
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
	std::vector<GameObject*> m_gameObjects;
	
	int m_currentFrame;

	bool m_bRunning;
};
// create the typedef
typedef Game TheGame;
#endif // __Game__