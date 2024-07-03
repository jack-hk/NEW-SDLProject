#pragma once
#include <iostream>
#include "objects/Collidable.h"

class CollisionManager
{
public:
	void update();
	void clean();

	void addCollider(Collidable* collider) { colliders.push_back(collider); }
	static bool AABB(SDL_Rect a, SDL_Rect b);
private:
	static inline std::vector<Collidable*> colliders;

	void resolveCollision(Collidable* a, Collidable* b);
};
