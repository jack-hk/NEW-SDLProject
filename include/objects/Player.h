#pragma once
#include "Character.h"
#include "Projectile.h"
#include "InputManager.h"
#include "CollisionManager.h"

class Player : public Character
{
public:
	Player(SDL_Rect rect, bool isMovabletag, const char* tag, SDL_Texture* texture, int hitPoints);
	~Player();

	void movementInput(InputManager input);
	void fireProjectile(InputManager input, CollisionManager collision, SDL_Texture* projectTexture);

	inline std::vector<Projectile*> getProjectiles() { return projectiles; }
private:
	std::vector<Projectile*> projectiles;
};