#include "DxLib.h"
#include "TITLE.h"
#include "STAGE.h"
#include "GAME_CLEAR.h"
#include "GAME_OVER.h"
#include "CONTAINER.h"
#include "PLAYER.h"
#include "ENEMIES.h"
#include "BOSS.h"
#include "PLAYER_BULLETS.h"
#include "ENEMY_BULLETS.h"
#include "BOSS_BULLETS.h"
#include "HP_GAUGE.h"
#include "GAME.h"

GAME::GAME(){
	Container = new CONTAINER;
	//引数としてGAMEクラスのインスタンス"game"のポインタを設定
	//gameポインタは最終的に、以下でインスタンス化されたクラスの基底クラス"GAME_OBJECT"へ渡される
	//したがって全ての派生クラスでGAMEクラスのメンバにアクセスできるようになる
	Scenes[TITLE_ID] = new TITLE(this);
	Scenes[STAGE_ID] = new STAGE(this);
	Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
	Scenes[GAME_OVER_ID] = new GAME_OVER(this);
	CurSceneId = TITLE_ID;
	//
	Player = new PLAYER(this);
	Enemies = new ENEMIES(this);
	Boss = new BOSS(this);
	PlayerBullets = new PLAYER_BULLETS(this);
	EnemyBullets = new ENEMY_BULLETS(this);
	BossBullets = new BOSS_BULLETS(this);
	HpGauge = new HP_GAUGE(this);
	Item = new ITEM(this);
}
GAME::~GAME(){
	delete Item;
	delete HpGauge;
	delete BossBullets;
	delete EnemyBullets;
	delete PlayerBullets;
	delete Boss;
	delete Enemies;
	delete Player;
	for (int i = 0; i < NUM_SCENES; i++) {
		delete Scenes[i];
	}
	delete Container;
}
//実質的なmain関数
void GAME::run(){	
	//裏画面処理など諸々の設定
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) { DxLib_End(); }
	SetDrawScreen(DX_SCREEN_BACK);
	SetBackgroundColor(100, 150, 200, 128);			//ここでTITLEの背景色を設定する
	//CONTAINERクラスにある各クラスのデータ構造体(小文字始まり)にデータを設定する。
	Container->load();
	//各クラスのデータ構造体(大文字始まり)に、load()で設定したデータを入れる。
	Player->create();
	Enemies->create();
	Boss->create();
	PlayerBullets->create();
	EnemyBullets->create();
	BossBullets->create();
	HpGauge->create();
	Item->create();
	//TITELのinit()が呼び出される
	Scenes[CurSceneId]->init();

	while ((ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)){
		//それぞれのupdate(),draw(),nextScene()が呼び出される
		Scenes[CurSceneId]->proc();
	}
	DxLib_End();
}

//シーンの切り替え
void GAME::changeScene(SCENE_ID sceneId) {
	CurSceneId = sceneId;
	Scenes[CurSceneId]->init();
}
//描画
void GAME::draw(){
	Player->draw();
	Enemies->draw();
	Boss->draw();
	PlayerBullets->draw();
	EnemyBullets->draw();
	BossBullets->draw();
	Item->draw();
}