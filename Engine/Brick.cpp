#include "Brick.h"

Brick::Brick(Rect& body, Color color)
	:body(body), color(color), isDestroyed(false)
{
}

void Brick::draw(Graphics& gfx)
{
	gfx.DrawRect(body, color);
}
