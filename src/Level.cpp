#include "Level.h"

Level::Level()
{
	Game::levels.push_back(this);
}

void Level::update()
{
	for (size_t i = 0; i < _gameObjects.size(); i++)
	{
		_gameObjects[i]->updateComponents();
	}
}

void Level::addGameObject(GameObject* gameObjectToAdd)
{
	_gameObjects.push_back(gameObjectToAdd);
}
