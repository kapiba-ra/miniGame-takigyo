#include "DxLib.h"
#include "GAME.h"
#include "CONTAINER.h"
#include "PLAYER_BULLETS.h" 
#include "ENEMY_BULLETS.h" 
#include "BOSS_BULLETS.h" 
#include "GAME_CLEAR.h"

GAME_CLEAR::GAME_CLEAR(class GAME* game) :
	SCENE(game) {
}
GAME_CLEAR::~GAME_CLEAR() {
}

void GAME_CLEAR::init(){
	GameClear = game()->container()->gameClearData();
}

void GAME_CLEAR::update() {
	//弾が突然消えないように描画は続ける
	game()->playerBulletsInst()->update();
	game()->enemyBulletsInst()->update();
	game()->bossBulletsInst()->update();
	game()->bossInst()->rotate();		//BOSSを回転させる
	game()->playerInst()->zoom();		//PLAYERを拡大させる
}

void GAME_CLEAR::draw() {
	ClearDrawScreen();
	game()->draw();
	//メッセージの表示
	DrawStringFToHandle(GameClear.pos.x, GameClear.pos.y, GameClear.endMessage,
		GameClear.textColor, GameClear.messageFont);
	DrawStringFToHandle(GameClear.pos.x, GameClear.pos.y + GameClear.textSize, GameClear.toTitleMessage,
		GameClear.textColor, GameClear.messageFont);
	ScreenFlip();
}
void GAME_CLEAR::nextScene() {
	if (CheckHitKey(KEY_INPUT_Z) && !ChangeStopFlag) {
		SetBackgroundColor(100, 150, 200, 128);		//TITLEの背景色
		game()->changeScene(GAME::TITLE_ID);
		ChangeStopFlag = true;
	}
	else if (!CheckHitKey(KEY_INPUT_Z)) {
		ChangeStopFlag = false;
	}
}