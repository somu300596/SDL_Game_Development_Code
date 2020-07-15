#include <vector>
#include <utility>

#include "SDL.h"
#include "Vector2D.h"

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
	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);
	bool getButtonState(int joy, int buttonNumber);

private:
	InputHandler() {}
	~InputHandler() {}
	static InputHandler* s_pInstance;

	//Joystick related member variables
	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksInitialised;
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
	const int m_joystickDeadZone = 10000;
	std::vector<std::vector<bool>> m_buttonStates;
	
};

typedef InputHandler TheInputHandler;