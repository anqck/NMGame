#include "Apple.h"
#include "AladdinCharacter.h"
#include "SoundHelper.h"

Apple::Apple()
{
	this->mID = EObjectID::APPLE;

	this->mCanBeHitByFlyingObject = false;

	mWidth = 30;
	mHeight = 30;

	this->mDone = false;
}

Apple::Apple(D3DXVECTOR3 pos) : Apple()
{
	this->mPosition = pos;

	this->mCurrentState = AppleState::AppleState_Normal;

	std::vector<MyRECT> temp;

	temp.push_back(MyRECT(0, 0,11, 11));
	this->mState.push_back(new ObjectState(temp, 13, L"Object\\Apple.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	temp.push_back(MyRECT(31, 37, 42, 39));
	temp.push_back(MyRECT(31, 30, 36, 40));
	temp.push_back(MyRECT(31, 18, 29, 43));
	temp.push_back(MyRECT(30, 0, 17, 46));
	temp.push_back(MyRECT(0, 22, 42, 19));
	temp.push_back(MyRECT(0, 0, 21, 15));
	temp.push_back(MyRECT(13, 43, 62, 27));
	temp.push_back(MyRECT(16, 0, 20, 29));
	temp.push_back(MyRECT(0, 43, 63, 12));
	temp.push_back(MyRECT(20, 21, 37, 30));

	this->mState.push_back(new ObjectState(temp, 14, L"Object\\AppleDisappear.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));


	this->mState.at(0)->SetPosition(pos);
	this->mState.at(1)->SetPosition(pos);
	temp.clear();
}

Apple::~Apple()
{
}

void Apple::ResetDefault()
{
	mWidth = 30;
	mHeight = 30;

	this->mDone = false;
	this->mCurrentState = AppleState::AppleState_Normal;
}

void Apple::Render(float DeltaTime)
{
	GameVisibleEntity::Render(DeltaTime);

	this->mState.at(mCurrentState)->Render();
}

void Apple::Update(float DeltaTime)
{
	this->mState.at(mCurrentState)->Update(DeltaTime);
	this->mPosition = this->mState.at(mCurrentState)->GetPosition();

	switch (mCurrentState)
	{
	case AppleState::AppleState_Normal:

		break;

	case AppleState::AppleState_Disappear:
	{
		this->mPosition = this->mState.at(mCurrentState)->GetPosition();

		if (this->mState.at(mCurrentState)->isDone())
		{
			mDone = true;
		}

		break;
	}

	}

}

void Apple::processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision)
{
	switch ((EObjectID)obj->GetID())
	{
	case EObjectID::ALADDIN:
		if (this->mCurrentState == AppleState::AppleState_Normal)
		{
			((AladdinCharacter *)obj)->AddApple(1);
			this->mCurrentState = AppleState::AppleState_Disappear;

			SoundHelper::GetInstance()->Play("Apple_Collect");
		}
		


		break;
	}
}
