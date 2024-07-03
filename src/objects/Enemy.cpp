#include "objects/Enemy.h"

Enemy::Enemy(SDL_Rect rect, bool isMovable, const char* tag, SDL_Texture* texture, int hitPoints) : Character(rect, isMovable, tag, texture, hitPoints) {}

void Enemy::update()
{
	if (!touchingCollider) return;
	if (isColliding && touchingCollider->getTag() == "PlayerWeapon")
	{
		if (hitPoints == 0)
		{
			std::cout << "[INFO] Cat is KOed!" << std::endl;
		}
		else if (hitPoints < 1) 
		{ 
			return;
		}
		std::cout << "[INFO] Cat's HP: " << hitPoints << std::endl;
		hitPoints -= 1;
	}
}