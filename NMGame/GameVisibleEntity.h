﻿#pragma once
#ifndef __OBJECT_H__
#define __OBJECT_H__
#include "Global.h"
#include <vector>
#include "MyRECT.h"
#include "Sprite.h"
#include "ViewPort.h"
#include "Collision.h"
#include "ObjectState.h"

enum EObjectID
{
	GROUND,
	ROPE,
	STAIR,
	WALL,
	FIREGROUND,
	COLLAPSEGROUND,
	SLIDECOLUMN,
	SWINGBAR,
	JUMPBAR,
	BLOCK,

	APPLE, //Cộng táo
	LAMP, //Đụng vào enemy trên màn hết máu
	HEATH, //Cộng máu
	GENIE, //Cộng điểm
	MONKEY, //Cộng điẻm
	GEM,//Cộng gem + điểm
	CHECKPOINT,

	CAMEL,

	ENEMY1,
	ENEMY2,
	ENEMY3,
	ENEMY4,
	ENEMY5, //Núp trong bình, quăng táo 0 dame
	THROWPOT,
	TRADER, //bán hàng

	THROWINGAPPLE, //Táo quăng ra
	THROWINGCAMEL //Lạc đà bắn ra

};

class GameVisibleEntity {
protected:
	EObjectID				mID;

	Sprite*					mSprite;

	int						mWidth, mHeight;

	D3DXVECTOR3				mPosition;
	D3DXVECTOR2				mVelocity;

	MyRECT					mBoundingBox;
	MyRECT					mInteractBoundingBox;

	float					mTime;
	int						ANIMATE_RATE;

	bool					mCanBeAttack;
	bool					mCanAttack;

	
public:
	GameVisibleEntity();
	GameVisibleEntity( D3DXVECTOR3 pos);
	GameVisibleEntity( int X, int Y);

	virtual void			Render(float DeltaTime) ;
	virtual void			Update(float DeltaTime);

	virtual D3DXVECTOR3		getViewPortPosition();

	EObjectID				GetID();
	void					SetID(EObjectID id);

	D3DXVECTOR3				GetPosition();
	void					SetPosition(D3DXVECTOR3 Position);
	void					SetPosition(int X, int Y);

	void					SetWidthAndHeight(int width, int height);

	TransformObject			GetTransformPosition();

	virtual MyRECT			GetBoundingBox();
	void					SetBoundingBox(MyRECT rect);

	virtual MyRECT			GetInteractBoundingBox();
	void					SetInteractBoundingBox(MyRECT rect);

	virtual ObjectState*		GetCurrentState();
	virtual bool				isDone() { return false; };
	
	virtual void processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

};

#endif __OBJECT_H__