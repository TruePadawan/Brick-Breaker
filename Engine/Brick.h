#pragma once
#include "Rect.h"
#include "Graphics.h"

class Brick
{
	Brick(Rect& body, Color color);
private:
	Rect body;
	Color color;
	bool isDestroyed;
};

