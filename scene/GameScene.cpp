#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() {
	// クラスの開放
	delete gameMap_;

	// モデルの開放
	delete modelPlayer_;
	delete modelMap_;
	delete player_;
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	// プレイヤー
	textureHandlePlayer_ = TextureManager::Load("sample.png");
	modelPlayer_ = Model::Create();
	worldTransformPlayer_.Initialize();
	
	// マップ
	textureHandleMap_ = TextureManager::Load("SoilBlock.png");
	modelMap_ = Model::Create();

	textureHandleTimer_ = TextureManager::Load("number.png");
	for (int i = 0; i < 5; i++) {

		spriteTimer_[i] = Sprite::Create(textureHandleTimer_, {300.0f + i * 26, 0});
	}

	textureHandleScore_ = TextureManager::Load("score.png");

	spriteScore_ = Sprite::Create(textureHandleScore_, {150, 5});

	
	//worldTransform_[5][10].Initialize();

	viewProjection_.translation_.x = 0;
	viewProjection_.translation_.y = 0;
	viewProjection_.translation_.z = -20;
	viewProjection_.Initialize();

	

	


	// クラス
	player_ = new Player();
	gameMap_ = new GameMap();
	
	// 初期化
	player_->Initialize(modelPlayer_, textureHandlePlayer_, gameMap_);
	gameMap_->Initialize(modelMap_, textureHandleMap_);
}

void GameScene::Update() {
	gameMap_->Update();
	player_->Update();
	
	textureHandleTimer_--;
	if (textureHandleTimer_ <=0) {
		gameTimer_ -= 1;
		textureHandleTimer_ = 60;

	}


	if (input_->PushKey(DIK_Z))
	{
		viewProjection_.translation_.z += 0.1f;
	}

	if (input_->PushKey(DIK_X)) {
		viewProjection_.translation_.z -= 0.1f;
	}

	viewProjection_.translation_.x = player_->GetX();
	viewProjection_.translation_.y = player_->GetY();

	viewProjection_.UpdateMatrix();
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	
	

	/// 
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	player_->Draw(viewProjection_);

	gameMap_->Draw(viewProjection_);

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);
	

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// 
	
	
	player_->DrawScore();
	DrawTimer();

	spriteScore_->Draw();


	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	

#pragma endregion
}

void GameScene::DrawTimer() {
	int eachNumber[5] = {};
	int number = gameTimer_;

	int keta = 10000;

	for (int i = 0; i < 5; i++) {

		eachNumber[i] = number / keta;
		number = number % keta;
		keta = keta / 10;
	}
	for (int i = 0; i < 5; i++) {

		spriteTimer_[i]->SetSize({50, 100});
		spriteTimer_[i]->SetTextureRect({32.0f * eachNumber[i], -20}, {32, 64});
		spriteTimer_[i]->Draw();
	}
}


