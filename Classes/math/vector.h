/****************************************************************************
	Copyright (c) 2014 , AdamWu calvinmankor@gmail.com
	All rights reserved.

	Use, modification and distribution are subject to the "New BSD License"
    as listed at <url: http://www.opensource.org/licenses/bsd-license.php >.

	COMPANY:  
	CREATED:  2014Äê11ÔÂ30ÈÕ
****************************************************************************/
//
// def of 2d vector
//
#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <math.h>

class Vector
{
public:
	inline Vector(void)
		:x(0)
		,y(0)
	{}

	inline Vector(float x,float y)
		:x(x)
		,y(y)
	{}

	~Vector() {};
	
	// car or cdr
	inline float getX() {return x;};
	inline void setX(float x) {this->x = x;};
	inline float getY() {return y;};
	inline void setY(float y) {this->y = y;};

	// math operate
	inline Vector &operator /=(const float Scalar)	{ x /= Scalar; y /= Scalar;		return *this; }

	inline Vector &operator *=(const float Scalar)	{ x *= Scalar; y *= Scalar;		return *this; }

	inline Vector &operator +=(const Vector &Other) { x += Other.x;	y += Other.y;	return *this; }

	inline Vector &operator -=(const Vector &Other) { x -= Other.x;	y -= Other.y;	return *this;	}

	inline float operator ^ (const Vector &V)	const	{	return (x * V.y) - (y * V.x); } // cross product

	inline float operator * (const Vector &V)	const	{	return (x*V.x) + (y*V.y); } // dot product

	inline Vector operator * (float  s)			const	{	return Vector(x*s, y*s); }

	inline Vector operator / (float  s)			const	{	return Vector(x/s, y/s); }

	inline Vector operator + (const Vector &V)	const	{	return Vector(x+V.x, y+V.y); }

	inline Vector operator - (const Vector &V)	const	{	return Vector(x-V.x, y-V.y); }

	friend Vector operator * (float k, const Vector& V) {	return Vector(V.x*k, V.y*k); }

	inline Vector operator -(void) const { return Vector(-x, -y); }

	inline float Length(void) const { return (float) sqrt(x*x + y*y); }

	float Normalise(void) 
	{	
		float fLength = Length();	

		if (fLength == 0.0f) 
			return 0.0f; 

		(*this) *= (1.0f / fLength); 

		return fLength;	
	}

private:
	float x;
	float y;
};

#endif // __VECTOR_H__

