#include "GameObject.h"

GameObject::GameObject(Vector2D go_position, int go_size)
{
	position.x = go_position.x;
	position.y = go_position.y;
	size = go_size;
}

GameObject::~GameObject()
{
	for (auto component : components)
	{
		delete component;
	}
}

void GameObject::addComponent(Component* componentToAdd)
{
	components.push_back(componentToAdd);
}

void GameObject::updateComponents()
{
	for (auto component : components)
	{
		component->update();
	}
}