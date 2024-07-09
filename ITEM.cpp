#include "CONTAINER.h"
#include "GAME.h"
#include "ITEM.h"

ITEM::ITEM(GAME* game) :
	GAME_OBJECT(game){
}
ITEM::~ITEM(){
}

void ITEM::create(){
	Item = game()->container()->itemData();
}

void ITEM::init(){
	//x座標はPLAYERの移動範囲より少し小さい範囲でランダムに設定
	Item.pos.x = static_cast<float>(Item.limitW) + rand() % (game()->container()->SCREEN_WIDTH - 2 * Item.limitW);
	Item.pos.y = game()->container()->itemData().pos.y;
	Item.active = game()->container()->itemData().active;
}

void ITEM::update(){
	//Itemが有効の時に関数を呼び出す
	if (Item.active) {
		move();
		collision();
	}
}

void ITEM::move(){
	Item.pos.y += Item.fallSpeed;	//ITEMを一定速度で落とす
	if (Item.pos.y >= game()->container()->SCREEN_HEIGHT) {
		Item.active = false;		//画面外へ行ったらITEMを無効に
	}
}

void ITEM::collision(){
	//sqDistance(square distance)は、当たり判定を行う最長距離の二乗
	float distance = game()->container()->playerData().bcRadius + Item.bcRadius;
	float sqDistance = distance * distance;
	//ITEMからPLAYERへの距離
	VECTOR2 vec = game()->playerInst()->pos() - Item.pos;
	//(ITEMからPLAYERへの距離の２乗)<=(当たり判定を行う最長距離の２乗)→ITEMを無効に
	if (sqLength(vec)<=sqDistance && Item.active){
		Item.active = false;
		game()->playerBulletsInst()->powerUpBullets();		//弾を強くする
		game()->playerInst()->itemHit();					//PLAYERの通常時画像を変える
	}
}

void ITEM::draw() {
	//Itemが有効の時に関数を呼び出す
	if (Item.active) {
	DrawRotaGraphF(Item.pos.x, Item.pos.y, Item.exRate, Item.angle, Item.img, TRUE);
	}
}
