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
	ball(Vector2D(200.0f, 200.0f), Vector2D(300.0f, 300.0f)),
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

			bricks[x][y] = Brick(Rect(brickLeft, brickRight, brickTop, brickBottom), brickColors[y]);
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
	float frameTime = frameTimer.Mark();
	ball.move(frameTime);
	if (ball.isAtBoundary(wall))
	{
		wallCollisionSound.Play();
	}

	bool shouldBreak = false;

	for (int y = 0; y < nBricksDown; ++y)
	{
		for (int x = 0; x < nBricksAcross; ++x)
		{
			if (bricks[x][y].handleBallCollision(ball))
			{
				brickCollisionSound.Play();
				shouldBreak = true;
				break;
			}
		}
		if (shouldBreak) break;
	}

	paddle.move(wnd.kbd, frameTime);
	paddle.handleBallCollision(ball);
	paddle.handleBoundaryCollision(wall);
}

void Game::ComposeFrame()
{
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
