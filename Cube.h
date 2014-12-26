#pragma once
#ifndef _CUBE_
#define _CUBE_
#include "Vertex.h"
#include "d3dx9.h"
class Cube
{
public:
	Cube();
	void SetDevice(IDirect3DDevice9 *Device);
	void setLength(float length);
	void init(D3DXVECTOR3 &center);
	bool initVertex(D3DXVECTOR3 &center);
	bool initIndex();

	~Cube();
private:
	IDirect3DDevice9 *_Device;
	IDirect3DVertexBuffer9 *_VertexBuffer;
	IDirect3DIndexBuffer9 *_IndexBUffer;
	float _length;
};

#endif