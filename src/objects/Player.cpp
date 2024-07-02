#include "objects/Player.h"

Player::Player(SDL_Rect rect, bool isMovable, SDL_Texture* texture, int hitPoints) : Character(rect, isMovable, texture, hitPoints) {}

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