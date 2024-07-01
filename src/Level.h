#pragma once
#include <vector>
#include "Game.h"
#include "GameObject.h"

class Level
{
public:
	Level();
	void update();
	void addGameObject(GameObject* gameObject);

private:
	std::vector<GameObject*> _gameObjects;
};