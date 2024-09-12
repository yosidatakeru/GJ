#include "Player.h"
#include <cassert>
#include <TextureManager.h>
//#include <GameScene.cpp>

void Player::Initialize(Model* model, uint32_t textureHandle,GameMap*gameMap) 
{ 
	assert(model);

	model_ = model;
	textureHandle_ = textureHandle;

	input_ = Input::GetInstance();

	//textureHandle_ = TextureManager::Load("sample.png");

	gameMap_ = gameMap;

	worldTransform_.translation_.x = 20.0f;
	worldTransform_.translation_.y = 32.0f;
	worldTransform_.translation_.z = 0;

	worldTransform_.Initialize();

	// スコア
	textureHandleNumber_ = TextureManager::Load("number.png");
	for (int i = 0; i < 5; i++) {

		spriteNumber_[i] = Sprite::Create(textureHandleNumber_, {300.0f + i * 26, 0});
	}
}

void Player::Update() 
{ 
	if (input_->PushKey(DIK_RIGHT)) 
	{
		float x = worldTransform_.translation_.x + 0.1f;
		float y = worldTransform_.translation_.y;
		if (gameMap_->CheckStage(x, y) == false && gameMap_->NoBlock(x, y) == false 
			&& gameMap_->ScoreBlock(x, y) == false && gameMap_->VeryScoreBlock(x, y) == false) {
			worldTransform_.translation_.x += 0.1f;
		} 
		
		
	}

	if (input_->PushKey(DIK_LEFT)) {
		float x = worldTransform_.translation_.x - 0.1f;
		float y = worldTransform_.translation_.y;
		if (gameMap_->CheckStage(x, y) == false && gameMap_->NoBlock(x, y) == false
			&& gameMap_->ScoreBlock(x, y) == false && gameMap_->VeryScoreBlock(x, y) == false) {
			worldTransform_.translation_.x -= 0.1f;
		}

		
	}

	if (input_->PushKey(DIK_UP)) {
		float x = worldTransform_.translation_.x;
		float y = worldTransform_.translation_.y + 0.1f;
		if (gameMap_->CheckStage(x, y) == false && gameMap_->NoBlock(x, y) == false
			&& gameMap_->ScoreBlock(x, y) == false && gameMap_->VeryScoreBlock(x, y) == false) {
			worldTransform_.translation_.y += 0.1f;
		}
	}

	if (input_->PushKey(DIK_DOWN)) {
		float x = worldTransform_.translation_.x;
		float y = worldTransform_.translation_.y - 0.1f;
		if (gameMap_->CheckStage(x, y) == false && gameMap_->NoBlock(x, y) == false 
			&& gameMap_->ScoreBlock(x, y) == false && gameMap_->VeryScoreBlock(x, y) == false) {
			worldTransform_.translation_.y -= 0.1f;
		}
	}

	if (input_->PushKey(DIK_SPACE)&&input_->PushKey(DIK_DOWN)){
		float x = worldTransform_.translation_.x;
		float y = worldTransform_.translation_.y-1;
		if (gameMap_->CheckBlock(x, y) == true) {
			gameMap_->CheckBreak(x,y);

		} else if (gameMap_->ScoreBlock(x,y)==true) {
			gameMap_->ScoreBreak(x, y);

			gameScore_ += 50;

		} else if (gameMap_->VeryScoreBlock(x, y) == true) {
			gameMap_->VeryScoreBreak(x, y);

			gameScore_ += 100;
		}
		
	}

	if (input_->PushKey(DIK_SPACE) && input_->PushKey(DIK_RIGHT)) {
		float x = worldTransform_.translation_.x + 1;
		float y = worldTransform_.translation_.y;
		if (gameMap_->CheckBlock(x, y) == true) {
			gameMap_->CheckBreak(x, y);

		} else if (gameMap_->ScoreBlock(x, y) == true) {
			gameMap_->ScoreBreak(x, y);

			gameScore_ += 50;

		} else if (gameMap_->VeryScoreBlock(x, y) == true) {
			gameMap_->VeryScoreBreak(x, y);

			gameScore_ += 100;
		}
	}

	if (input_->PushKey(DIK_SPACE) && input_->PushKey(DIK_LEFT)) {
		float x = worldTransform_.translation_.x -1;
		float y = worldTransform_.translation_.y;
		if (gameMap_->CheckBlock(x, y) == true) {
			gameMap_->CheckBreak(x, y);

		} else if (gameMap_->ScoreBlock(x, y) == true) {
			gameMap_->ScoreBreak(x, y);

			gameScore_ += 50;

		} else if (gameMap_->VeryScoreBlock(x, y) == true) {
			gameMap_->VeryScoreBreak(x, y);

			gameScore_ += 100;
		}
	}

	if (input_->PushKey(DIK_SPACE) && input_->PushKey(DIK_UP)) {
		float x = worldTransform_.translation_.x ;
		float y = worldTransform_.translation_.y+1;
		if (gameMap_->CheckBlock(x, y) == true) {
			gameMap_->CheckBreak(x, y);

		} else if (gameMap_->ScoreBlock(x, y) == true) {
			gameMap_->ScoreBreak(x, y);

			gameScore_ += 50;

		} else if (gameMap_->VeryScoreBlock(x, y) == true) {
			gameMap_->VeryScoreBreak(x, y);

			gameScore_ += 100;
		}
	}

	if (input_->PushKey(DIK_SPACE) && input_->PushKey(DIK_DOWN)) {
		float x = worldTransform_.translation_.x ;
		float y = worldTransform_.translation_.y-1;
		if (gameMap_->CheckBlock(x, y) == true) {
			gameMap_->CheckBreak(x, y);

		} else if (gameMap_->ScoreBlock(x, y) == true) {
			gameMap_->ScoreBreak(x, y);

			gameScore_ += 50;

		} else if (gameMap_->VeryScoreBlock(x, y) == true) {
			gameMap_->VeryScoreBreak(x, y);

			gameScore_ += 100;
		}
	}
	worldTransform_.matWorld_ = MakeAffineMatrix(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

	worldTransform_.TransferMatrix(); 

}

void Player::Draw(ViewProjection& viewProjection) 
{
	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}

void Player::DrawScore() {
	int eachNumber[5] = {};
	int number = gameScore_;

	int keta = 10000;

	for (int i = 0; i < 5; i++) {

		eachNumber[i] = number / keta;
		number = number % keta;
		keta = keta / 10;
	}
	for (int i = 0; i < 5; i++) {

		spriteNumber_[i]->SetSize({32, 64});
		spriteNumber_[i]->SetTextureRect({32.0f * eachNumber[i], 0}, {32, 64});
		spriteNumber_[i]->Draw();
	}
}
