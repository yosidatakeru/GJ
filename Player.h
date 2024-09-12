#pragma once
#include "MathUtilityForText.h"
#include "Model.h"
#include "WorldTransform.h"
#include "Input.h"

#include "GameMap.h"
#include <Sprite.h>


class Player {
public:
	void Initialize(Model* model, uint32_t textureHandle,GameMap* gameMap);

	void Update();

	void Draw(ViewProjection& viewProjection);

	void DrawScore();

	float GetX() { return worldTransform_.translation_.x; }
	float GetY() { return worldTransform_.translation_.y; }

private:
	Input* input_ = nullptr;

	WorldTransform worldTransform_;

	Model* model_ = nullptr;

	uint32_t textureHandle_ = 0u;

	GameMap* gameMap_ = nullptr;

	// スコア
	uint32_t textureHandleNumber_ = 0;
	Sprite* spriteNumber_[5] = {};

	int gameScore_ = 0;
};