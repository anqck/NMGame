﻿#include "DemoScene.h"



DemoScene::DemoScene()
{
	this->mSceneID = SceneID::SceneID_GameScene1;
	SoundHelper::GetInstance()->Stop();
	this->LoadResource();

	mScore = 0;
	mDone = false;


	
}

DemoScene::DemoScene(AladdinGame * game) : DemoScene()
{
	this->mGame = game;
	//allowAttack = true;

}

DemoScene::~DemoScene()
{
}

void DemoScene::Update(float DeltaTime)
{
	this->mMap->Update(DeltaTime);

	mListObjectInViewPort = mQuadTree->GetListObjectInViewport(Camera::GetInstance()->GetBoundingBoxInWorldAxis());	

	CheckCollision(DeltaTime);

	for (int i = 0; i < mListObjectInViewPort.size(); i++)
	{

		mListObjectInViewPort.at(i)->Update(DeltaTime);
	}

	
	for (int i = 0; i < mListFlyingObject.size(); i++)
	{
		if (mListFlyingObject.at(i)->isDone() == true)
		{
			delete (mListFlyingObject.at(i));
			mListFlyingObject.erase(mListFlyingObject.begin() + i);
			i--;
		}
		else
			mListFlyingObject.at(i)->Update(DeltaTime);
	}

	this->mAladdin->Update(DeltaTime);

	
	
	Camera::GetInstance()->Update(this->mAladdin);	

	mSceneInformation->Update(DeltaTime);
	
	
	
}

void DemoScene::Render(float DeltaTime)
{

	

	this->mMap->Render(DeltaTime, MapLevel::MapBackground);
	this->mMap->Render(DeltaTime,MapLevel::MapLevel1);

	//this->mCamel->Render(DeltaTime);

	
	for (int i = 0; i < mListObjectInViewPort.size(); i++)
	{
		mListObjectInViewPort.at(i)->Render(DeltaTime);
	}

	for (int i = 0; i < mListFlyingObject.size(); i++)
	{
		mListFlyingObject.at(i)->Render(DeltaTime);
	}


	this->mAladdin->Render(DeltaTime);

	this->mMap->Render(DeltaTime, MapLevel::MapLevel2);

	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_4))
		QuadTree::DrawQuadtree(this->mQuadTree->GetRoot());

	mSceneInformation->Render();

	

}

void DemoScene::LoadResource()
{
	SoundHelper::GetInstance()->Play("Scene1_Background", true, 1);

	this->mMap = new DemoMap();
	this->mScore = 0;

	this->mAladdin = new AladdinCharacter(D3DXVECTOR3(100, WORLD_Y - MAP_HEIGHT + 161,0));


	//Camera::GetInstance()->SetPosition(100.0f, WORLD_Y - MAP_HEIGHT + 90 );

	mQuadTree = new QuadTree();

	mQuadTree->LoadQuadTree("Map//1.txt");

	mSceneInformation = new SceneInformation(this->mAladdin);
	
	

}

void DemoScene::OnKeyDown(int keyCode)
{

	this->mAladdin->OnKeyDown(keyCode);

}

void DemoScene::OnKeyUp(int keyCode)
{

	this->mAladdin->OnKeyUp(keyCode);
}

void DemoScene::ProcessInput()
{
	this->mAladdin->ProcessInput();
}

void DemoScene::CheckCollision(float DeltaTime)
{
	//Reset Aladdin Colission flag
	mAladdin->ResetFlagCollision();

	for (int i = 0; i < mListObjectInViewPort.size(); i++)
	{
		
		//Check collision with Object interact with InteractBB
		if (mListObjectInViewPort.at(i)->GetInteractWithInteractBB())
		{
			mListObjectInViewPort.at(i)->processCollisionAABB(this->mAladdin, this->mAladdin->GetBoundingBox().Intersects(mListObjectInViewPort.at(i)->GetInteractBoundingBox()), CollisionWith::InteractBoundingBox);
		}

		//Check collision with other Object interact with InteractBB
		for (int j = i + 1; j < mListObjectInViewPort.size(); j++)
		{
			if (mListObjectInViewPort.at(j)->GetInteractWithInteractBB()|| mListObjectInViewPort.at(i)->GetInteractWithInteractBB())
			{
				
				//if (Collision::GetSweptBoardphaseBox(mListObjectInViewPort.at(i)->GetBoundingBox(), mListObjectInViewPort.at(i)->GetVelocity(), DeltaTime).Intersects(mListObjectInViewPort.at(j)->GetBoundingBox()) == true)
				{
					CollisionResult res = Collision::SweptAABB(DeltaTime, mListObjectInViewPort.at(i)->GetBoundingBox(), this->mListObjectInViewPort.at(i)->GetVelocity(), mListObjectInViewPort.at(j)->GetBoundingBox(), mListObjectInViewPort.at(j)->GetVelocity());
					if (res.EntryTime < 1 && res.EntryTime >= 0)
					{
						mListObjectInViewPort.at(i)->processCollision(DeltaTime, mListObjectInViewPort.at(j), res);
						mListObjectInViewPort.at(j)->processCollision(DeltaTime, mListObjectInViewPort.at(i), res);
					}
				}
			}

			if (mListObjectInViewPort.at(i)->GetInteractWithInteractBB())
			{
				mListObjectInViewPort.at(i)->processCollisionAABB(this->mAladdin, this->mAladdin->GetBoundingBox().Intersects(mListObjectInViewPort.at(i)->GetInteractBoundingBox()), CollisionWith::InteractBoundingBox);
				if (mListObjectInViewPort.at(j)->GetInteractWithInteractBB())
				{
					mListObjectInViewPort.at(i)->processCollisionAABB(mListObjectInViewPort.at(j), mListObjectInViewPort.at(j)->GetInteractBoundingBox().Intersects(mListObjectInViewPort.at(i)->GetInteractBoundingBox()), CollisionWith::InteractBoundingBox);
					mListObjectInViewPort.at(j)->processCollisionAABB(mListObjectInViewPort.at(i), mListObjectInViewPort.at(j)->GetInteractBoundingBox().Intersects(mListObjectInViewPort.at(i)->GetInteractBoundingBox()), CollisionWith::InteractBoundingBox);
				}
			}
		}

		

		//Check collision with Object can be attack and Aladdin when attack
		if (this->mListObjectInViewPort.at(i)->GetCanBeAttack())
		{
			if (mAladdin->getCurrentState() == AState::Attack1 || mAladdin->getCurrentState() == AState::SitAttack || mAladdin->getCurrentState() == AState::JumpAttack || mAladdin->getCurrentState() == AState::RunAttack || mAladdin->getCurrentState() == AState::LookUpAttack || mAladdin->getCurrentState() == AState::RopeAttack || mAladdin->getCurrentState() == AState::SwingAttack)
				mListObjectInViewPort.at(i)->processCollisionAABB(this->mAladdin, this->mAladdin->GetAttackBoundingBox().Intersects(mListObjectInViewPort.at(i)->GetBoundingBox()), CollisionWith::SwordBoundingBox);
		}

		//Check collision with Object can Attack Aladdin
		if (this->mListObjectInViewPort.at(i)->GetCanAttack())
		{
			mAladdin->processCollisionAABB(this->mListObjectInViewPort.at(i), this->mListObjectInViewPort.at(i)->GetAttackBoundingBox().Intersects(mAladdin->GetBoundingBox()), CollisionWith::SwordBoundingBox);
		}

		//Check collision with Aladdin

		if (Collision::GetSweptBoardphaseBox(mAladdin->GetBoundingBox(), mAladdin->getCurrentObjectState()->GetVelocity(), DeltaTime).Intersects(this->mListObjectInViewPort.at(i)->GetBoundingBox()) == true)
		{

			if (this->mListObjectInViewPort.at(i)->GetID() == EObjectID::STAIR &&this->mListObjectInViewPort.at(i)->GetStairLayer() == mAladdin->GetStairLayer())
			{
				CollisionResult res = Collision::SweptAABB(DeltaTime, mAladdin->GetBoundingBox(), mAladdin->getCurrentObjectState()->GetVelocity(), this->mListObjectInViewPort.at(i)->GetBoundingBox(), D3DXVECTOR2(0, 0));
				if (res.EntryTime < 1 && res.EntryTime >= 0)
				{
					mListObjectInViewPort.at(i)->processCollision(DeltaTime, mAladdin, res);
					mAladdin->processCollision(DeltaTime, mListObjectInViewPort.at(i), res);
				}
			}

			else
			{
				CollisionResult res = Collision::SweptAABB(DeltaTime, mAladdin->GetBoundingBox(), mAladdin->getCurrentObjectState()->GetVelocity(), this->mListObjectInViewPort.at(i)->GetBoundingBox(), D3DXVECTOR2(0, 0));
				if (res.EntryTime < 1 && res.EntryTime >= 0)
				{

					mListObjectInViewPort.at(i)->processCollision(DeltaTime, mAladdin, res);
					mAladdin->processCollision(DeltaTime, mListObjectInViewPort.at(i), res);
				}
			}

		}



		if (mListObjectInViewPort.at(i)->GetID() != EObjectID::STAIR)
			mAladdin->processCollisionAABB(mListObjectInViewPort.at(i), this->mAladdin->GetBoundingBox().Intersects(mListObjectInViewPort.at(i)->GetBoundingBox()), CollisionWith::BoundingBox);
	}

	//Kiểm tra flying object với các object khác và chính nó
		for (int i = 0; i < mListFlyingObject.size() ; i++)
		{
			for (int j = 0; j < mListObjectInViewPort.size(); j++)
			{
				if (mListObjectInViewPort.at(j)->GetInteractWithInteractBB())
				{					
					mListFlyingObject.at(i)->processCollisionAABB(mListObjectInViewPort.at(j), mListFlyingObject.at(i)->GetInteractBoundingBox().Intersects(mListObjectInViewPort.at(j)->GetInteractBoundingBox()), CollisionWith::InteractBoundingBox);
				}

				if (mListObjectInViewPort.at(j)->GetCanBeHitByFlyingObject()) //Kiểm tra Object có thể va chạm với flying obj không, giảm số lần kt SweptAABB
				{
					if (mListObjectInViewPort.at(j)->GetCanBeAttack())
					{
						
							CollisionResult res = Collision::SweptAABB(DeltaTime, mListFlyingObject.at(i)->GetBoundingBox(), this->mListFlyingObject.at(i)->GetCurrentState()->GetVelocity(), mListObjectInViewPort.at(j)->GetBoundingBox(), mListObjectInViewPort.at(j)->GetCurrentState()->GetVelocity());
							if (res.EntryTime < 1 && res.EntryTime >= 0)
							{
								mListFlyingObject.at(i)->processCollision(DeltaTime, mListObjectInViewPort.at(j), res);
								mListObjectInViewPort.at(j)->processCollision(DeltaTime, mListFlyingObject.at(i), res);
							}
						
					}
					else
					{
						if (Collision::GetSweptBoardphaseBox(mListFlyingObject.at(i)->GetBoundingBox(), this->mListFlyingObject.at(i)->GetCurrentState()->GetVelocity(), DeltaTime).Intersects(mListObjectInViewPort.at(j)->GetBoundingBox()) == true)
						{
							CollisionResult res = Collision::SweptAABB(DeltaTime, mListFlyingObject.at(i)->GetBoundingBox(), this->mListFlyingObject.at(i)->GetCurrentState()->GetVelocity(), mListObjectInViewPort.at(j)->GetBoundingBox(), D3DXVECTOR2(0, 0));
							if (res.EntryTime < 1 && res.EntryTime >= 0)
							{
								mListFlyingObject.at(i)->processCollision(DeltaTime, mListObjectInViewPort.at(j), res);
								mListObjectInViewPort.at(j)->processCollision(DeltaTime, mListFlyingObject.at(i), res);
							}
						}
					}
					
				}
			}


			//Kiểm tra với các flying object khác(vd ThrowApple vs ThrowPot) 
			for (int j = 0; j < mListFlyingObject.size(); j++)
			{
				if (i == j)
					continue;

				if (mListFlyingObject.at(j)->GetCanBeHitByFlyingObject()) //Kiểm tra Object có thể va chạm với flying obj không, giảm số lần kt SweptAABB
				{
					CollisionResult res = Collision::SweptAABB(DeltaTime, mListFlyingObject.at(i)->GetBoundingBox(), this->mListFlyingObject.at(i)->GetCurrentState()->GetVelocity(), this->mListFlyingObject.at(j)->GetBoundingBox(), this->mListFlyingObject.at(j)->GetCurrentState()->GetVelocity());
					if (res.EntryTime < 1 && res.EntryTime >= 0)
					{
						mListFlyingObject.at(i)->processCollision(DeltaTime, this->mListFlyingObject.at(j), res);
						mListFlyingObject.at(j)->processCollision(DeltaTime, mListFlyingObject.at(i), res);
					}
				}
			}

			//Kiểm tra vcham với Aladdin
			if (this->mListFlyingObject.at(i)->GetCanAttack())
			{
				CollisionResult res = Collision::SweptAABB(DeltaTime, this->mListFlyingObject.at(i)->GetBoundingBox(), this->mListFlyingObject.at(i)->GetCurrentState()->GetVelocity(), mAladdin->GetBoundingBox(), mAladdin->getCurrentObjectState()->GetVelocity());
				if (res.EntryTime < 1 && res.EntryTime >= 0)
				{
					mAladdin->processCollision(DeltaTime, this->mListFlyingObject.at(i), res);
					mListFlyingObject.at(i)->processCollision(DeltaTime, mAladdin, res);
				}
			}


			//Kiểm tra vc với Aladdin
			if (this->mListFlyingObject.at(i)->GetCanBeAttack())
			{
				if(mAladdin->getCurrentState() == AState::Attack1 || mAladdin->getCurrentState() == AState::SitAttack || mAladdin->getCurrentState() == AState::JumpAttack || mAladdin->getCurrentState() == AState::LookUpAttack || mAladdin->getCurrentState() == AState::RopeAttack || mAladdin->getCurrentState() == AState::SwingAttack)
					
					mListFlyingObject.at(i)->processCollisionAABB(this->mAladdin, this->mAladdin->GetAttackBoundingBox().Intersects(mListFlyingObject.at(i)->GetBoundingBox()),CollisionWith::SwordBoundingBox);
			}
		}
	

		
		

		


	/*for (int i = 0; i < mListObjectInViewPort.size(); i++)
	{
		for (int j = j + 1 ; i < mListObjectInViewPort.size() - 1; i++)
		{
			
		}
	}*/
}

void DemoScene::GoToLastCheckPoint()
{
	//mQuadTree->LoadQuadTree("Map//1.txt");
	for (int i = 0; i < mQuadTree->GetListAllObject().size(); i++)
	{
		mQuadTree->GetListAllObject().at(i)->ResetDefault();
	}
	
	this->mAladdin->GoToLastCheckPoint();
}


int DemoScene::GetAladdinHP()
{
	return this->mAladdin->GetHP();
}

int DemoScene::GetAladdinLife()
{
	return this->mAladdin->GetLifeCount();
}

int DemoScene::GetScore()
{
	return this->mScore;
}

void DemoScene::SetScore(int number)
{
	this->mScore = number;
}

void DemoScene::AddScore(int number)
{
	this->mScore += number;
}

void DemoScene::AddFlyingObject(GameVisibleEntity *obj)
{
	mListFlyingObject.push_back(obj);
}

SceneInformation * DemoScene::GetSceneInformation()
{
	return this->mSceneInformation;
}
