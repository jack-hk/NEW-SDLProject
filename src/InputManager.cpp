#include "InputManager.h"

void InputManager::initialize()
{
	_keyboardState = SDL_GetKeyboardState(NULL);
	_previousKeyboardState = (Uint8*)malloc(SDL_NUM_SCANCODES);
	std::cout << "Succesfully initialized InputManager..." << std::endl;
}

void InputManager::update()
{ 
	SDL_memcpy((void*)_previousKeyboardState, _keyboardState, SDL_NUM_SCANCODES);
}

void InputManager::quit()
{
	free((void*)_previousKeyboardState);
	std::cout << "Quitted InputManager..." << std::endl;
}

bool InputManager::getKey(SDL_Scancode key)
{
	return _keyboardState[key];
}

bool InputManager::getKeyDown(SDL_Scancode key)
{
	return _keyboardState[key] && !(_previousKeyboardState[key]);
}

bool InputManager::getKeyUp(SDL_Scancode key)
{
	return !(_keyboardState[key]) && _previousKeyboardState[key];
}