#include "Cube.h"


Cube::Cube()
:_Device(nullptr), _length(1.0f)
{
}


Cube::~Cube()
{
}
void Cube::SetDevice(IDirect3DDevice9 *Device)
{
	_Device = Device;
}
void Cube::setLength(float length)
{
	_length = length;
}
void Cube::init(D3DXVECTOR3 &center)
{
	initVertex(center);
}
bool Cube::initVertex(D3DXVECTOR3 &center)
{
	float x = center.x - 0.5f * _length;
	float y = center.y - 0.5f * _length;
	float z = center.z - 0.5f * _length;

	/*
	1----------2
	|		   |
	|          |
	|		   |
	|		   |
	0----------3
	*/
	Vertex vertexs[] = 
	{
		//front face
		Vertex(x          , y		   , z          , 0.0f, 0.0f, -1.0f, 0.0f, 1.0f),
		Vertex(x		  , y + _length, z			, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f),
		Vertex(x + _length, y + _length, z		    , 0.0f, 0.0f, -1.0f, 1.0f, 0.0f),
		Vertex(x + _length, y		   , z			, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f),

		//back face
		Vertex(x, y, z, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f),
		Vertex(x, y, z, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f),
		Vertex(x, y, z, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f),
		Vertex(x, y, z, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f),



	}


}
bool Cube::initIndex()
{

}