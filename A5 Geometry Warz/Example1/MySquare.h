#pragma once

#include "Angel.h"

const int NUM_VERTICES = 4; // A square has 4 points :)

class MySquare
{
	public:
		MySquare(vec2 anOrigin, vec2 anExtent);
		MySquare(const MySquare& otherSquare);
		MySquare& MySquare::operator=(const MySquare& otherSquare);
		virtual ~MySquare(void);
		
		void Init(void);
		void AddTranslation(vec2 aOffset);
		void AddScale(vec2 aScaleOffset);
		void AddShear(vec2 aShearOffset);
		void AddAngle(float anAngle);

		vec2 GetCenter(void);
		vec2* GetPoints(void);
		
		mat4 GetTranslationMatrix(void) { return translationMatrix; }
		mat4 GetRotationMatrix(void) { return rotationMatrix; }
		mat4 GetShearMatrix(void) { return shearMatrix; }
		mat4 GetScaleMatrix(void) { return scaleMatrix; }

	private:
		void GeneratePoints(void);

		float angle;
		vec2* center;
		vec2 points[NUM_VERTICES];
		vec2 extents;
		vec2 scaleVector;
	
		mat4 translationMatrix;
		mat4 rotationMatrix;
		mat4 shearMatrix;
		mat4 scaleMatrix;
};