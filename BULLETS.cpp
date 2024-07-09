#include "BULLETS.h"
#include "CONTAINER.h"
BULLETS::BULLETS(class GAME* game) :
	GAME_OBJECT(game), Bullets(0){
	screenWidth = this->game()->container()->getScreenWidth();
	screenHeight = this->game()->container()->getScreenWidth();
}
BULLETS::~BULLETS(){
	delete[] Bullets;
}

void BULLETS::SetBullets(const BULLETS::DATA& data){
	Bullet = data;
	Bullets = new BULLET[Bullet.totalNum];		//弾の最大数分ポインタ配列を作る
}

void BULLETS::init(){
	Bullet.curNum = 0;
}

void BULLETS::launch(const VECTOR2& pos, const VECTOR2& vec) {
	//現在の弾の数が最大数を超えていないときに処理
	if (Bullet.curNum < Bullet.totalNum) {
		//発射するとBullets[0]から順に位置と発射方向が設定される。
		int i = Bullet.curNum;
		Bullets[i].pos = pos;
		Bullets[i].vec = vec;
		Bullet.curNum++;
	}
}

void BULLETS::update(){
	//弾の位置の更新(配列削除時の手間を考えループは後ろから)
	for (int i = Bullet.curNum - 1; i >= 0; i--) {
		Bullets[i].pos += Bullets[i].vec * Bullet.advSpeed;		//1フレームでadvSpeedドットの距離を進む
		Bullet.angle += Bullet.angSpeed;						//弾を回転させる
		//画面外に出たときに消えるように処理
		if (Bullets[i].pos.y < Bullet.bcRadius ||
			Bullets[i].pos.y>screenHeight + Bullet.bcRadius ||
			Bullets[i].pos.x < -Bullet.bcRadius ||
			Bullets[i].pos.x>screenWidth + Bullet.bcRadius) {
			kill(i);
		}
	}
}

void BULLETS::kill(int i) {
	Bullet.curNum--;							//現在の弾の数を減らす
	Bullets[i] = Bullets[Bullet.curNum];		//当たった弾に配列の最後の弾の情報を上書き
}

void BULLETS::draw(){
	for (int i = 0; i < Bullet.curNum; i++) {
		DrawRotaGraphF(Bullets[i].pos.x, Bullets[i].pos.y, Bullet.exRate,
			Bullet.angle, Bullet.img, TRUE);
	}
}