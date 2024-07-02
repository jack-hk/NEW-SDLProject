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
	Uint32 frameStart, frameTime;

	SDL_Texture* catTex = graphics.loadTexture("assets/cat.png");
	SDL_Texture* mouseTex = graphics.loadTexture("assets/mouse.png");
	SDL_Texture* brickTex = graphics.loadTexture("assets/brick.png");

	Character player(SDL_Rect(300, 450, 40, 40), true, mouseTex, 5);
	collision.addCollider(&player);

	Visible enemy1(SDL_Rect(80, 100, 90, 90), true, catTex);
	collision.addCollider(&enemy1);

	Visible wall1(SDL_Rect(0, 0, 100, 100), false, brickTex);
	collision.addCollider(&wall1);

	std::cout << "HP: " << player.getHitPoints() << std::endl;

	while (isRunning)
	{
		frameStart = SDL_GetTicks();
		input.update();
		// Input movement, for the demostration.
		if (input.getKey(SDL_SCANCODE_W))
		{
			player.transform(player.getPosition() + (Vector2D(0, -1)));
		}
		if (input.getKey(SDL_SCANCODE_A))
		{
			player.transform(player.getPosition() + (Vector2D(-1, 0)));
		}
		if (input.getKey(SDL_SCANCODE_S))
		{
			player.transform(player.getPosition() + (Vector2D(0, 1)));
		}
		if (input.getKey(SDL_SCANCODE_D))
		{
			player.transform(player.getPosition() + (Vector2D(1, 0)));
		}
		collision.update();
		graphics.clearRenderer();

		player.draw(graphics.getRenderer());
		enemy1.draw(graphics.getRenderer());
		wall1.draw(graphics.getRenderer());

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

		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
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