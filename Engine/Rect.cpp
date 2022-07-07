#include "Rect.h"

Rect::Rect(float left, float right, float top, float bottom)
	:left(left), right(right), top(top), bottom(bottom)
{
}

Rect::Rect(const Vector2D& topLeft, const Vector2D& bottomRight)
	:left(topLeft.x), right(bottomRight.x), top(topLeft.y), bottom(bottomRight.y)
{
}

bool Rect::isOverlapping(const Rect& other) const
{
	return (left < other.right&& right > other.left &&
		top < other.bottom&& bottom > other.top);
}

Rect Rect::getExpanded(float offset)
{
	return Rect(left - offset, right + offset, top - offset, bottom + offset);
}

Vector2D Rect::getCenterPos() const
{
	return Vector2D((left+right)/2.0f, (top+bottom)/2.0f);
}

Rect Rect::fromCenter(const Vector2D& centerPos, float halfWidth, float halfHeight)
{
	const Vector2D half{ halfWidth, halfHeight };
	return Rect(centerPos - half, centerPos + half);
}
