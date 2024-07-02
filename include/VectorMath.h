#pragma once
#include <cmath>

struct Vector2D
{
    float x;
    float y;

    Vector2D(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& v2) const
    {
        return Vector2D(x + v2.x, y + v2.y);
    }

    Vector2D operator-(const Vector2D& v2) const
    {
        return Vector2D(x - v2.x, y - v2.y);
    }

    Vector2D operator*(float scalar) const
    {
        return Vector2D(x * scalar, y * scalar);
    }
};
