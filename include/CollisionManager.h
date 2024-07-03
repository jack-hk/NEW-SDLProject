#pragma once
#include <iostream>
#include "objects/Collidable.h"

class CollisionManager
{
public:
	void update();
	void clean();

	inline void addCollider(Collidable* collider) { colliders.push_back(collider); }
	inline bool findCollider(Collidable* collider)
	{
		auto it = std::find(colliders.begin(), colliders.end(), collider);
		if (it != colliders.end()) return true;
		else return false;
	}
	inline void removeCollider(Collidable* collider)
	{
		auto it = std::find(colliders.begin(), colliders.end(), collider);
		if (it != colliders.end())
		{
			colliders.erase(it);
		}
	}
	static bool AABB(SDL_Rect a, SDL_Rect b);
private:
	static inline std::vector<Collidable*> colliders;

	void resolveCollision(Collidable* a, Collidable* b);
};
