#pragma once
class GAME
{
public:
	GAME();
	~GAME();
	void run();
//CONTAINERのデータへのアクセス用
private:	
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }
//SCENE 定数で0から順に与えられる。
public:
	enum SCENE_ID {
		TITLE_ID,
		STAGE_ID,
		GAME_CLEAR_ID,
		GAME_OVER_ID,
		NUM_SCENES		//4でちょうど場面の総数になる。
	};
	void changeScene(SCENE_ID sceneId);
private:
	class SCENE* Scenes[NUM_SCENES];	//基底クラス「SCENE」の４つのポインタが用意される。
	SCENE_ID CurSceneId;	//Current SceneId
//キャラクタ
private:	//各クラスのポインタを設定
	class PLAYER* Player;
	class ENEMIES* Enemies;
	class BOSS* Boss;
	class PLAYER_BULLETS* PlayerBullets;
	class ENEMY_BULLETS* EnemyBullets;
	class BOSS_BULLETS* BossBullets;
	class HP_GAUGE* HpGauge;
	class ITEM* Item;
public:		//各クラスのポインタのゲッター関数。InstはInstanceとしてplayerData()等と区別
	class PLAYER* playerInst() { return Player; };
	class ENEMIES* enemiesInst() { return Enemies; }
	class BOSS* bossInst() { return Boss; }
	class PLAYER_BULLETS* playerBulletsInst(){ return PlayerBullets; }
	class ENEMY_BULLETS* enemyBulletsInst(){ return EnemyBullets; }
	class BOSS_BULLETS* bossBulletsInst(){ return BossBullets; }
	class HP_GAUGE* hpGaugeInst(){ return HpGauge; }
	class ITEM* itemInst(){ return Item; }
	void draw();
};