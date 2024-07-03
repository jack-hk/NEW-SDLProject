#include "objects/Flag.h"

Flag::Flag(SDL_Rect rect, bool isMovable, const char* tag, SDL_Texture* texture) : Collectible(rect, isMovable, tag, texture)
{
}

void Flag::update()
{
	if (!touchingCollider) return;
	if (isColliding && touchingCollider->getTag() == "PlayerWeapon")
	{
		isCollected = true;
		std::cout << "[INFO] YOU WON!" << std::endl;
		std::cout << "[INFO] You got to the flag, survived the feline beast and escaped the warehouse! Wooohoo!" << std::endl;
	}
}