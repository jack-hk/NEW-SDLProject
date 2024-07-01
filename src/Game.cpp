#include "Game.h"

bool Game::initialize()
{
	if (!graphics.initialize(WINDOW_TITLE, WINDOWSIZE_WIDTH, WINDOWSIZE_HEIGHT, WINDOWCOLOR_RED, WINDOWCOLOR_GREEN, WINDOWCOLOR_BLUE, WINDOWCOLOR_ALPHA))
	{
		std::cout << "Failed to initialize graphics!" << std::endl;
		return false;
	} else std::cout << "Succesfully initialized GraphicsManager..." << std::endl;

	input.initialize();
}

void Game::run()
{
	std::cout << "Game is running..." << std::endl;
	isRunning = true;
	SDL_Event _sdlEvent;
	while (isRunning)
	{
		graphics.update();
		input.update();
		while (SDL_PollEvent(&_sdlEvent))
		{
			switch (_sdlEvent.type)
			{
			case SDL_QUIT:
				std::cout << "Game quitted..." << std::endl;
				isRunning = false;
				break;
			}
		}
	}
}

void Game::quit()
{
	input.quit();
	graphics.quit();
	SDL_Quit();
	std::cout << "Cleaned SDL subsystems!" << std::endl;
}