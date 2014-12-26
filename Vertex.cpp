#include "Vertex.h"

const DWORD Vertex::FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1;
Vertex::Vertex(float x, float y, float z, float nx, float ny, float nz, float u, float v)
	:_x(x), _y(y), _z(z), _nx(nx), _ny(ny), _nz(nz), _u(u), _v(v)
{

}

