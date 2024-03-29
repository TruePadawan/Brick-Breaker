#pragma once
#include "SpriteCodex.h"

class Ball
{
public:
	Ball(const Vector2D& pos, const Vector2D& ballVelocity);
	bool isCollidingWith(const Rect& entity);
	void move(float ft);
	bool isAtBoundary(const Rect &boundary);
	void draw(Graphics& gfx);
	Vector2D& getVelocity();
	Vector2D& getPos();
	Rect getBoundingRect() const;
	void reboundX();
	void reboundY();
	bool isDestroyed();
private:
	bool destroyed;
	Vector2D position;
	Vector2D velocity;
	static constexpr float radius = 7.0f;
};

