#pragma once

class Vector2D
{
public:
	Vector2D() = default;
	Vector2D( float x_in,float y_in );
	Vector2D operator+( const Vector2D& rhs ) const;
	Vector2D& operator+=( const Vector2D& rhs );
	Vector2D operator*( float rhs ) const;
	Vector2D& operator*=( float rhs );
	Vector2D operator-( const Vector2D& rhs ) const;
	Vector2D& operator-=( const Vector2D& rhs );
	float GetLength() const;
	float GetLengthSq() const;
	Vector2D& Normalize();
	Vector2D GetNormalized() const;
	static float getDisplacementFromCenter(const Vector2D& first, const Vector2D& second);
public:
	float x;
	float y;
};