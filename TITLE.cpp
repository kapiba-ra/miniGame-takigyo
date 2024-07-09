#include "DxLib.h"
#include "CONTAINER.h"
#include "GAME.h"
#include "TITLE.h"

TITLE::TITLE(class GAME* game) :
	SCENE(game) {
}
TITLE::~TITLE() {
}

void TITLE::init() {
	Title = game()->container()->titleData();
}

void TITLE::draw() {
	ClearDrawScreen();
	DrawRotaGraphF(100,200,6,0.1,game()->container()->playerData().img, TRUE);
	DrawStringFToHandle(Title.pos.x, Title.pos.y-300, Title.titleName,
		Title.textColor, Title.titleNameFont);		//タイトル名の表示
	Title.countTime++;		//１フレームで+１
	if (Title.countTime <=30) {
		DrawStringFToHandle(Title.pos.x, Title.pos.y, Title.start,
			Title.textColor, Title.startFont);		//"ZでStartを表示"
	}
	else if (Title.countTime >= 60)Title.countTime = 0;
	ScreenFlip();
}

void TITLE::nextScene() {
	if (CheckHitKey(KEY_INPUT_Z) && !ChangeStopFlag) {
		//STAGE_IDはGAMEクラスのpublicな定数→GAME::STAGE_IDで呼び出せる
		game()->changeScene(GAME::STAGE_ID);
		ChangeStopFlag = true;	
		SetBackgroundColor(50, 50, 150, 128);	//次のSTAGEの背景を設定
	}
	else if (!CheckHitKey(KEY_INPUT_Z)) {
		ChangeStopFlag = false;
	}
}