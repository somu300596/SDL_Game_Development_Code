#include <vector>
#include <utility>

#include "SDL.h"
#include "Vector2D.h"

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new InputHandler();
		}

		return s_pInstance;
	}
	void update();
	void clean();

	//Joystick related member functions
	void initialiseJoysticks();
	bool joysticksInitialised() {
		return m_bJoysticksInitialised;
	}
	bool getMouseButtonState(int buttonNumber)
	{
		return m_mouseButtonStates[buttonNumber];
	}
	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);
	Vector2D getMousePosition()
	{
		return m_mousePosition;
	}

private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;

	//Joystick related member variables
	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksInitialised;
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
	const int m_joystickDeadZone = 10000;
	
	//Mouse related member variables
	std::vector<bool> m_mouseButtonStates;
	Vector2D m_mousePosition = {0,0};
};

typedef InputHandler TheInputHandler;