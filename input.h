#pragma once

#include <map>



class Input
{
public:
	Input();
	~Input();

	enum class Button
	{
		QUIT,

		UP,
		DOWN,
		LEFT,
		RIGHT,

		INCREASE_SPEED,
		DECREASE_SPEED,
		RUNNING,
		ATTACKING,
		SHOW_CREDITS,
		DIEING,


		HELP_DISPLAY_INFORMATIONS,
		DEBUG_HIDE_IDS,
		DEBUG_SHOW_IDS
	};
	





	enum class Button_State
	{
		PRESSED,
		DOWN,
		RELEASED,
		UP
		
		
	};

	void get_input();
	bool is_button_state(Button type, Button_State state);

private:
	
	std::map<Button, Button_State> _button_state;
	
	
};