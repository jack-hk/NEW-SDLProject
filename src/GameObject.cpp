#include "GameObject.h"

GameObject::GameObject(Vector2D go_position, int go_size)
{
	position.x = go_position.x;
	position.y = go_position.y;
	size = go_size;
}