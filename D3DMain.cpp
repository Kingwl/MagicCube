#include "d3d9.h"
#include "d3dx9.h"
const int Width = 400;
const int Height = 400;
IDirect3DDevice9 *Device = nullptr;

LRESULT CALLBACK d3d::winProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			::DestroyWindow(hWnd);
		}
		break;
	default:
		break;
	}
	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}
bool Display(float timeDelta)
{
	if (Device != nullptr)
	{
		D3DXVECTOR3 pos(0.0f, 0.0f, -5.0f);
		D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
		D3DXVECTOR3 look(0.0f, 0.0f, 0.0f);
		D3DXMATRIX V;
		D3DXMatrixLookAtLH(&V, &pos, &up, &look);
		Device->SetTransform(D3DTS_VIEW, &V);
		Device->SetRenderState(D3DRS_LIGHTING, false);
		Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL, 0xff000000, 1.0f, 0);


		Device->Present(0, 0, 0, 0);

	}
	return true;
}
bool Setup()
{
	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(&proj, D3DX_PI * 0.5f, (float)Width / (float)Height, 1.0f, 1000.0f);
	Device->SetTransform(D3DTS_PROJECTION, &proj);
	return true;
}
void Cleanup()
{

}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (!d3d::initD3D(hInstance, Width, Height, true, D3DDEVTYPE_HAL, &Device))
	{
		::MessageBox(nullptr, "initD3d failed", "error", 0);
		return 0;
	}
	if (!Setup())
	{
		::MessageBox(nullptr, "Setup failed", "error", 0);
		return 0;
	}
	d3d::EnterMsgLoop(Display);
	Cleanup();
	Device->Release();
	return 0;
}