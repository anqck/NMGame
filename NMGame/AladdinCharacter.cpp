﻿#include "AladdinCharacter.h"

#include"KeyboardHelper.h"

#include <dinput.h>

#include <string> 

AladdinCharacter::AladdinCharacter()
{
}

AladdinCharacter::AladdinCharacter( D3DXVECTOR3  pos)
{


	vector<MyRECT> temp;

	/*this->mWidth = 63 * 2;
	this->mHeight = 48 * 2.5 ;*/

	//DoNothing
	temp.push_back(MyRECT(1212, 9, 57, 1275));
	this->mAladdinState.push_back(new ObjectState(temp, 10, L"Aladdin.png", D3DXVECTOR2(0, 0),CenterArchor::CenterBottom));
	temp.clear();

	//Walk
	temp.push_back(MyRECT(117, 42, 82, 165));
	temp.push_back(MyRECT(56, 103, 146, 107));
	temp.push_back(MyRECT(117, 83, 120, 167));
	temp.push_back(MyRECT(0, 0, 55, 58));
	temp.push_back(MyRECT(0, 56, 111, 55));
	temp.push_back(MyRECT(0, 159, 203, 57));
	temp.push_back(MyRECT(59, 189, 230, 112));
	temp.push_back(MyRECT(58, 147, 188, 115));
	temp.push_back(MyRECT(59, 0, 52, 116));
	temp.push_back(MyRECT(0, 112, 158, 54));
	temp.push_back(MyRECT(0, 204, 246, 58));
	temp.push_back(MyRECT(117, 0, 41, 169));
	temp.push_back(MyRECT(116, 121, 155, 170));
	temp.push_back(MyRECT(59, 53, 102, 116));
	this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 14, L"AladdinWalk.png", D3DXVECTOR2(0.5f, 0.0f),4, CenterArchor::CenterBottom));
	temp.clear();


	//Stop walk
	temp.push_back(MyRECT(0, 56, 110, 57));
	temp.push_back(MyRECT(106, 105, 143, 162));
	temp.push_back(MyRECT(58, 53, 104, 124));
	temp.push_back(MyRECT(53, 155, 202, 118));
	temp.push_back(MyRECT(92, 0, 42, 156));
	temp.push_back(MyRECT(0, 0, 55, 46));
	temp.push_back(MyRECT(47, 0, 52, 91));
	temp.push_back(MyRECT(51, 203, 249, 103));
	temp.push_back(MyRECT(58, 105, 154, 105));
	temp.push_back(MyRECT(0, 111, 162, 52));
	temp.push_back(MyRECT(0, 163, 214, 50));
	temp.push_back(MyRECT(104, 203, 240, 154));
	this->mAladdinState.push_back(new ObjectState(temp, 20, L"WalkStop.png", D3DXVECTOR2(0.1, 0), CenterArchor::CenterBottom));
	temp.clear();

	//LookUp
	temp.push_back(MyRECT(488, 7, 56, 551));
	temp.push_back(MyRECT(488, 56, 111, 551));
	temp.push_back(MyRECT(488, 109, 174, 551));
	this->mAladdinState.push_back(new ObjectState(temp, 20, L"Aladdin.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	//Stand
	temp.push_back(MyRECT(0, 0, 44, 53));
	temp.push_back(MyRECT(54, 0, 42, 105));
	temp.push_back(MyRECT(54, 43, 85, 105));
	temp.push_back(MyRECT(54, 86, 127, 105));
	temp.push_back(MyRECT(0, 45, 89, 53));
	temp.push_back(MyRECT(0, 132, 172, 52));
	temp.push_back(MyRECT(0, 173, 213, 52));
	temp.push_back(MyRECT(0, 90, 131, 47));
	this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 8, L"AladdinStand.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	//Sit
	temp.push_back(MyRECT(498, 204, 257, 550));
	temp.push_back(MyRECT(498, 257, 314, 550));
	temp.push_back(MyRECT(498, 314, 373, 550));
	temp.push_back(MyRECT(498, 376, 434, 550));
	this->mAladdinState.push_back(new ObjectState(temp, 20, L"Aladdin.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//Rest
	temp.push_back(MyRECT(498, 376, 434, 550));
	this->mAladdinState.push_back(new ObjectState(temp, 20, L"Aladdin.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//SitAttack
	temp.push_back(MyRECT(630, 4, 58, 674));
	temp.push_back(MyRECT(630, 62, 112, 674));
	temp.push_back(MyRECT(630, 113, 189, 674, D3DXVECTOR3(12, 0, 0)));
	temp.push_back(MyRECT(630, 190, 287, 674, D3DXVECTOR3(19, 0, 0)));
	temp.push_back(MyRECT(630, 297, 383, 674, D3DXVECTOR3(20, 0, 0)));
	temp.push_back(MyRECT(630, 390, 465, 674, D3DXVECTOR3(12, 0, 0)));
	temp.push_back(MyRECT(630, 473, 522, 674, D3DXVECTOR3(0, 0, 0)));
	this->mAladdinState.push_back(new ObjectState(temp, 13, L"Aladdin.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	//Attack1
	temp.push_back(MyRECT(313, 6, 54, 390));
	temp.push_back(MyRECT(313, 54, 110, 390));
	temp.push_back(MyRECT(313, 110, 169, 390));
	temp.push_back(MyRECT(313, 168, 256, 390, D3DXVECTOR3(20, 0, 0)));
	temp.push_back(MyRECT(313, 258, 318, 390, D3DXVECTOR3(7, 0, 0)));
	
	this->mAladdinState.push_back(new ObjectState(temp, 13, L"Aladdin.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	//RopeClimb
	temp.push_back(MyRECT(0, 43, 75, 63));
	temp.push_back(MyRECT(0, 0, 42, 62));
	temp.push_back(MyRECT(0, 76, 107, 76));
	temp.push_back(MyRECT(0, 167, 195, 81));
	temp.push_back(MyRECT(0, 108, 137, 86));
	temp.push_back(MyRECT(0, 138, 166, 89));
	temp.push_back(MyRECT(0, 196, 224, 79));
	temp.push_back(MyRECT(0, 225, 253, 74));
	this->mAladdinState.push_back(new ObjectStateWithLoop(temp, 13, L"RopeClimb.png", D3DXVECTOR2(0, -0.2), CenterArchor::CenterBottom));
	temp.clear();


	//RunAndJump
	temp.push_back(MyRECT(77, 159, 196, 127));
	temp.push_back(MyRECT(59, 117, 158, 101));
	temp.push_back(MyRECT(0, 175, 220, 76));
	temp.push_back(MyRECT(54, 59, 116, 111));
	temp.push_back(MyRECT(49, 0, 58, 91));
	temp.push_back(MyRECT(49, 0, 58, 91));
	temp.push_back(MyRECT(0, 0, 61, 48));
	temp.push_back(MyRECT(0, 62, 120, 53));
	temp.push_back(MyRECT(0, 121, 174, 58));

	this->mAladdinState.push_back(new ObjectState(temp, 11, L"AladdinAction\\AladdinRunJump.png", D3DXVECTOR2(0, 0), D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	//chibinh nem qua
	temp.push_back(MyRECT(1465, 6, 46, 1530));
	temp.push_back(MyRECT(1465, 53, 100, 1530));
	temp.push_back(MyRECT(1465, 107, 151, 1530));
	temp.push_back(MyRECT(1465, 157, 198, 1530));
	temp.push_back(MyRECT(1465, 205, 260, 1530));
	temp.push_back(MyRECT(1465, 266, 316, 1530));
	temp.push_back(MyRECT(1465, 323, 363, 1530));
	temp.push_back(MyRECT(1465, 370, 413, 1530));
	this->mAladdinState.push_back(new ObjectState(temp, 20, L"Aladdinblue.png", D3DXVECTOR2(0, 0), D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	//chibinh ngoi nem
	temp.push_back(MyRECT(1535, 6, 62, 1585));
	temp.push_back(MyRECT(1535, 69, 130, 1585));
	temp.push_back(MyRECT(1535, 137, 176, 1585));
	temp.push_back(MyRECT(1535, 183, 224, 1585));
	temp.push_back(MyRECT(1535, 230, 284, 1585));
	temp.push_back(MyRECT(1535, 290, 374, 1585));
	temp.push_back(MyRECT(1535, 384, 443, 1585));
	this->mAladdinState.push_back(new ObjectState(temp, 13, L"Aladdinblue.png", D3DXVECTOR2(0, 0), D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();


	//RunAttack
	temp.push_back(MyRECT(61, 112, 147, 113));
	temp.push_back(MyRECT(0, 74, 125, 60, D3DXVECTOR3(4, 8, 0)));
	temp.push_back(MyRECT(61, 61, 111, 114, D3DXVECTOR3(5, 8, 0)));
	temp.push_back(MyRECT(0, 126, 174, 60, D3DXVECTOR3(3, 6, 0)));
	temp.push_back(MyRECT(0, 0, 73, 60, D3DXVECTOR3(12, 4, 0)));
	temp.push_back(MyRECT(61, 0, 60, 111,D3DXVECTOR3(12,2,0)));
	this->mAladdinState.push_back(new ObjectState(temp, 13, L"AladdinAction\\RunAttack.png", D3DXVECTOR2(0.5f, 0.0f), CenterArchor::CenterBottom));
	temp.clear();


	this->mCurrentState = AState::DoNothing;

	this->mPosition = pos;
	this->mAladdinState.at(mCurrentState)->SetPosition(pos);
	
	this->mDir = Direction::Right;
	

	this->mTime = 0;
	this->allowStateChange = true;
	this->allowAttack = true;
	this->allowJump = true;
	this->mIsGrounded = true;
	isClimbing = false;


}

void AladdinCharacter::Update(float DeltaTime)
{
	

	/*if (this->mAladdinState.at(this->mCurrentState)->GetPosition().x >= 747 && this->mAladdinState.at(this->mCurrentState)->GetPosition().x <= 753 && this->mAladdinState.at(this->mCurrentState)->GetPosition().y < 470 && isClimbing == false)
	{
		isClimbing = true;
		this->mAladdinState.at(this->mCurrentState)->SetPosition(750, this->mAladdinState.at(this->mCurrentState)->GetPosition().y);
		setAllowStateChange(true);
		this->setCurrentState(AState::RopeClimb);
	}*/
	//printLog(to_string(this->mAladdinState.at(this->mCurrentState)->GetPosition().x).c_str());
	switch (this->mCurrentState)
	{
	case AState::DoNothing:
		printLog("DoNothing");
		break;
	case AState::Walk:
		printLog("Walk");
		break;
	case AState::StopWalk:
		printLog("StopWalk");
		break;
	case AState::LookUp:
		printLog("LookUp");
		break;
	case AState::Attack1:
		printLog("Attack1");
		break;
	case AState::Stand:
		printLog("Stand");
		break;
	case AState::Sit:
		printLog("Sit");
		break;
	case AState::SitAttack:
		printLog("SitAttack");
		break;
	case AState::RunAndJump:
		printLog("RunAndJump");
		break;
	case AState::ThrowApple:
		printLog("ThrowApple");
	case AState::SitThrow:
		printLog("SitThrow");
	default:
		printLog("Else");
		break;
	}
	//printLog(to_string(mCurrentState).c_str());

	this->mAladdinState.at(mCurrentState)->SetFlipVertical((mDir == Direction::Left) ? (true) : (false));
	
	if (this->mCurrentState != AState::RopeClimb)
	{
		if (this->mCurrentState != AState::RunAndJump)
			this->mAladdinState.at(mCurrentState)->Update(DeltaTime);
		else
			this->mAladdinState.at(mCurrentState)->Update(mTime);

	}
	else
	{
		if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_UP))
		{
			this->mAladdinState.at(this->mCurrentState)->Animate(DeltaTime);
			this->mAladdinState.at(mCurrentState)->Move(DeltaTime);				
		}
	}

	switch (this->mCurrentState)
	{
	case AState::DoNothing: //Trường hợp không làm gì
	{
		if (this->mTime >= 50 * DeltaTime)
		{
			//this->mAladdinState.at(AState::Stand)->SetPosition(this->mPosition);
			this->allowStateChange = true;
			this->setCurrentState(AState::Stand);
			this->mTime = 0;
		}
		else
		{			
			this->mTime += DeltaTime;			
		}
		break;
	}
	case AState::Walk: //Trường hợp đang đi
	{
		if (this->mTime >= 30 * DeltaTime)
		{
			this->mIsStopAnimation = true;	//Cờ hiệu cho hành động dừng
		}
		else
		{
			this->mTime += DeltaTime;
		}
		break;
	}
	
	case AState::RunAndJump:
	{
		float vx = (KeyboardHelper::GetInstance()->IsKeyDown(DIK_RIGHT)
			|| KeyboardHelper::GetInstance()->IsKeyDown(DIK_LEFT)) ?
			0.36 : 0;
		/*if (mIsGrounded == true)
		{
			mJumpHeight = this->mAladdinState.at(mCurrentState)->GetPosition().y + 170;
			this->mAladdinState.at(mCurrentState)->SetVelocity(0, 0);
			mIsGrounded = false;
			mIsFalling = false;
			mIsReachJumpHeight = false;
		}
		else
		{
			
			if ( mIsReachJumpHeight == false)
			{				
				this->mAladdinState.at(mCurrentState)->SetVelocity(vx, 0.5);
				if (this->mAladdinState.at(mCurrentState)->GetPosition().y >= mJumpHeight)
				{
					mIsReachJumpHeight = true;
				}					
			}
			else
			{

				if (mIsFalling == false)
				{
					this->mAladdinState.at(mCurrentState)->SetVelocity(vx, 0.06);
					if (this->mAladdinState.at(mCurrentState)->GetPosition().y >= mJumpHeight + 18)
					{
						mIsFalling = true;						
					}						
				}
				else				
				{					
					this->mAladdinState.at(mCurrentState)->SetVelocity(vx , -0.5);
				}
				
			}
		}*/
		 
		//float vy = -2 * 0.5 *0.7;//Sin(PI/4) ~ 0.7
		/*float vy = -10;
		printLog(to_string(this->mAladdinState.at(mCurrentState)->GetPosition().y).c_str());*/
		
		mTime += DeltaTime/16;

		this->mAladdinState.at(mCurrentState)->SetVelocity(vx, 0.85);
		this->mAladdinState.at(mCurrentState)->SetAcceleration(0, -0.05);

		

		break;
	}
	case AState::Stand:
		
		break;
	case AState::ThrowApple:
		if (this->mAladdinState.at(mCurrentState)->GetCurrentIdx() == 3 && this->mAladdinState.at(mCurrentState)->isNextFrame == true)
		{
			mListThrowingApple.push_back(new ThrowingApple(D3DXVECTOR3(this->mAladdinState.at(mCurrentState)->GetPosition().x + ((this->mDir == Direction::Right)? 1: -1) * 40, this->mAladdinState.at(mCurrentState)->GetPosition().y +  125, 0),this->mDir));
		}			
		break;
	case AState::SitThrow:
		if (this->mAladdinState.at(mCurrentState)->GetCurrentIdx() == 3 && this->mAladdinState.at(mCurrentState)->isNextFrame == true)
		{
			mListThrowingApple.push_back(new ThrowingApple(D3DXVECTOR3(this->mAladdinState.at(mCurrentState)->GetPosition().x + ((this->mDir == Direction::Right) ? 1 : -1)* 32, this->mAladdinState.at(mCurrentState)->GetPosition().y +  95 , 0), this->mDir));
		}
		break;
	}

	//Kiểm tra danh sách các táo đã ném ra nếu xong thì bỏ khỏi list;
	for (int i = 0; i < mListThrowingApple.size(); i++)
	{
		mListThrowingApple.at(i)->Update(DeltaTime);
		if (mListThrowingApple.at(i)->isDone() == true)
		{
			mListThrowingApple.erase(mListThrowingApple.begin() + i);
		}
	}

	this->mPosition = this->mAladdinState.at(mCurrentState)->GetPosition();
	this->mAladdinState.at(this->mCurrentState)->mSprite->SetPosition(mPosition);

	//Bounding box update
	//this->mHeight = (this->mAladdinState.at(mCurrentState)->mSprite->GetSourceRect().bottom - this->mAladdinState.at(mCurrentState)->mSprite->GetSourceRect().top) * 2.5;
	//this->mWidth = (this->mAladdinState.at(mCurrentState)->mSprite->GetSourceRect().right - this->mAladdinState.at(mCurrentState)->mSprite->GetSourceRect().left) * 2;
}

void AladdinCharacter::Render(float DeltaTime)
{
	//this->Transform();
	this->mAladdinState.at(this->mCurrentState)->Render();

	for (int i = 0; i < mListThrowingApple.size(); i++)
	{
		mListThrowingApple.at(i)->Render(DeltaTime);
		
	}
}

void AladdinCharacter::OnKeyDown(int keyCode)
{

	switch (keyCode)
	{
	case VK_RIGHT:
		this->setDirection(Direction::Right);
		break;
	case VK_LEFT:
		this->setDirection(Direction::Left);
		break;	
	case VK_ESCAPE:
		PostMessage(GLOBAL::GetHWND(), WM_CLOSE, 0, 0);
	}
}

void AladdinCharacter::OnKeyUp(int keyCode)
{
	if(keyCode	== 83) //S
		this->allowAttack = true;

	if (keyCode == 65) //A
		this->allowAttack = true;
	
	if (keyCode == 68) //D
		this->allowJump = true;

}

void AladdinCharacter::ProcessInput()
{
	flagKeyPressed = false;
	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_RIGHT) || KeyboardHelper::GetInstance()->IsKeyDown(DIK_LEFT))
	{
		switch (this->mCurrentState)
		{
		case AState::Sit:
		case AState::LookUp:
		case AState::RopeClimb:
		case AState::RunAttack: //Chuyển từ chạy đánh sang chạy
			flagKeyPressed = true;
			if (this->mAladdinState.at(mCurrentState)->isDone())
			{				
				this->setAllowStateChange(true);
				this->setCurrentState(AState::Walk);
			
			}
			break;
		case AState::RunAndJump:
			break;
		default:
			flagKeyPressed = true;
			this->setAllowStateChange(true);
			this->setCurrentState(AState::Walk);
		}			
	}

	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_UP))
	{
		switch (this->mCurrentState)
		{
		case AState::Sit:
		case AState::RopeClimb:
		case AState::RunAndJump:
			break;
		default:
			flagKeyPressed = true;
			this->setAllowStateChange(true);
			this->setCurrentState(AState::LookUp);
		}
	}

	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_DOWN))
	{
		
		switch (this->mCurrentState)
		{
		case AState::SitAttack:
		case AState::SitThrow:
			if (this->mAladdinState.at(mCurrentState)->isDone())
			{
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::Sit);
			}

			break;
		case AState::RunAndJump:
		case AState::RopeClimb:
			break;
		default:
			flagKeyPressed = true;
			this->setAllowStateChange(true);
			this->setCurrentState(AState::Sit);
		}
	}

	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_A))
	{
		switch (this->mCurrentState)
		{
		//case AState::Attack1:
		
		case AState::RunAndJump:
		case AState::RopeClimb:
		case AState::ThrowApple:
		case AState::SitThrow:
			break;
		case AState::SitAttack:
		case AState::Sit:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::SitThrow);

				break;
			}

		default:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::ThrowApple);

				break;
			}
		}
	}
	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_S))
	{
		switch (this->mCurrentState)
		{
		case AState::RunAttack:
		case AState::Attack1:
		case AState::SitAttack:
		case AState::RunAndJump:
		case AState::RopeClimb:
			break;
		case AState::SitThrow:
		case AState::Walk:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::RunAttack);
				break;
			}
		case AState::Sit:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::SitAttack);
				break;
			}
		default:
			if (allowAttack)
			{
				allowAttack = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::Attack1);
				break;
			}			
		}
	}
	

	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_D))
	{
		switch (this->mCurrentState)
		{
		case AState::RopeClimb:
		case AState::Walk:
			if (mIsGrounded && allowJump)
			{
				allowJump = false;
				flagKeyPressed = true;
				this->setAllowStateChange(true);
				this->setCurrentState(AState::RunAndJump);
				break;
			}
		case AState::SitAttack:
			break;
		default:
			break;
		}
	}

	if (flagKeyPressed == false)
	{
		switch (this->mCurrentState)
		{
		
		case AState::Attack1:
		case AState::StopWalk:
		case AState::SitAttack:
		case AState::ThrowApple:
		case AState::SitThrow:			
			if (this->mAladdinState.at(mCurrentState)->isDone())
			{
				this->setAllowStateChange(true);
				this->setCurrentState(AState::DoNothing);
			}
			break;
		case AState::Stand:
		case AState::RopeClimb:
			break;
		
		case AState::RunAndJump:
			if (this->mAladdinState.at(mCurrentState)->GetPosition().y <  WORLD_Y - MAP_HEIGHT + 160)
			{
				mIsGrounded = true;
				this->mAladdinState.at(mCurrentState)->SetVelocity(0, 0);
				this->mAladdinState.at(mCurrentState)->SetPosition(this->mAladdinState.at(mCurrentState)->GetPosition().x, WORLD_Y - MAP_HEIGHT + 160);
				this->allowStateChange = true;
				this->setCurrentState(AState::DoNothing);
			}
			break;
		case AState::RunAttack:
		default:
			this->setAllowStateChange(true);
			this->setCurrentState(AState::DoNothing);
			break;
		}
	}

	
}

void AladdinCharacter::setCurrentState(AState state)
{
	//Kiểm tra xem state thay đổi có khác state hiện tại
	if (this->mCurrentState == state)
	{
		return;
	}
		


	//Kiểm tra biến cho phép sự thay đổi
	if (this->allowStateChange == false)
		return;
	else
		this->allowStateChange = false;

	this->_BeforeStateChange(state);

	this->mCurrentState = state;

	this->_AfterStateChange();

}

void AladdinCharacter::_BeforeStateChange(AState &changeTo)
{	
	

	//Khi chuyển từ hành động chạy sang hành động đứng và biến cờ hiệu hành động dừng
	if ((this->mCurrentState == AState::Walk) && (changeTo == AState::DoNothing) && (this->mIsStopAnimation == true))
	{
		changeTo = AState::StopWalk;
		this->mIsStopAnimation = false;
	}
	
	//Khi chuyển từ SitAttack qua Sit thì set frame cuối cùng
	if ((this->mCurrentState == AState::SitAttack || this->mCurrentState == AState::SitThrow) && (changeTo == AState::Sit) )
	{
		this->mAladdinState.at(AState::Sit)->GoToLastFrameIdx();
		this->allowStateChange = true;
	}

	//Khi chuyển từ RunAttack qua Run thì set frame cuối cùng
	if ((this->mCurrentState == AState::RunAttack) && (changeTo == AState::Walk))
	{
		this->mAladdinState.at(AState::RunAttack)->GoToFrame(12);

		this->allowStateChange = true;
	}

	//Thay vị trí hiện tại cho state khác
	this->mPosition = this->mAladdinState.at(this->mCurrentState)->GetPosition();
	this->mAladdinState.at(changeTo)->SetPosition(this->mPosition);
	
	//Reset lại frame idx của state cũ
	this->mAladdinState.at(this->mCurrentState)->resetFrame();

	if (mCurrentState != AState::RopeClimb)
		isClimbing = false;
	
	
}
void AladdinCharacter::_AfterStateChange()
{
	switch (this->mCurrentState)
	{
	case AState::DoNothing:
		this->mTime = 0;
		break;
	case AState::Walk:
		this->mTime = 0;
		break;
	case AState::RunAndJump:
		this->mTime = 0;
		break;
	}
}
Direction AladdinCharacter::getDirection()
{
	return this->mDir;
}
void AladdinCharacter::setDirection(Direction dir)
{
	mDir = dir;
}
void AladdinCharacter::setAllowStateChange(bool allow)
{
	this->allowStateChange = allow;
}

AState AladdinCharacter::getCurrentState()
{
	return this->mCurrentState;
}



