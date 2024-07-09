#include "CONTAINER.h"
#include "GAME.h"
#include "ENEMY_BULLETS.h"
#include "PLAYER_BULLETS.h"
#include "HP_GAUGE.h"
#include "ENEMIES.h"
#include <cmath>
//πを定義
#define pi 3.141592f

ENEMIES::ENEMIES(GAME* game):
	GAME_OBJECT(game),Enemies(0){
}
ENEMIES::~ENEMIES(){
	delete[] Enemies;
}

void ENEMIES::create(){
	Enemy = game()->container()->enemyData();
	Enemies = new ENEMY[Enemy.totalNum];		//最大数だけポインタ配列を作る
}

void ENEMIES::init(){
	Enemy.centerPos = game()->container()->enemyData().centerPos;
	//敵の位置がdivThetaだけ均等に中心座標からずれて描画される為の設定
	float divTheta = pi * 2 / Enemy.totalNum;		
	//弾の発射間隔を敵ごとにずらす為にその間隔を設定
	float divInterval = Enemy.triggerInterval /Enemy.totalNum;

	for (int i = 0; i < Enemy.totalNum; i++) {
		Enemies[i].ofstTheta = divTheta * i;				//描画位置の中心からの角度
		Enemies[i].triggerErapsedTime = divInterval * i;	//弾の発射間隔までの経過時間
		Enemies[i].invincibleRestTime = 0;
		Enemies[i].hp = Enemy.initHp;
	}
	Enemy.curNum = Enemy.totalNum;		//敵の復活
}

void ENEMIES::update() {
	move();
	collision();
	launch();
}

void ENEMIES::move(){
	//targetPosYまで中心座標を降ろす
	if (Enemy.centerPos.y < Enemy.targetPosY) {
		Enemy.centerPos.y += Enemy.fallSpeed;
	}
	//現在の敵の数だけループさせる
	for (int i = 0; i < Enemy.curNum; i++) {
		float theta = Enemy.refTheta + Enemies[i].ofstTheta;
		//楕円の周上の座標をpx,pyで決定し、それぞれの敵の座標に
		float px = Enemy.centerPos.x + cosf(theta) * Enemy.majRadius;
		float py = Enemy.centerPos.y + sinf(theta) * Enemy.minRadius;
		Enemies[i].pos.x = px;
		Enemies[i].pos.y = py;
		if (theta > 2 * pi)theta -= 2 * pi;		//thetaが際限なく増えないように
	}
	Enemy.refTheta += Enemy.thetaSpeed;				//少しずつ座標をずらす
}

void ENEMIES::collision() {
	PLAYER_BULLETS* bullets = game()->playerBulletsInst();		//PLAYERの弾のポインタを用意(読みやすい)
	float distance = Enemy.bcRadius + bullets->bcRadius();		//PLAYERの弾とENEMYの距離
	float sqDistance = distance * distance;		//絶対値ではなく距離の二乗を使う(計算量の削減)
	//敵の数だけ処理する(配列なので後ろからループして削除時の処理を簡単にする)
	for (int j = Enemy.curNum - 1; j >= 0; j--) {
		//無敵時間を減らす処理
		if (Enemies[j].invincibleRestTime > 0) {
			Enemies[j].invincibleRestTime -= 1.0f;
		}
		//無敵じゃない時の処理
		else {
			//画面上のPLAYERの弾の数だけ当たり判定を計算
			for (int i = bullets->curNum() - 1; i >= 0; i--) {
				VECTOR2 vec = Enemies[j].pos - bullets->pos(i);
				//sqLength(vec)でベクトルの大きさの二乗を計算
				if (sqLength(vec) < sqDistance) {
					Enemies[j].hp-=game()->container()->playerBulletData().damage;
					Enemies[j].invincibleRestTime = Enemy.invincibleTime;
					//ある個体Enemies[j]のhp0になったとき現在の敵の数を減少
					if (Enemies[j].hp <= 0) {
						Enemy.curNum--;
						//hpが0になったらその敵の配列をEnemies[curNum]の情報で上書きする。
						//curNumが減ることにより次のループで消えるEnemies[Enemy.curNum]を保存しつつ、
						//hpがゼロになった配列の情報を消すことができる。
						Enemies[j] = Enemies[Enemy.curNum];
					}
					bullets->kill(i);		//当たった弾を削除(上記のものと似た上書き処理をしている)
					i = 0;					//ループを抜ける
				}
			}
		}
	}
}

void ENEMIES::launch() {
	VECTOR2 playerPos = game()->playerInst()->pos();
	//敵の数だけループ
	for (int i = 0; i < Enemy.curNum; i++) {
		Enemies[i].triggerErapsedTime += 1.0f;
		//経過時間が発射までのインターバルを超えたときの処理
		if (Enemies[i].triggerErapsedTime >= Enemy.triggerInterval) {
			//発射方向の設定(normalizeはベクトルの正規化)
			VECTOR2 launchVec = normalize(playerPos - Enemies[i].pos);
			//発射位置の設定(ofstLaunchDistで敵の真ん中より少し下になるよう調整)
			VECTOR2 pos = Enemies[i].pos + launchVec * Enemy.ofstLaunchDist;
			game()->enemyBulletsInst()->launch(pos, launchVec);		//発射位置、方向を渡す
			Enemies[i].triggerErapsedTime = 0;
		}
	}
}

void ENEMIES::draw(){
	for (int i = 0; i < Enemy.curNum; i++) {
		DrawRotaGraphF(Enemies[i].pos.x, Enemies[i].pos.y,Enemy.exRate, Enemy.angle, Enemy.img, TRUE);
		game()->hpGaugeInst()->draw(Enemies[i].pos, Enemy.hpGaugeOfst, Enemies[i].hp);
	}
}
