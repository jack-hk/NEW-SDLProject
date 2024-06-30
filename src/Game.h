#pragma once
#include <iostream>
#include <SDL.h>

// Singleton Class
class Game
{
public:
	static Game& getInstance()
	{
		static Game instance;
		return instance;
	}
	Game(Game const&) = delete;
	void operator=(Game const&) = delete;

	bool initialize();
private:
	Game() {}
};