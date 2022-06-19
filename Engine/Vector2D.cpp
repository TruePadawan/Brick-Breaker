#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D( float x_in,float y_in )
	:
	x( x_in ),
	y( y_in )
{
}

Vector2D Vector2D::operator+( const Vector2D& rhs ) const
{
	return Vector2D( x + rhs.x,y + rhs.y );
}

Vector2D& Vector2D::operator+=( const Vector2D& rhs )
{
	return *this = *this + rhs;
}

Vector2D Vector2D::operator*( float rhs ) const
{
	return Vector2D( x * rhs,y * rhs );
}

Vector2D& Vector2D::operator*=( float rhs )
{
	return *this = *this * rhs;
}

Vector2D Vector2D::operator-( const Vector2D& rhs ) const
{
	return Vector2D( x - rhs.x,y - rhs.y );
}

Vector2D& Vector2D::operator-=( const Vector2D& rhs )
{
	return *this = *this - rhs;
}

float Vector2D::GetLength() const
{
	return std::sqrt( GetLengthSq() );
}

float Vector2D::GetLengthSq() const
{
	return x * x + y * y;
}

Vector2D& Vector2D::Normalize()
{
	return *this = GetNormalized();
}

Vector2D Vector2D::GetNormalized() const
{
	const float len = GetLength();
	if( len != 0.0f )
	{
		return *this * (1.0f / len);
	}
	return *this;
}
