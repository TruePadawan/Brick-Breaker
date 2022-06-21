#include "Brick.h"

Brick::Brick(Rect& body, Color color)
	:body(body), color(color), destroyed(false)
{
}

Rect Brick::getBoundingRect() const
{
	return body;
}

bool Brick::handleBallCollision(Ball& ball)
{
	bool didCollisionHappen = false;
	Rect brickRect{ this->getBoundingRect() };
	Rect ballRect{ ball.getBoundingRect() };

	if (!destroyed && ballRect.isOverlapping(brickRect))
	{
		didCollisionHappen = true;
		destroyed = true;

		if (ballRect.left < brickRect.left)
		{
			ball.reboundX();
		}
		else if (ballRect.right > brickRect.right)
		{
			ball.reboundX();
		}

		if (ballRect.top < brickRect.top)
		{
			ball.reboundY();
		}
		else if (ballRect.bottom > Graphics::ScreenHeight)
		{
			ball.reboundY();
		}
	}
	return didCollisionHappen;
}

void Brick::draw(Graphics& gfx)
{
	if (!destroyed)
	{
		gfx.DrawRect(body, color);
	}
}
