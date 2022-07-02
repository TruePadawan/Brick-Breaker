#pragma once

#include "Ball.h"
#include "Rect.h"
#include "Graphics.h"
#include "Keyboard.h"

class Paddle
{
public:
	Paddle() = default;
	Paddle(Vector2D& _centerPos, float _halfWidth, float _halfHeight);
	void draw(Graphics& gfx) const;
	void move(Keyboard& kbd, float ft);
	void handleBoundaryCollision(const Rect& boundary);
	void handleBallCollision(Ball& ball);
	Rect getBoundingRect() const;
private:
	Vector2D centerPos;
	float halfWidth;
	float halfHeight;
	float speed;
};

