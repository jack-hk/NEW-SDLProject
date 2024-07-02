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

void CollisionManager::resolveCollision(Collidable* a, Collidable* b)
{
    SDL_Rect rectA = a->getBody();
    SDL_Rect rectB = b->getBody();

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
            a->transform(Vector2D(rectA.x + overlapX, rectA.y));
        }
        else
        {
            a->transform(Vector2D(rectA.x - overlapX, rectA.y));
        }
    }
    else
    {
        if (fromTop)
        {
            a->transform(Vector2D(rectA.x, rectA.y + overlapY));
        }
        else
        {
            a->transform(Vector2D(rectA.x, rectA.y - overlapY));
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
			if (CollisionManager::AABB(CollisionManager::colliders[x]->getBody(), CollisionManager::colliders[y]->getBody()))
			{
				CollisionManager::colliders[x]->SetIsColliding(true);
				CollisionManager::colliders[y]->SetIsColliding(true);
				std::cout << "[ColSys]: Box Collision Detected!" << std::endl;
                               resolveCollision(colliders[x], colliders[y]);
			}
			else
			{
				CollisionManager::colliders[x]->SetIsColliding(false);
				CollisionManager::colliders[y]->SetIsColliding(false);
			}
		}
	}
}