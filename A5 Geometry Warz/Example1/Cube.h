#pragma once
#include "Angel.h"

typedef Angel::vec4  color4;
typedef Angel::vec4  point4;

const int NumVertices = 36; //(6 faces)(2 triangles/face)(3 vertices/triangle)

class Cube
{
public:
	Cube(void);
	~Cube(void);

	// Functions
	void init();
	void doColor();
	void quad(int, int, int, int);
	void display();

private:
	int Index;
	GLuint  model_view;
	GLuint  projection;

	GLfloat radius;
	GLfloat theta;
	GLfloat phi;

	GLfloat  left, right;
	GLfloat  bottom, top;
	GLfloat  zNear, zFar;

	point4 points[NumVertices];
	color4 colors[NumVertices];

	// Vertices of a unit cube centered at origin, sides aligned with axes
	point4 vertices[8];

	// RGBA colors
	color4 vertex_colors[8];
};

