#include "Rect.h"

Rect::Rect(float left, float right, float top, float bottom)
	:left(left), right(right), top(top), bottom(bottom)
{
}

Rect::Rect(const Vector2D& topLeft, const Vector2D& bottomRight)
	:left(topLeft.x), right(bottomRight.x), top(topLeft.y), bottom(bottomRight.y)
{
}
