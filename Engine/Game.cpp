/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd), frameTimer(),
	ball(Vector2D(310.0f, 280.0f), Vector2D(300.0f, 300.0f)),
	wall(0.0f, float(Graphics::ScreenWidth), 0.0f, float(Graphics::ScreenHeight)),
	wallCollisionSound(L"Sounds\\arkpad.wav"), brickCollisionSound(L"Sounds\\arkbrick.wav"),
	paddle(Vector2D(400.0f, 500.0f), 50.0f, 15.0f)
{
	Color brickColors[nBricksDown] = { Colors::Blue, Colors::Red, Colors::Gray, Colors::Magenta };

	float marginLeft = 40.0f;
	float marginTop = 40.0f;

	for (int y = 0; y < nBricksDown; ++y)
	{
		for (int x = 0; x < nBricksAcross; ++x)
		{
			float brickLeft = x * brickWidth + marginLeft;
			float brickRight = brickLeft + brickWidth ;
			float brickTop = y * brickHeight + marginTop;
			float brickBottom = brickTop + brickHeight;

			if (y == 2)
			{
				bricks[x][y] = Brick(Rect(brickLeft, brickRight, brickTop, brickBottom), brickColors[y], BrickType::HARD);
			}
			else {
				bricks[x][y] = Brick(Rect(brickLeft, brickRight, brickTop, brickBottom), brickColors[y], BrickType::SOFT);
			}
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (ball.isDestroyed()) return;

	float frameTime = frameTimer.Mark();
	ball.move(frameTime);
	if (ball.isAtBoundary(wall))
	{
		wallCollisionSound.Play();
	}

	auto gridPosOfCollidingBricks = getGridPosOfCollidingBricks();
	if (gridPosOfCollidingBricks.size() == 1)
	{
		int x = gridPosOfCollidingBricks.at(0).first;
		int y = gridPosOfCollidingBricks.at(0).second;
		bricks[x][y].handleBallCollision(ball);
		brickCollisionSound.Play();
	}
	else if (gridPosOfCollidingBricks.size() == 2)
	{
		int x1 = gridPosOfCollidingBricks.at(0).first;
		int y1 = gridPosOfCollidingBricks.at(0).second;
		int x2 = gridPosOfCollidingBricks.at(1).first;
		int y2 = gridPosOfCollidingBricks.at(1).second;

		auto brick1Pos = bricks[x1][y1].getBoundingRect().getCenterPos();
		auto brick2Pos = bricks[x2][y2].getBoundingRect().getCenterPos();

		float dist1 = Vector2D::getDisplacementFromCenter(ball.getPos(), brick1Pos);
		float dist2 = Vector2D::getDisplacementFromCenter(ball.getPos(), brick2Pos);
		if (dist1 < dist2)
		{
			bricks[x1][y1].handleBallCollision(ball);
		}
		else {
			bricks[x2][y2].handleBallCollision(ball);
		}
		brickCollisionSound.Play();
	}

	paddle.move(wnd.kbd, frameTime);
	paddle.handleBallCollision(ball);
	paddle.handleBoundaryCollision(wall);
}

std::vector<std::pair<int, int>> Game::getGridPosOfCollidingBricks()
{
	std::vector<std::pair<int, int>> positions;
	const Rect ballRect{ ball.getBoundingRect() };

	for (int y = 0; y < nBricksDown; ++y)
	{
		for (int x = 0; x < nBricksAcross; ++x)
		{
			const Rect brickRect{ bricks[x][y].getBoundingRect() };
			if (!bricks[x][y].isDestroyed() && ballRect.isOverlapping(brickRect))
			{
				std::pair<int, int> gridPos{ x, y };
				positions.push_back(gridPos);
			}
		}
	}
	return positions;
}

void Game::ComposeFrame()
{
	if (ball.isDestroyed()) return;

	ball.draw(gfx);
	for (int y = 0; y < nBricksDown; ++y)
	{
		for (int x = 0; x < nBricksAcross; ++x)
		{
			bricks[x][y].draw(gfx);
		}
	}
	paddle.draw(gfx);
}
