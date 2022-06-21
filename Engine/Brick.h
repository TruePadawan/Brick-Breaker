#pragma once
#include "Rect.h"
#include "Ball.h"
#include "Graphics.h"

class Brick
{
public:
	Brick() = default;
	Brick(Rect& body, Color color);
	Rect getBoundingRect() const;
	bool handleBallCollision(Ball& ball);
	void draw(Graphics& gfx);
private:
	Rect body;
	Color color;
	bool destroyed;
};

