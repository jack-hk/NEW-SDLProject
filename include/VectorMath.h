#pragma once

struct Vector2D
{
	int x;
	int y;

	Vector2D(int x, int y)
	{
		this->x = x;
		this->y = y;
	};

	Vector2D operator+(const Vector2D& v2)
	{
		return Vector2D(x + v2.x, y + v2.y);
	}
};