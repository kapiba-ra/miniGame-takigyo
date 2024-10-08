#include "CONTAINER.h"
#include "GAME.h"
#include "PLAYER_BULLETS.h"
#include "ENEMY_BULLETS.h"
#include "BOSS_BULLETS.h"
#include "PLAYER.h"

PLAYER::PLAYER(GAME* game):
	GAME_OBJECT(game){
}
PLAYER::~PLAYER(){
}

void PLAYER::create() {
	Player = game()->container()->playerData();
	screenWidth = game()->container()->getScreenWidth();
	
}

void PLAYER::init(){
	//再開時に初期化すべきものについてはCONTAINERのデータで初期化
	Player.pos = game()->container()->playerData().pos;
	Player.hp = game()->container()->playerData().hp;
	Player.img = game()->container()->playerData().img;
	Player.bulletSE = game()->container()->playerData().bulletSE;
	Player.exRate = game()->container()->playerData().exRate;
	Player.invincibleRestTime = game()->container()->playerData().invincibleRestTime;	
}

void PLAYER::update() {
	move();
	launch();
	collision();
}

void PLAYER::move(){
	if (Player.pos.x > Player.limitW && CheckHitKey(KEY_INPUT_A)) {
		Player.pos.x += -Player.advSpeed;
	}
	if (Player.pos.x < screenWidth - Player.limitW && CheckHitKey(KEY_INPUT_D)) {
		Player.pos.x += Player.advSpeed;
	}
}
void PLAYER::launch() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		Player.triggerErapsedTime += 1;		//１フレーム毎に1加算
		//発射間隔を経過時間が超えたときに処理
		if (Player.triggerErapsedTime >= Player.triggerInterval) {
			//発射位置posの設定(PLAYERの中心より少し上の座標)
			VECTOR2 pos = Player.pos + Player.launchVec * Player.ofstLaunchDist;
			game()->playerBulletsInst()->launch(pos, Player.launchVec);		//発射位置、方向を渡す
			Player.triggerErapsedTime = 0;
			//発射音を鳴らす
			PlaySoundMem(Player.bulletSE, DX_PLAYTYPE_BACK);
		}
	}
	else {
		//スペースキーを放すと次に押した瞬間にすぐ弾が出るようにする。
		Player.triggerErapsedTime = Player.triggerInterval; 
	}
}

void PLAYER::collision() {					//画像の切り替え以外は敵の当たり判定と似ている
	if (Player.invincibleRestTime > 0) {
		Player.invincibleRestTime -= 1.0f;
		Player.graphic = Player.hitImg;		//無敵時間中はhit状態の画像
	}
	else{
		//BOSSが攻撃し始めると、BOSSの弾についての当たり判定を行う。
		BULLETS* bullets;
		if (game()->enemiesInst()->curNum() >= 1) { bullets = game()->enemyBulletsInst(); }
		else { bullets = game()->bossBulletsInst(); }
		// 無敵時間でないときは通常時の画像
		Player.graphic = Player.img;
		// プレイヤーの当たり判定用の円を上と下に二つ用意する
		VECTOR2 circle1Pos = Player.pos - VECTOR2(0, Player.bcRadius);		// 上の円の中心
		VECTOR2 circle2Pos = Player.pos + VECTOR2(0, Player.bcRadius);		// 下の円の中心
		// 当たり判定の最大距離と、その2乗を計算
		float distance = Player.bcRadius + bullets->bcRadius();
		float sqDistance = distance * distance;
		for (int i = bullets->curNum() - 1; i >= 0; i--) {
			VECTOR2 bulletPos = bullets->pos(i);
			VECTOR2 vec1 = circle1Pos - bulletPos;
			VECTOR2 vec2 = circle2Pos - bulletPos;
			//二つの円のきょりについてそれぞれ条件を設定する
			if (sqLength(vec1) < sqDistance || sqLength(vec2) < sqDistance) {
				Player.hp -= bullets->damage();
				Player.invincibleRestTime = Player.invincibleTime;
				bullets->kill(i);
				i = 0;  // 当たったらループを抜ける
			}
		}
	}
}

void PLAYER::zoom(){
	if (Player.graphic != Player.awakenImg && Player.hp > 0) {
		Player.graphic = Player.awakenImg;		//強制的にPLAYERを覚醒状態の画像に
	}
	else if(Player.graphic != Player.hitImg && Player.hp <= 0){
		Player.graphic = Player.hitImg;		//強制的にPLAYERを被弾時の画像に
	}
	if (Player.exRate < 6.0) {
		Player.exRate += 0.1f;		//画像の拡大(制限付き)
	}
}

void PLAYER::draw(){
	game()->hpGaugeInst()->draw(Player.pos, Player.hpGaugeOfst, Player.hp);
	DrawRotaGraphF(Player.pos.x, Player.pos.y, Player.exRate, Player.angle, Player.graphic, TRUE);
}

void PLAYER::itemHit(){
	//通常時画像をITEM獲得時の画像に差し替える
	Player.img = Player.awakenImg;
	//Item取得状態のSEに切り替える
	Player.bulletSE = game()->container()->playerBulletData().sound.upBulletSEget();
}
