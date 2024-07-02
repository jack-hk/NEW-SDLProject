#include "CollisionManager.h"

bool CollisionManager::AABB(SDL_Rect a, SDL_Rect b)
{
	if (a.x < b.x + b.w &&
		a.x + a.w > b.x &&
		a.y < b.y + b.h &&
		a.y + a.h > b.y)
	{
		return true;
	}
	return false;
}

void CollisionManager::resolveCollision(Collidable* collidee, Collidable* collider)
{

	SDL_Rect rectA = collidee->getRect();
	SDL_Rect rectB = collider->getRect();

	int overlapLeft = (rectB.x + rectB.w) - rectA.x;
	int overlapRight = (rectA.x + rectA.w) - rectB.x;
	int overlapTop = (rectB.y + rectB.h) - rectA.y;
	int overlapBottom = (rectA.y + rectA.h) - rectB.y;

	bool fromLeft = overlapLeft < overlapRight;
	bool fromTop = overlapTop < overlapBottom; 

	int overlapX = fromLeft ? overlapLeft : overlapRight;
	int overlapY = fromTop ? overlapTop : overlapBottom;

	if (overlapX < overlapY)
	{
		if (fromLeft)
		{
			if (collidee->getIsMovable())
			{
				collidee->transform(Vector2D(rectA.x + overlapX, rectA.y));
			}
			else
			{
				collider->transform(Vector2D(rectB.x - overlapX, rectA.y));
			}
		}
		else
		{
			if (collidee->getIsMovable())
			{
				collidee->transform(Vector2D(rectA.x - overlapX, rectA.y));
			}
			else
			{
				collider->transform(Vector2D(rectB.x + overlapX, rectA.y));
			}
		}
	}
	else
	{
		if (fromTop)
		{
			if (collidee->getIsMovable())
			{
				collidee->transform(Vector2D(rectA.x, rectA.y + overlapY));
			}
			else
			{
				collider->transform(Vector2D(rectA.x, rectB.y - overlapY));
			}
		}
		else
		{
			if (collidee->getIsMovable())
			{
				collidee->transform(Vector2D(rectA.x, rectA.y - overlapY));
			}
			else
			{
				collider->transform(Vector2D(rectA.x, rectB.y + overlapY));
			}
		}
	}
}

void CollisionManager::update()
{
	for (size_t y = 0; y < CollisionManager::colliders.size(); y++)
	{
		for (size_t x = y + 1; x < CollisionManager::colliders.size(); x++)
		{
			if (x == y) continue;
			if (CollisionManager::AABB(CollisionManager::colliders[x]->getRect(), CollisionManager::colliders[y]->getRect()))
			{
				CollisionManager::colliders[x]->setIsColliding(true);
				CollisionManager::colliders[y]->setIsColliding(true);
				resolveCollision(colliders[x], colliders[y]);
			}
			else
			{
				CollisionManager::colliders[x]->setIsColliding(false);
				CollisionManager::colliders[y]->setIsColliding(false);
			}
		}
	}
}