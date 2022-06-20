#include "Paddle.h"

Paddle::Paddle(Vector2D& _centerPos, float _halfWidth, float _halfHeight)
	:centerPos(_centerPos), halfHeight(_halfHeight), halfWidth(_halfWidth), speed(300.0f)
{
}

void Paddle::draw(Graphics& gfx) const
{
	Rect boundingRect{ getBoundingRect() };
	gfx.DrawRect(boundingRect, Colors::Green);
	boundingRect.left += 10;
	boundingRect.right -= 10;
	gfx.DrawRect(boundingRect, Colors::Red);
}

void Paddle::move(Keyboard& kbd, float ft)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		centerPos.x -= speed * ft;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT))
	{
		centerPos.x += speed * ft;
	}
}

void Paddle::isAtBoundary(const Rect& boundary)
{
	Rect boundingRect = getBoundingRect();

	if (boundingRect.left < boundary.left)
	{
		centerPos.x += boundary.left - boundingRect.left;
	}
	else if (boundingRect.right > boundary.right)
	{
		centerPos.x -= boundingRect.right - boundary.right;
	}
}

void Paddle::handleBallCollision(Ball& ball)
{
	Rect boundingRect = getBoundingRect();
	Rect ballBoundingRect = ball.getBoundingRect();
	if (ball.getVelocity().y > 0 && boundingRect.isOverlapping(ballBoundingRect))
	{
		ball.reboundY();
	}
}

Rect Paddle::getBoundingRect() const
{
	return Rect::fromCenter(centerPos, halfWidth, halfHeight);
}
