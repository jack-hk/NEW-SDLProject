#include "Game.h"

bool Game::initialize()
{
	if (!graphics.initialize(WINDOW_TITLE, WINDOWSIZE_WIDTH, WINDOWSIZE_HEIGHT, WINDOWCOLOR_RED, WINDOWCOLOR_GREEN, WINDOWCOLOR_BLUE, WINDOWCOLOR_ALPHA))
	{
		std::cout << "Failed to initialize GraphicsManager!" << std::endl;
		return false;
	}

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

for (int i = 0; i < rows; ++i) //floor, has no collider
{
	for (int j = 0; j < cols; ++j)
	{
		int x = startX + j * (width);
		int y = startY + i * (height);

		Visible* wall = new Visible(SDL_Rect{ x, y, width, height }, false, "", floor);

		visibleGameObjects.push_back(wall);
	}
}

for (int i = 0; i < 6; ++i)
{
	int x = startX + i * (width);
	int y = startY;

	Visible* wall = new Visible(SDL_Rect{ x, y, width, height }, false, "", wall1);

	collision.addCollider(wall);

	visibleGameObjects.push_back(wall);
}

for (int i = 0; i < 3; ++i)
{
	int x = startX + i * (width + spacing);
	int y = 200;

	Visible* wall = new Visible(SDL_Rect{ x, y, width, height }, false, "", wall2);

	collision.addCollider(wall);

	visibleGameObjects.push_back(wall);
}

for (int i = 0; i < 3; ++i)
{
	int x = 100 + i * (width + spacing);
	int y = 400;

	Visible* wall = new Visible(SDL_Rect{ x, y, width, height }, false, "", wall2);

	collision.addCollider(wall);

	visibleGameObjects.push_back(wall);
}
Visible* wall3 = new Visible(SDL_Rect(501, 200, width, height), false, "", wall2);
collision.addCollider(wall3);
visibleGameObjects.push_back(wall3);
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
	SDL_Texture* flagTex = graphics.loadTexture("assets/flag.png");
	SDL_Texture* winTex = graphics.loadTexture("assets/win.png");

	buildLevel(brickTex, crateTex, floorTex);

	Player player(SDL_Rect(50, 550, 40, 40), true, "Player", mouseTex, 100);
	collision.addCollider(&player);

	Enemy enemy1(SDL_Rect(300, 100, 90, 90), true, "Enemy", catTex, 100);
	collision.addCollider(&enemy1);

	Flag flag(SDL_Rect(550, 120, 40, 40), false, "", flagTex);
	collision.addCollider(&flag);

	Visible winSign(SDL_Rect(200, 200, 200, 200), false, "", winTex);

	while (isRunning)
	{
		frameStart = SDL_GetTicks();

		collision.update();

		player.fireProjectile(input, collision, crateTex);
		player.checkToDestroyProjectiles(collision);
		player.updateProjectiles();

		input.update();
		player.movementInput(input);
		enemy1.update();
		if (enemy1.getHitPoints() < 1 && collision.findCollider(&enemy1)) collision.removeCollider(&enemy1);
		if (!flag.getCollected()) flag.update();

		graphics.clearRenderer();

		if (!flag.getCollected()){

		for (auto& obj : visibleGameObjects)
		{
			if (obj)
			{
				obj->draw(graphics.getRenderer());
			}
		}

		for (auto& obj : player.getProjectiles())
		{
			obj->draw(graphics.getRenderer());
		}

		player.draw(graphics.getRenderer());
		if (enemy1.getHitPoints() > 0)enemy1.draw(graphics.getRenderer());
		}

		if (!flag.getCollected()) flag.draw(graphics.getRenderer());

		if (flag.getCollected()) winSign.draw(graphics.getRenderer());

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
	collision.clean();
	SDL_Quit();
	std::cout << "Cleaned SDL subsystems!" << std::endl;
}