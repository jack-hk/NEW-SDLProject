#pragma once

class GameObject;
class Component
{
public:
	GameObject* go;

	inline Component(GameObject* gameObject) { go = gameObject; }
	virtual void update() = 0;

private:
	bool isEnabled = true;
};