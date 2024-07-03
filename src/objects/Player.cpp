#include "objects/Player.h"

Player::Player(SDL_Rect rect, bool isMovable, const char* tag, SDL_Texture* texture, int hitPoints) : Character(rect, isMovable, tag, texture, hitPoints)
{
	std::cout << "[INFO] Your HP: " << hitPoints << std::endl;
}

Player::~Player()
{
	for (auto& obj : projectiles)
	{
		Projectile* projectile = dynamic_cast<Projectile*>(obj);
		if (projectile)
		{
			delete obj;
		}
	}
	projectiles.clear();
	std::cout << "[Player]: Deleted and cleared projectiles... (size is: " << projectiles.size() << ")" << std::endl;
}

void Player::movementInput(InputManager input)
{
	if (input.getKey(SDL_SCANCODE_W))
	{
		transform(getPosition() + (Vector2D(0, -3)));
	}
	if (input.getKey(SDL_SCANCODE_A))
	{
		transform(getPosition() + (Vector2D(-3, 0)));
	}
	if (input.getKey(SDL_SCANCODE_S))
	{
		transform(getPosition() + (Vector2D(0, 3)));
	}
	if (input.getKey(SDL_SCANCODE_D))
	{
		transform(getPosition() + (Vector2D(3, 0)));
	}
}

void Player::fireProjectile(InputManager input, CollisionManager collision, SDL_Texture* projectTexture)
{
	Vector2D direction = { 0, 0 };
	SDL_Rect spawnRect = { rect.x, rect.y, 16, 16 };

	if (input.getKeyDown(SDL_SCANCODE_UP))
	{
		direction.y = -1;
		direction.x = 0;
	}
	else if (input.getKeyDown(SDL_SCANCODE_DOWN))
	{
		direction.y = 1;
		direction.x = 0;
	}
	else if (input.getKeyDown(SDL_SCANCODE_LEFT))
	{
		direction.x = -1;
		direction.y = 0;
	}
	else if (input.getKeyDown(SDL_SCANCODE_RIGHT))
	{
		direction.x = 1;
		direction.y = 0;
	}
	else
	{
		// No key pressed, return early
		return;
	}

	Projectile* newProjectile = new Projectile(spawnRect, projectTexture, "PlayerWeapon", direction);
	collision.addCollider(newProjectile);
	projectiles.push_back(newProjectile);
}