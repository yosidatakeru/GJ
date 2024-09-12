#include "GameMap.h"

#include <cassert>
#include <TextureManager.h>

void GameMap::Initialize(Model* model, uint32_t textureHandle) {
	assert(model);

	model_ = model;

	textureHandle_ = textureHandle;
	textureHandleMapA_ = TextureManager::Load("map.png");
	modelMap_ = Model::Create();

	textureHandleMapB_ = TextureManager::Load("StoneBlock.png");
	

	textureHandleMapC_ = TextureManager::Load("LuckyBlock.png");

	//背景
	textureHandleBackground_ = TextureManager::Load("back.png");

	spriteBackground_ = Sprite::Create(textureHandleBackground_, {0, 0});



	for (int y = 0; y < mapY; y++) {
		for (int x = 0; x < mapX; x++) {
			worldTransform_[y][x].translation_.x = (float)x * 2;
			worldTransform_[y][x].translation_.y = (float)y * 2;
			worldTransform_[y][x].translation_.z = 0;

			worldTransform_[y][x].Initialize();
		}
	}
}

void GameMap::Update() {
	for (int y = 0; y < mapY; y++) {
		for (int x = 0; x < mapX; x++) {
			worldTransform_[y][x].matWorld_ = MakeAffineMatrix(worldTransform_[y][x].scale_, worldTransform_[y][x].rotation_, worldTransform_[y][x].translation_);

			worldTransform_[y][x].TransferMatrix();
		}
	}
}

void GameMap::Draw(ViewProjection& viewProjection) {
	for (int y = 0; y < mapY; y++) {
		for (int x = 0; x < mapX; x++) {
			if (mapData[y][x] == 1) {
				model_->Draw(worldTransform_[y][x], viewProjection, textureHandle_);
			}
		}
	}

	for (int y = 0; y < mapY; y++) {
		for (int x = 0; x < mapX; x++) {
			if (mapData[y][x] == 2) {
				model_->Draw(worldTransform_[y][x], viewProjection, textureHandleMapA_);
			}
		}
	}

	for (int y = 0; y < mapY; y++) {
		for (int x = 0; x < mapX; x++) {
			if (mapData[y][x] == 3) {
				model_->Draw(worldTransform_[y][x], viewProjection, textureHandleMapB_);
			}
		}
	}

	for (int y = 0; y < mapY; y++) {
		for (int x = 0; x < mapX; x++) {
			if (mapData[y][x] == 4) {
				model_->Draw(worldTransform_[y][x], viewProjection, textureHandleMapC_);
			}
		}
	}
}
//背景
void GameMap::Draw2D() { spriteBackground_->Draw(); }

bool GameMap::CheckStage(float px, float py) {
	for (int y = 0; y < mapY; y++) {
		for (int x = 0; x < mapX; x++) {
			if (mapData[y][x] == 1) {
				float x2 = worldTransform_[y][x].translation_.x;
				float y2 = worldTransform_[y][x].translation_.y;
				if (abs(x2 - px) < 2.0 && abs(y2 - py) < 2.0) {
					return true;
				}
			}
		}
	}
	return false;

	}

bool GameMap::CheckBlock(float px, float py) {
	    for (int y = 0; y < mapY; y++) {
		    for (int x = 0; x < mapX; x++) {
			    if (mapData[y][x] == 1) {
				    float x2 = worldTransform_[y][x].translation_.x ;
				    float y2 = worldTransform_[y][x].translation_.y ;
				    if (abs(x2 - px) < 2.0 && abs(y2 - py) < 2.0) {
					    return true;
				    }
			    }
		    }
	    }
	    return false;
}

bool GameMap::NoBlock(float px, float py) {
	for (int y = 0; y < mapY; y++) {
		for (int x = 0; x < mapX; x++) {
			if (mapData[y][x] == 2) {
				float x2 = worldTransform_[y][x].translation_.x;
				float y2 = worldTransform_[y][x].translation_.y;
				if (abs(x2 - px) < 2.0 && abs(y2 - py) < 2.0) {
					return true;
				}
			}
		}
	}
	return false;
}

bool GameMap::ScoreBlock(float px, float py) {
	for (int y = 0; y < mapY; y++) {
		for (int x = 0; x < mapX; x++) {
			if (mapData[y][x] == 3) {
				float x2 = worldTransform_[y][x].translation_.x;
				float y2 = worldTransform_[y][x].translation_.y;
				if (abs(x2 - px) < 2.0 && abs(y2 - py) < 2.0) {
					return true;
				}
			}
		}
	}
	return false;
}

bool GameMap::VeryScoreBlock(float px, float py) {
	for (int y = 0; y < mapY; y++) {
		for (int x = 0; x < mapX; x++) {
			if (mapData[y][x] == 4) {
				float x2 = worldTransform_[y][x].translation_.x;
				float y2 = worldTransform_[y][x].translation_.y;
				if (abs(x2 - px) < 2.0 && abs(y2 - py) < 2.0) {
					return true;
				}
			}
		}
	}
	return false;
}

bool GameMap::CheckBreak(float px, float py) {
	for (int y = 0; y < mapY; y++) {
		for (int x = 0; x < mapX; x++) {
			if (mapData[y][x] == 1) {
				float x2 = worldTransform_[y][x].translation_.x ;
				float y2 = worldTransform_[y][x].translation_.y ;
				if (abs(x2 - px) < 2.0 && abs(y2 - py) < 2.0) {
					mapData[y][x] = 0;
				}
			}
		}
	}
	return false;
}

bool GameMap::ScoreBreak(float px, float py) {
	for (int y = 0; y < mapY; y++) {
		for (int x = 0; x < mapX; x++) {
			if (mapData[y][x] == 3) {
				float x2 = worldTransform_[y][x].translation_.x;
				float y2 = worldTransform_[y][x].translation_.y;
				if (abs(x2 - px) < 2.0 && abs(y2 - py) < 2.0) {
					mapData[y][x] = 0;
				}
			}
		}
	}
	return false;
}

bool GameMap::VeryScoreBreak(float px, float py) {
	for (int y = 0; y < mapY; y++) {
		for (int x = 0; x < mapX; x++) {
			if (mapData[y][x] == 4) {
				float x2 = worldTransform_[y][x].translation_.x;
				float y2 = worldTransform_[y][x].translation_.y;
				if (abs(x2 - px) < 2.0 && abs(y2 - py) < 2.0) {
					mapData[y][x] = 0;
				}
			}
		}
	}
	return false;
}

