#include "Rect.h"

Rect::Rect(float left, float right, float top, float bottom)
	:left(left), right(right), top(top), bottom(bottom)
{
}

Rect::Rect(const Vector2D& topLeft, const Vector2D& bottomRight)
	:left(topLeft.x), right(bottomRight.x), top(topLeft.y), bottom(bottomRight.y)
{
}

Rect Rect::fromCenter(const Vector2D& centerPos, float halfWidth, float halfHeight)
{
	const Vector2D half{ halfWidth, halfHeight };
	return Rect(centerPos - half, centerPos + half);
}
