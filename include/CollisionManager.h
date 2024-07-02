#pragma once
#include "objects/Collidable.h"

class CollisionManager
{
public:
	void update();
	void addCollider(Collidable* collider) { colliders.push_back(collider); }
	static bool AABB(SDL_Rect a, SDL_Rect b);
private:
	static inline std::vector<Collidable*> colliders;
};
