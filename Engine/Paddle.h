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
	void isAtBoundary(const Rect& boundary);
	Rect getRect() const;
private:
	Vector2D centerPos;
	float halfWidth;
	float halfHeight;
	float speed;
};

