#include "BULLETS.h"
#include "CONTAINER.h"
BULLETS::BULLETS(class GAME* game) :
	GAME_OBJECT(game)
	//,Bullets(0)
{
	screenWidth = this->game()->container()->getScreenWidth();
	screenHeight = this->game()->container()->getScreenWidth();
}
BULLETS::~BULLETS(){
	//delete[] Bullets;
}

void BULLETS::SetBullets(const BULLETS::DATA& data){
	Bullet = data;
	//Bullets = new BULLET[Bullet.totalNum];		//弾の最大数分ポインタ配列を作る
}

void BULLETS::init(){
	Bullet.curNum = 0;
}

void BULLETS::launch(const VECTOR2& pos, const VECTOR2& vec) {
	//現在の弾の数が最大数を超えていないときに処理
	if (Bullet.curNum < Bullet.totalNum) {
		//発射するとBullets[0]から順に位置と発射方向が設定される。
		BULLET* newBullet = Bullets.Alloc(); // PoolAllocatorから新しい弾を確保
		if (newBullet) {
			newBullet->pos = pos;
			newBullet->vec = vec;
			Bullet.curNum++;
		}
	}
}

void BULLETS::update() {
    BULLET* current = &Bullets[0];  // PoolAllocatorの先頭から開始
    for (int i = 0; i < Bullet.curNum; i++) {
        if (current) {
            current->pos += current->vec * Bullet.advSpeed;  // 弾の位置を更新
            Bullet.angle += Bullet.angSpeed;                // 弾を回転させる

            // 画面外に出たときに消えるように処理
            if (current->pos.y < Bullet.bcRadius ||
                current->pos.y > screenHeight + Bullet.bcRadius ||
                current->pos.x < -Bullet.bcRadius ||
                current->pos.x > screenWidth + Bullet.bcRadius) {
                kill(i);  // 弾を削除
            }
            current++; // 次の弾へ
        }
    }
}

void BULLETS::kill(int i) {
    BULLET* lastBullet = &Bullets[Bullet.curNum - 1];  // 最後の弾
    BULLET* bulletToKill = &Bullets[i];                // 削除対象の弾

    if (bulletToKill && lastBullet) {
        *bulletToKill = *lastBullet;  // 削除対象の弾に最後の弾を上書き
        Bullets.Free(lastBullet);     // PoolAllocatorから解放
        Bullet.curNum--;              // 現在の弾の数を減らす
    }
}

void BULLETS::draw() {
    BULLET* current = &Bullets[0];  // PoolAllocatorの先頭から開始
    for (int i = 0; i < Bullet.curNum; i++) {
        if (current) {
            DrawRotaGraphF(current->pos.x, current->pos.y, Bullet.exRate,
                Bullet.angle, Bullet.img, TRUE);
            current++;  // 次の弾へ
        }
    }
}
