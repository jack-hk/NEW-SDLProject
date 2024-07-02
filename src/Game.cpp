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

	SDL_Texture* catTex = graphics.loadTexture("assets/cat.png");
	SDL_Texture* mouseTex = graphics.loadTexture("assets/mouse.png");
	SDL_Texture* brickTex = graphics.loadTexture("assets/brick.png");
	NonMovable go1(SDL_Rect(80, 100, 90, 90), catTex);
	NonMovable go2(SDL_Rect(300, 450, 40, 40), mouseTex);
	NonMovable go3(SDL_Rect(0, 0, 100, 100), brickTex);
	collision.addCollider(&go1);
	collision.addCollider(&go2);
	collision.addCollider(&go3);
	while (isRunning)
	{
		input.update();
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
		collision.update();
		graphics.clearRenderer();
		go1.draw(graphics.getRenderer());
		go2.draw(graphics.getRenderer());
		go3.draw(graphics.getRenderer());
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
	}
}

void Game::quit()
{
	input.quit();
	graphics.quit();
	SDL_Quit();
	std::cout << "Cleaned SDL subsystems!" << std::endl;
}