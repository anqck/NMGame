﻿#pragma once
#ifndef _ALADDIN_H__
#define _ALADDIN_H__

#include "Global.h"
#include "GameLog.h"
#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"
#include "SceneManager.h"
#include "Collision.h"
#include "MyRECT.h"
#include <vector>
#include <map>

#include "ThrowApple.h"
#include "StoppingDust.h"
#include "Rope.h"
#include "SwingBar.h"

enum AState
{
	DoNothing,
	Walk,
	StopWalk,
	LookUp,
	Stand,
	Sit,
	Rest,
	SitAttack,
	Attack1,
	RopeClimb,
	RunAndJump,
	ThrowApple,
	SitThrow,
	RunAttack,
	StandJump,
	JumpAttack,
	Push,
	LookUpAttack,
	JumpThrow,
	RunThrow,
	Wait1,
	Wait2,
	RopeJump,
	SwingWait,
	SwingAttack,
	SwingThrow,
	SwingMove,
	Couple,
	Falling,
	Damaged,
	RopeAttack,
	RopeThrow,
	SwingDoNothing
};



class AladdinCharacter : public GameVisibleEntity
{
public:
	AladdinCharacter();
	AladdinCharacter( D3DXVECTOR3	pos);


	void			Update(float DeltaTime);
	void			Render(float DeltaTime);			//
	void			OnKeyDown(int keyCode);
	void			OnKeyUp(int keyCode);
	void			ProcessInput();

	void			LoadResource();
	AState			getCurrentState();
	void			setCurrentState(AState state);
	ObjectState *	GetCurrentState();

	ObjectState*	getCurrentObjectState();

	Direction		getDirection();
	void			setDirection(Direction dir);

	void			setAllowStateChange(bool allow);
	
	void			ResetFlagCollision();

	bool			isGrounded();
	void			SetGrounded(bool allow);


	void			processCollision(float DeltaTime, GameVisibleEntity *obj, CollisionResult collision);
	void			processCollisionAABB(GameVisibleEntity * obj, bool AABBresult, CollisionWith collisionWith);

	int				GetHP();

	void			AddApple(int number);
	int				GetAppleCount();

	MyRECT			GetBoundingBox();
	MyRECT			GetAttackBoundingBox();

	void			PrintLogState();

protected:
	vector<ObjectState*>	mAladdinState;
	AState					mCurrentState;
	int						mHP;
	int						mAppleCount;
	Direction				mDir;

	bool					allowStateChange;
	float					mTime;					//Đếm thời gian 
	float					mStopWalkThresHold;
	bool					mIsStopAnimation;


	bool					mIsGrounded;
	bool					mWallCollision;

	bool					mRopeCollision;
	Rope*					mLastRope;

	bool					mSwingBarCollision;
	SwingBar*					mLastSwingBar;

	//Falling
	float					mNotOnGroundTime;
	bool					mFallingFlag;


	//float					_yCollision;

	bool					mOpacityRender;
	bool					mIsOpacityRendered;
	float					mOpacityTime;

	bool					allowAttack;
	bool					allowJump;
	bool					allowAction;
	bool					isClimbing;

	void					_BeforeStateChange(AState &changeTo);
	void					_AfterStateChange();

	bool					flagKeyPressed ;

	StoppingDust*			mStoppingDust;


	

};

#endif _ALADDIN_H__