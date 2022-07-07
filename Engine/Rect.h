#pragma once
#include "Vector2D.h"

class Rect
{
public:
	Rect() = default;
	Rect(float left, float right, float top, float bottom);
	Rect(const Vector2D& topLeft, const Vector2D& bottomRight);
	bool isOverlapping(const Rect& other) const;
	Rect getExpanded(float offset);
	Vector2D getCenterPos() const;
	static Rect fromCenter(const Vector2D& centerPos, float halfWidth, float halfHeight);
public:
	float left;
	float right;
	float top;
	float bottom;
};

