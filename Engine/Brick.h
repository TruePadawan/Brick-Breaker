#pragma once
#include "Rect.h"
#include "Ball.h"
#include "Graphics.h"

enum BrickType {
	SOFT, HARD
};

class Brick
{
public:
	Brick() = default;
	Brick(Rect& body, Color color, BrickType type = SOFT);
	Rect getBoundingRect() const;
	bool handleBallCollision(Ball& ball);
	void draw(Graphics& gfx);
private:
	void setDestroyed();
private:
	Rect body;
	Color color;
	BrickType type;
	bool destroyed;
	int recordedHits;
};