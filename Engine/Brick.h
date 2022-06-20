#pragma once
#include "Rect.h"
#include "Graphics.h"

class Brick
{
public:
	Brick(Rect& body, Color color);
	void draw(Graphics& gfx);
private:
	Rect body;
	Color color;
	bool isDestroyed;
};

