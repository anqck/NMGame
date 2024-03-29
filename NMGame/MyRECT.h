#pragma once

#include"Global.h"

enum CenterArchor
{
	TopLeft,
	CenterBottom,
	Center,
	CenterTop
};

class MyRECT :public RECT
{
public:
	
	MyRECT();
	MyRECT(float top, float left, float right, float bottom);
	MyRECT(float top, float left, float right, float bottom, D3DXVECTOR3 translation);
	~MyRECT();

	D3DXVECTOR3 GetCenterArchorPosision(CenterArchor mCenterArchor);

	void		setCenterTranslation(int x = 0, int y = 0);
	D3DXVECTOR3	getCenterTranslation();

	bool		Intersects(MyRECT rect);
	bool		Contains(MyRECT rect);
private:
	D3DXVECTOR3	centerTranslation;
	
};