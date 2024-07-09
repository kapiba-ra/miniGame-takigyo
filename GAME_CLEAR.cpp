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
	//�e���ˑR�����Ȃ��悤�ɕ`��͑�����
	game()->playerBulletsInst()->update();
	game()->enemyBulletsInst()->update();
	game()->bossBulletsInst()->update();
	game()->bossInst()->rotate();		//BOSS����]������
	game()->playerInst()->zoom();		//PLAYER���g�傳����
}

void GAME_CLEAR::draw() {
	ClearDrawScreen();
	game()->draw();
	//���b�Z�[�W�̕\��
	DrawStringFToHandle(GameClear.pos.x, GameClear.pos.y, GameClear.endMessage,
		GameClear.textColor, GameClear.messageFont);
	DrawStringFToHandle(GameClear.pos.x, GameClear.pos.y + GameClear.textSize, GameClear.toTitleMessage,
		GameClear.textColor, GameClear.messageFont);
	ScreenFlip();
}
void GAME_CLEAR::nextScene() {
	if (CheckHitKey(KEY_INPUT_Z) && !ChangeStopFlag) {
		SetBackgroundColor(100, 150, 200, 128);		//TITLE�̔w�i�F
		game()->changeScene(GAME::TITLE_ID);
		ChangeStopFlag = true;
	}
	else if (!CheckHitKey(KEY_INPUT_Z)) {
		ChangeStopFlag = false;
	}
}