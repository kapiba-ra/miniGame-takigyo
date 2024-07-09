#include "DxLib.h"
#include "GAME.h"
#include "CONTAINER.h"
#include "STAGE.h"
#include "PLAYER.h"
#include "PLAYER_BULLETS.h"
#include "ENEMIES.h"
#include "ENEMY_BULLETS.h"
#include "BOSS.h"
#include "BOSS_BULLETS.h"
#include "ITEM.h"

STAGE::STAGE(class GAME* game) :
	SCENE(game) {
}
STAGE::~STAGE() {
}

void STAGE::init() {
	//ŠeƒNƒ‰ƒX‚Ì‰Šú‰»ŠÖ”‚ğŒÄ‚Ño‚·
	game()->playerBulletsInst()->init();
	game()->playerInst()->init();
	game()->enemyBulletsInst()->init();
	game()->enemiesInst()->init();
	game()->bossBulletsInst()->init();
	game()->bossInst()->init();
	game()->itemInst()->init();
	//•¶š‚Ìİ’è
	Stage = game()->container()->stageData();
}

void STAGE::update() {
	game()->playerBulletsInst()->update();
	game()->playerInst()->update();
	game()->bossBulletsInst()->update();
	game()->bossInst()->update();
	game()->enemyBulletsInst()->update();
	game()->enemiesInst()->update();
	game()->itemInst()->update();
}

void STAGE::nextScene() {
	if (game()->bossInst()->hp()<=0) {
		game()->changeScene(GAME::GAME_CLEAR_ID);
		ChangeStopFlag = true;
		game()->playerBulletsInst()->powerDownBullets();	//PLAYER‚Ì’e‚ğ’Êí‚Éİ’è
		SetBackgroundColor(50, 100, 50, 128);	//‚ ‚Æ‚Å‚©‚¦‚é
	}
	else if (!CheckHitKey(KEY_INPUT_Z)) {
		ChangeStopFlag = false;
	}
	if (game()->playerInst()->hp()<=0) {
		game()->changeScene(GAME::GAME_OVER_ID);
		ChangeStopFlag = true;
		game()->playerBulletsInst()->powerDownBullets();	//PLAYER‚Ì’e‚ğ’Êí‚Éİ’è
		SetBackgroundColor(50, 100, 50, 128);
	}
}

void STAGE::draw() {
	ClearDrawScreen();
	WaterFallArt.perform();		//”wŒi‚Ìü‚ğ•`‰æBDXƒ‰ƒCƒuƒ‰ƒŠ‚Ìd—lãA”wŒi‚©‚ç•`Ê‚µ‚Ä
	game()->draw();				//‚»‚Ì‘¼‚Ì•¨‘Ì‚ğ•`‰æ‚·‚é–‚É‚æ‚Á‚ÄƒŒƒCƒ„[‚ğİ’è‚·‚é
	DrawStringFToHandle(Stage.pos.x, Stage.pos.y, Stage.moveMessage,
		Stage.textColor, Stage.messageFont);
	DrawStringFToHandle(Stage.pos.x, Stage.pos.y + Stage.textSize, Stage.shotMessage,
		Stage.textColor, Stage.messageFont);
	ScreenFlip();
}