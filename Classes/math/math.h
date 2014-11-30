/****************************************************************************
	Copyright (c) 2014 , AdamWu calvinmankor@gmail.com
	All rights reserved.

	Use, modification and distribution are subject to the "New BSD License"
    as listed at <url: http://www.opensource.org/licenses/bsd-license.php >.

	COMPANY:  
	CREATED:  2014Äê11ÔÂ30ÈÕ
****************************************************************************/
//
//	math.h
//

#include "vector.h"

#define FLOAT_ZERO 0.000001

static inline bool isZero(float v)
{
	return abs(v) <= FLOAT_ZERO && abs(v) >= -FLOAT_ZERO; 
}

// check whether point P in triangle ABC
static inline bool pointInTriangle(const Vector& A, const Vector& B, const Vector& C, const Vector& P)
{
	Vector v0 = C - A ;
	Vector v1 = B - A ;
	Vector v2 = P - A ;

	float dot00 = v0 * v0;
	float dot01 = v0 * v1;
	float dot02 = v0 * v2;
	float dot11 = v1 * v1;
	float dot12 = v1 * v2;

	float inverDeno = 1 / (dot00 * dot11 - dot01 * dot01) ;

	float u = (dot11 * dot02 - dot01 * dot12) * inverDeno ;
	if (u < 0 || u > 1) // if u out of range, return directly
	{
		return false ;
	}

	float v = (dot00 * dot12 - dot01 * dot02) * inverDeno ;
	if (v < 0 || v > 1) // if v out of range, return directly
	{
		return false ;
	}

	return u + v <= 1 ;
}


// check whether point P on Segment AB
static inline bool pointOnSegment(const Vector& A, const Vector& B, const Vector& P)
{
	Vector v0 = A - P;
	Vector v1 = B - P;
	return isZero(v0 ^ v1);
}

// check whether two segments intersect(AB CD)
static inline bool lineIntersect(const Vector& A, const Vector& B, const Vector& C, const Vector& D)
{
	// check whether in segment
	if (pointOnSegment(C, D, A) || pointOnSegment(C, D, B) || pointOnSegment(A, B, C) || pointOnSegment(A, B, D))
		return true;

	// more
	Vector v0 = B - A;
	Vector v1 = C - A;
	Vector v2 = D - A;
	Vector v3 = D - C;
	Vector v4 = A - C;
	Vector v5 = B - C;

	float d1 = v0 ^ v1;
	float d2 = v0 ^ v2;
	float d3 = v3 ^ v4;
	float d4 = v3 ^ v5;

	return (d1 * d2) < 0 && (d2 * d3) < 0;
}

// check whether two triangle intersect
static inline bool triangleIntersect(const Vector& A1, const Vector& B1, const Vector& C1, 
									 const Vector& A2, const Vector& B2, const Vector& C2)
{
	if (pointInTriangle(A2, B2, C2, A1) || pointInTriangle(A2, B2, C2, B1) || pointInTriangle(A2, B2, C2, C1) ||
		pointInTriangle(A1, B1, C1, A2) || pointInTriangle(A1, B1, C1, B2) || pointInTriangle(A1, B1, C1, C2))
		return true;

	if (lineIntersect(A1, B1, A2, B2) || lineIntersect(A1, B1, A2, C2) || lineIntersect(A1, B1, B2, C2) ||
		lineIntersect(A1, C1, A2, B2) || lineIntersect(A1, C1, A2, C2) || lineIntersect(A1, C1, B2, C2) ||
		lineIntersect(B1, C1, A2, B2) || lineIntersect(B1, C1, A2, C2) || lineIntersect(B1, C1, B2, C2))
		return true;
}