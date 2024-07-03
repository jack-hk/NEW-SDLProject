#pragma once
#include "Character.h"
#include "Projectile.h"
#include "InputManager.h"

class Player : public Character
{
public:
	Player(SDL_Rect rect, bool isMovable, SDL_Texture* texture, int hitPoints);
	~Player();

	void movementInput(InputManager input);
	void fireProjectile(InputManager input, SDL_Texture* projectTexture);

	inline std::vector<Projectile*> getProjectiles() { return projectiles; }
private:
	std::vector<Projectile*> projectiles;
};