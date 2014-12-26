#pragma once
#ifndef _VERTEX_
#define _VERTEX_
#include "d3dx9.h"
struct Vertex
{
	Vertex(float x, float y, float z, float nx, float ny, float nz, float u, float v);
	float _x, _y, _z;
	float _nx, _ny, _nz;
	float _u, _v;
	static const DWORD FVF;
};

#endif
