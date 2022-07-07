#include "Brick.h"

Brick::Brick(Rect& body, Color color, BrickType type)
	:body(body), color(color), type(type), destroyed(false), recordedHits(0)
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
		setDestroyed();

		if (ballRect.left < brickRect.left || ballRect.right > brickRect.right)
		{
			ball.reboundX();
		}

		if (ballRect.top < brickRect.top || ballRect.bottom > brickRect.bottom)
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
		gfx.DrawRect(body.getExpanded(-1), color);
	}
}

void Brick::setDestroyed()
{
	if (type == HARD && recordedHits != 1)
	{
		++recordedHits;
		color.SetB(0);
	}
	else {
		destroyed = true;
	}
}
