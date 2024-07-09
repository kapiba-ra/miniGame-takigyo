#pragma once
#include "TITLE.h"
#include "STAGE.h"
#include "GAME_CLEAR.h"
#include "GAME_OVER.h"
#include "PLAYER.h"
#include "ENEMIES.h"
#include "BOSS.h"
#include "BULLETS.h"
#include "HP_GAUGE.h"
#include "ITEM.h"

//CONTAINERは各クラスに持たせるデータをまとめているクラス

class CONTAINER{
private:
	struct DATA {
		TITLE::DATA title;
		STAGE::DATA stage;
		GAME_CLEAR::DATA gameClear;
		GAME_OVER::DATA gameOver;
		PLAYER::DATA player;
		ENEMIES::DATA enemy;
		BOSS::DATA boss;
		BULLETS::DATA playerBullet;
		BULLETS::DATA enemyBullet;
		BULLETS::DATA bossBullet;
		HP_GAUGE::DATA hpGauge;
		ITEM::DATA item;
	};
	DATA Data;
//参照にすることで直接アクセスできる。
//Dataのデータは各クラスのprivateなDATAに代入される。
public:
	TITLE::DATA& titleData() { return Data.title; }
	STAGE::DATA& stageData() { return Data.stage; }
	GAME_CLEAR::DATA& gameClearData() { return Data.gameClear; }
	GAME_OVER::DATA& gameOverData() { return Data.gameOver; }
	PLAYER::DATA& playerData() { return Data.player; }
	ENEMIES::DATA& enemyData() { return Data.enemy; }
	BOSS::DATA& bossData() { return Data.boss; }
	BULLETS::DATA& playerBulletData() { return Data.playerBullet; }
	BULLETS::DATA& enemyBulletData() { return Data.enemyBullet; }
	BULLETS::DATA& bossBulletData() { return Data.bossBullet; }
	HP_GAUGE::DATA& hpGaugeData() { return Data.hpGauge; }
	ITEM::DATA& itemData() { return Data.item; }
//データを読み込む関数
public:
	void load();				//下記の2つの関数を実行する。ゲームループに入る前に呼び出される
		void setData();			//データの設定
		void loadGraphic();		//画像をメモリへロード
//画面の幅と高さ
public:
	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;
	int getScreenWidth()const { return SCREEN_WIDTH; } //画面の横幅を返すゲッター関数
	int getScreenHeight() const { return SCREEN_HEIGHT; } //画面の縦幅を返すゲッター関数
};

