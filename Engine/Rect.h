#pragma once
#include "Vector2D.h"

class Rect
{
public:
	Rect(float left, float right, float top, float bottom);
	Rect(const Vector2D& topLeft, const Vector2D& bottomRight);
public:
	float left;
	float right;
	float top;
	float bottom;
};

