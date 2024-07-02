#include "Game.h"

bool Game::initialize()
{
	if (!graphics.initialize(WINDOW_TITLE, WINDOWSIZE_WIDTH, WINDOWSIZE_HEIGHT, WINDOWCOLOR_RED, WINDOWCOLOR_GREEN, WINDOWCOLOR_BLUE, WINDOWCOLOR_ALPHA))
	{
		std::cout << "Failed to initialize graphics!" << std::endl;
		return false;
	} else std::cout << "Succesfully initialized GraphicsManager..." << std::endl;

	input.initialize();

	std::cout << "Game has now been initialized!" << std::endl;
	std::cout << "=================================" << std::endl;
	return true;
}

void Game::run()
{
	std::cout << "Game is running..." << std::endl;
	isRunning = true;
	SDL_Event _sdlEvent;

	SDL_Texture* tex = graphics.loadTexture("assets/placeholder1.png");
	Visible go1(SDL_Rect(80, 100, 70, 70), tex);
	Visible go2(SDL_Rect(300, 550, 70, 70), tex);
	collision.addCollider(&go1);
	collision.addCollider(&go2);
	while (isRunning)
	{
		input.update();
		collision.update();
		graphics.clearRenderer();
		go1.draw(graphics.getRenderer());
		go2.draw(graphics.getRenderer());
		graphics.presentRenderer();

		while (SDL_PollEvent(&_sdlEvent))
		{
			switch (_sdlEvent.type)
			{
			case SDL_QUIT:
				std::cout << "=================================" << std::endl;
				std::cout << "Game quitted..." << std::endl;
				isRunning = false;
				break;
			}
		}
		// Input movement, for the demostration.
		if (input.getKey(SDL_SCANCODE_W))
		{
			go1.transform(go1.getPosition() + (Vector2D(0, -1)));
		}
		if (input.getKey(SDL_SCANCODE_A))
		{
			go1.transform(go1.getPosition() + (Vector2D(-1, 0)));
		}
		if (input.getKey(SDL_SCANCODE_S))
		{
			go1.transform(go1.getPosition() + (Vector2D(0, 1)));
		}
		if (input.getKey(SDL_SCANCODE_D))
		{
			go1.transform(go1.getPosition() + (Vector2D(1, 0)));
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