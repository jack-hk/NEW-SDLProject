#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include "CommonMath.h"
#include "Component.h"

// Serves as a frame for components.
class GameObject
{
public:
	GameObject(Vector2D go_position, int go_size);
	~GameObject();

	inline Vector2D getPosition() { return position; }
	inline int getSize() { return size; }
	inline void transform(Vector2D newPosition) { position = newPosition; }

	void addComponent(Component* componentToAdd);
	void updateComponents();

	template <typename T> T* GetComponent()
	{
		for (auto component : components)
		{
			T* com = dynamic_cast<T*>(component);
			if (com != nullptr)
				return com;
		}
		return nullptr;
	}

private:
	Vector2D position = Vector2D(0, 0);
	int size = 32;

	std::vector<Component*> components;
};