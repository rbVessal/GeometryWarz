#include "MySquare.h"

#pragma region Constructors
MySquare::MySquare(vec2 anOrigin, vec2 anExtent)
{
	center = new vec2(anOrigin);
	extents = anExtent;
	GeneratePoints();
	shearMatrix = identity();
	scaleVector = vec2(1.0f, 1.0f);
	angle = 0;
	Init();
}

MySquare::MySquare(const MySquare& otherSquare)
{
	center = new vec2(*otherSquare.center);
	extents = otherSquare.extents;
	GeneratePoints();
	shearMatrix = otherSquare.shearMatrix;
	scaleVector = otherSquare.scaleVector;
	angle = otherSquare.angle;
	Init();
}

MySquare& MySquare::operator=(const MySquare& otherSquare)
{
	delete center; // Demonstration of difference between assignment and copy ctor.
	center = new vec2(*otherSquare.center); // Point to different memory but with same x/y coordinates.
	extents = otherSquare.extents;
	GeneratePoints();
	shearMatrix = otherSquare.shearMatrix;
	scaleVector = otherSquare.scaleVector;
	angle = otherSquare.angle;
	Init();

	return *this;
}

#pragma endregion

void MySquare::Init()
{
	shearMatrix = identity();
	translationMatrix = identity();
	rotationMatrix = identity();
	scaleMatrix = identity();
}

void MySquare::AddTranslation(vec2 aOffset)
{
	*center += aOffset;
	translationMatrix = Translate(center->x, center->y, 0.0f);
}

void MySquare::AddScale(vec2 aScaleOffset)
{
	scaleVector += aScaleOffset;
	scaleMatrix = Scale(scaleVector.x, scaleVector.y, 1.0f);
}

void MySquare::AddShear(vec2 aShearOffset)
{
	shearMatrix[0][1] += aShearOffset.x;
	shearMatrix[1][0] += aShearOffset.y;
}

void MySquare::AddAngle(float anAngle)
{
	angle += anAngle;
	rotationMatrix = RotateZ(angle);
}

void MySquare::GeneratePoints(void)
{
	// Note the order - since this is drawn as a triangle fan, the vertices are defined in a specific order.
	points[0] = vec2(-extents.x, -extents.y);
	points[1] = vec2(-extents.x, extents.y);
	points[2] = vec2(extents.x, extents.y);
	points[3] = vec2(extents.x, -extents.y);
}

vec2* MySquare::GetPoints(void)
{
	return points;
}

vec2 MySquare::GetCenter(void)
{
	return *center;
}

MySquare::~MySquare(void)
{
	delete center; // Demonstration of needing to clean up in destructor.
}