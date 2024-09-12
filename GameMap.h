#pragma once
#pragma once

#include "MathUtilityForText.h"
#include "Model.h"
#include "WorldTransform.h"
#include <Sprite.h>

class GameMap {

public:
	void Initialize(Model* model, uint32_t textureHandle);

	void Update();


	void Draw(ViewProjection& viewProjection);

	void Draw2D();

	bool CheckStage(float x, float y);

	bool CheckBlock(float x, float y);

	bool CheckBreak(float x, float y);

	bool NoBlock(float x, float y);

	bool ScoreBlock(float x, float y);

	bool ScoreBreak(float x, float y);

	bool VeryScoreBlock(float x, float y);

	bool VeryScoreBreak(float x, float y);

private:
	static const int mapX = 20;
	static const int mapY = 20;

	WorldTransform worldTransform_[mapX][mapY];

	Model* model_ = nullptr;

	uint32_t textureHandle_ = 0u;
	uint32_t textureHandleMapA_ = 0;
	uint32_t textureHandleMapB_ = 0;
	uint32_t textureHandleMapC_ = 0;
	Model* modelMap_ = nullptr;

	//背景
	uint32_t textureHandleBackground_ = 0;
	Sprite* spriteBackground_;

	

	int mapData[mapX][mapY] = {
	    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2},
        {2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2},
	    {2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2},
        {2, 1, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 2},
	    {2, 3, 3, 1, 3, 4, 3, 1, 3, 1, 3, 3, 3, 1, 3, 1, 3, 1, 3, 2},
        {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 2},
        {2, 1, 3, 3, 3, 3, 3, 1, 3, 3, 1, 3, 4, 3, 3, 3, 3, 4, 3, 2},
	    {2, 4, 1, 3, 1, 3, 1, 3, 3, 3, 1, 3, 3, 3, 3, 1, 3, 1, 3, 2},
        {2, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2},
        {2, 3, 3, 1, 3, 1, 3, 1, 4, 3, 1, 3, 3, 1, 1, 3, 3, 3, 3, 2},
	    {2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 3, 1, 3, 3, 3, 2},
        {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
	    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	};
};