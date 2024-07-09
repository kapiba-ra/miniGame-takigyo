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
	//’e‚ª“Ë‘RÁ‚¦‚È‚¢‚æ‚¤‚É•`‰æ‚Í‘±‚¯‚é
	game()->playerBulletsInst()->update();
	game()->enemyBulletsInst()->update();
	game()->bossBulletsInst()->update();
	game()->bossInst()->rotate();		//BOSS‚ð‰ñ“]‚³‚¹‚é
	game()->playerInst()->zoom();		//PLAYER‚ðŠg‘å‚³‚¹‚é
}

void GAME_CLEAR::draw() {
	ClearDrawScreen();
	game()->draw();
	//ƒƒbƒZ[ƒW‚Ì•\Ž¦
	DrawStringFToHandle(GameClear.pos.x, GameClear.pos.y, GameClear.endMessage,
		GameClear.textColor, GameClear.messageFont);
	DrawStringFToHandle(GameClear.pos.x, GameClear.pos.y + GameClear.textSize, GameClear.toTitleMessage,
		GameClear.textColor, GameClear.messageFont);
	ScreenFlip();
}
void GAME_CLEAR::nextScene() {
	if (CheckHitKey(KEY_INPUT_Z) && !ChangeStopFlag) {
		SetBackgroundColor(100, 150, 200, 128);		//TITLE‚Ì”wŒiF
		game()->changeScene(GAME::TITLE_ID);
		ChangeStopFlag = true;
	}
	else if (!CheckHitKey(KEY_INPUT_Z)) {
		ChangeStopFlag = false;
	}
}