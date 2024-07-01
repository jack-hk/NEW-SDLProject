#pragma once
#include <iostream>
#include <SDL.h>

class InputManager
{
public:
	void initialize();
	void update();
	void quit();

	bool getKey(SDL_Scancode key);
	bool getKeyDown(SDL_Scancode key);
	bool getKeyUp(SDL_Scancode key);

private:
	const Uint8* _keyboardState;
	const Uint8* _previousKeyboardState;
};

