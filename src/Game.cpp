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

void Game::buildLevel(SDL_Texture* wall1, SDL_Texture* wall2, SDL_Texture* floor)
{
	int startX = 0;
	int startY = 0;
	int width = 100;
	int height = 100;
	int spacing = 100;
	int rows = 6;
	int cols = 6;

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			int x = startX + j * (width);
			int y = startY + i * (height);

			Visible* wall = new Visible(SDL_Rect{ x, y, width, height }, false, floor);

			visibleGameObjects.push_back(wall);
		}
	}

	for (int i = 0; i < 6; ++i)
	{
		int x = startX + i * (width);
		int y = startY;

		Visible* wall = new Visible(SDL_Rect{ x, y, width, height }, false, wall1);

		collision.addCollider(wall);

		visibleGameObjects.push_back(wall);
	}

	for (int i = 0; i < 3; ++i)
	{
		int x = startX + i * (width + spacing);
		int y = 200;

		Visible* wall = new Visible(SDL_Rect{ x, y, width, height }, false, wall2);

		collision.addCollider(wall);

		visibleGameObjects.push_back(wall);
	}

	for (int i = 0; i < 3; ++i)
	{
		int x = 100 + i * (width + spacing);
		int y = 400;

		Visible* wall = new Visible(SDL_Rect{ x, y, width, height }, false, wall2);

		collision.addCollider(wall);

		visibleGameObjects.push_back(wall);
	}
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
	SDL_Texture* crateTex = graphics.loadTexture("assets/crate.png");
	SDL_Texture* floorTex = graphics.loadTexture("assets/floor.png");

	buildLevel(brickTex, crateTex, floorTex);

	Player player(SDL_Rect(300, 450, 40, 40), true, mouseTex, 5);
	collision.addCollider(&player);

	Visible enemy1(SDL_Rect(200, 200, 90, 90), true, catTex);
	collision.addCollider(&enemy1);

	Projectile projectile(SDL_Rect(280, 500, 20, 20), catTex, Vector2D(0,-1));

	std::cout << "HP: " << player.getHitPoints() << std::endl;
	while (isRunning)
	{
		frameStart = SDL_GetTicks();

		input.update();
		player.movementInput(input);
		projectile.update();
		collision.update();
		graphics.clearRenderer();

		for (auto& obj : visibleGameObjects)
		{
			Visible* visibleObj = dynamic_cast<Visible*>(obj);
			if (visibleObj)
			{
				visibleObj->draw(graphics.getRenderer());
			}
		}

		player.draw(graphics.getRenderer());
		enemy1.draw(graphics.getRenderer());
		projectile.draw(graphics.getRenderer());

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