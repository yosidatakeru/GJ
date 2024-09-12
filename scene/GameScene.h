#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "MathUtilityForText.h"

#include "GameMap.h"
#include "Player.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();



	void DrawTimer();
	

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
	/// 
	
	

	//プレイヤー
	uint32_t textureHandlePlayer_ = 0;
	Model* modelPlayer_ = nullptr;
	WorldTransform worldTransformPlayer_;

	// マップ
	uint32_t textureHandleMap_ = 0;
	
	Model* modelMap_ = nullptr;
	WorldTransform worldTransform_[10][10];

	ViewProjection viewProjection_;

	GameMap* gameMap_ = nullptr;

	Player* player_ = nullptr;

	//タイマー

	uint32_t textureHandleTimer_ = 60;
	Model* modelTimer_ = nullptr;
	Sprite* spriteTimer_[5] = {};


	int gameTimer_ = 10;
	
	uint32_t textureHandleScore_ = 0;
	Sprite* spriteScore_ = nullptr;

};
