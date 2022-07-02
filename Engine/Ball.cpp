#include "Ball.h"

Ball::Ball(const Vector2D& pos, const Vector2D& ballVelocity)
	:position(pos), velocity(ballVelocity), destroyed(false)
{
	
}

bool Ball::isCollidingWith(const Rect& entity)
{
	bool colliding = false;
	return false;
}

void Ball::move(float ft)
{
	position += velocity * ft;
}

bool Ball::isAtBoundary(const Rect& boundary)
{
	bool collidedWithWall = false;
	Rect boundingRect = getBoundingRect();

	if (boundingRect.left < boundary.left)
	{
		collidedWithWall = true;
		reboundX();
		position.x += boundary.left - boundingRect.left;
	}
	else if (boundingRect.right > boundary.right)
	{
		collidedWithWall = true;
		reboundX();
		position.x -= boundingRect.right - boundary.right;
	}

	if (boundingRect.top < boundary.top)
	{
		collidedWithWall = true;
		reboundY();
		position.y += boundary.top - boundingRect.top;
	}
	else if (boundingRect.bottom > Graphics::ScreenHeight)
	{
		destroyed = true;
		collidedWithWall = true;
		reboundY();
		position.y -= boundingRect.bottom - boundary.bottom;
	}

	return collidedWithWall;
}

void Ball::draw(Graphics& gfx)
{
	SpriteCodex::DrawBall(position, gfx);
}

Vector2D& Ball::getVelocity()
{
	return velocity;
}

Rect Ball::getBoundingRect() const
{
	return Rect::fromCenter(position, radius, radius);
}

void Ball::reboundX()
{
	velocity.x = -velocity.x;
}

void Ball::reboundY()
{
	velocity.y = -velocity.y;
}

bool Ball::isDestroyed()
{
	return destroyed;
}
