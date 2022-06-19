#pragma once

#include "Graphics.h"
#include "Vector2D.h"

class SpriteCodex
{
public:
	// centered drawing of 14x14 sprite
	static void DrawBall( const Vector2D& center,Graphics& gfx );
};