#include "BOSS.h"
#include "CONTAINER.h"
#include "GAME.h"
#include "BOSS_BULLETS.h"

BOSS::BOSS(GAME* game) : 
	GAME_OBJECT(game){
}
BOSS::~BOSS(){
}

void BOSS::create(){
	Boss = game()->container()->bossData();
}

void BOSS::init(){
	Boss.hp = game()->container()->bossData().hp;
	Boss.pos = game()->container()->bossData().pos;
	Boss.angle = game()->container()->bossData().angle;
}

void BOSS::update(){
	//ENEMYの数が0になったら呼び出す
	if (game()->enemiesInst()->curNum() <= 0) {
		move();
		collision();
		//弾の発射はtargetPosYに到達してから始める
		if (Boss.pos.y >= Boss.targetPosY) {
			launch();
		}
	}
}

void BOSS::move() {
	//targetPosYまでy座標を降ろす
	if (Boss.pos.y <= Boss.targetPosY) {
		Boss.pos.y += Boss.ySpeed;
		Boss.invincibleRestTime = Boss.invincibleTime;
	}
	else {
		// y座標がtargetPosYに達した場合、画面を横に行き来するように
		if (Boss.pos.x >= CONTAINER::SCREEN_WIDTH || Boss.pos.x <= 0) {
			Boss.xSpeed = -Boss.xSpeed; // 移動方向を反転
		}
		Boss.pos.x += Boss.xSpeed;
	}
}

void BOSS::collision(){
	PLAYER_BULLETS* bullets = game()->playerBulletsInst();		//PLAYERの弾のポインタ
	float distance = Boss.bcRadius + bullets->bcRadius();		//PLAYERの弾とBOSSの当たり判定最大距離
	float sqDistance = distance * distance;						//↑の２乗
	//無敵時間の時の処理
	if (Boss.invincibleRestTime > 0) {
		Boss.invincibleRestTime -= 1.0f;
	}
	//無敵じゃない時の処理
	else {
		//画面上のPLAYERの弾の数だけ当たり判定を計算
		for (int i = bullets->curNum() - 1; i >= 0; i--) {
			VECTOR2 vec = Boss.pos - bullets->pos(i);		//BOSSとPLAYERの弾の距離
			if (sqLength(vec) < sqDistance) {				//(↑の２乗)< (当たり判定最大距離の２乗)
				Boss.hp -= game()->container()->playerBulletData().damage;
				Boss.invincibleRestTime = Boss.invincibleTime;
				bullets->kill(i);		//当たった弾を削除(上記のものと似た上書き処理をしている)
				i = 0;					//ループを抜ける
			}
		}
	}
}

void BOSS::launch(){
	VECTOR2 playerPos = game()->playerInst()->pos();
	Boss.triggerErapsedTime += 1.0f;
	//経過時間が発射までのインターバルを超えたときの処理
	if (Boss.triggerErapsedTime >= Boss.triggerInterval) {
		//発射方向の設定
		VECTOR2 launchVec = normalize(playerPos - Boss.pos);
		//発射位置の設定
		VECTOR2 pos = Boss.pos + launchVec * Boss.ofstLaunchDist;
		game()->bossBulletsInst()->launch(pos, launchVec);		//発射位置、方向を渡す
		Boss.triggerErapsedTime = 0;
	}
}

void BOSS::rotate() {
	Boss.angle += 0.05f;
}

void BOSS::draw(){
	if (game()->enemiesInst()->curNum() <= 0) {
		DrawRotaGraphF(Boss.pos.x, Boss.pos.y, Boss.exRate, Boss.angle, Boss.img, TRUE);
		game()->hpGaugeInst()->draw(Boss.pos, Boss.hpGaugeOfst, Boss.hp);
	}
}
