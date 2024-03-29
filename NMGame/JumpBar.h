#pragma once
#ifndef __JUMPBAR_H__
#define __JUMPBAR_H__
#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"

enum JumpBarState
{
	JumpBarState_Normal,
	JumpBarState_JumpOn,
	JumpBarState_Shine
};

class JumpBar :public GameVisibleEntity
{
public:
	JumpBar();
	JumpBar(MyRECT bb, D3DXVECTOR3 pos);
	~JumpBar();

	void						Render(float DeltaTime);
	void						Update(float DeltaTime);

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

protected:
	vector<ObjectState*>		mState;
	JumpBarState				mCurrentState;


};

#endif __JUMPBAR_H__