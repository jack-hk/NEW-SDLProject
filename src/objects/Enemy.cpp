#include "objects/Enemy.h"

Enemy::Enemy(SDL_Rect rect, bool isMovable, const char* tag, SDL_Texture* texture, int hitPoints) : Character(rect, isMovable, tag, texture, hitPoints) {}

void Enemy::update()
{
	if (!touchingCollider) return;
	if (isColliding && touchingCollider->getTag() == "PlayerWeapon")
	{
		std::cout << "Cat: OUCH" << std::endl;
	}
}