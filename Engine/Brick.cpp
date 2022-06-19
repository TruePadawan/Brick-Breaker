#include "Brick.h"

Brick::Brick(Rect& body, Color color)
	:body(body), color(color), isDestroyed(false)
{
}