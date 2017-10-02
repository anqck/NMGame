#include "Global.h"


HINSTANCE						GLOBAL::mHInstance = NULL;
HWND							GLOBAL::mHwnd = NULL;
LPDIRECT3D9						GLOBAL::mDirect = NULL;
LPDIRECT3DDEVICE9				GLOBAL::mDirectDevice = NULL;
LPDIRECT3DSURFACE9				GLOBAL::mBackBuffer = NULL;
LPD3DXSPRITE					GLOBAL::mSpriteHandler = NULL;
bool							GLOBAL::misFullScreen = FALSE;
int								GLOBAL::mWindowsWidth;
int								GLOBAL::mWindowsHeight;
LPWSTR							GLOBAL::mGameName = L"TEST GAME";
int								GLOBAL::mFrameRate;
int								GLOBAL::mCurrentFrame = 0;

GLOBAL::GLOBAL()
{
}


GLOBAL::~GLOBAL()
{
}