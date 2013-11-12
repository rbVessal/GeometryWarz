GeometryWarz
============

OVERVIEW:
OpenGL Rendering of Geometry Warz

FEATURES:
Displays rendering multiple objects such as cubes, tetrahedrons, and quadrahedrons using VBOs and VAOs.
Does AABB collision with the window and other objects.
Changes colors of the object faces by manipulating the color array data in the vertex shader that gets passed to the fragment
shader.
Moves the polyhedrons by changing the offset of the position in the vertex shader.
Easily able to create other shapes if necessary by inheriting from Polyhedron class.
Uses modern OpenGL pipeline.

NOTE: 
You have to create empty glsl files and copy and paste the code from the glsl files in this repo to the empty ones.
GitHub corrupts the shader files in Visual Studio 2012 whenever committing to the repo.
