#pragma once
#include "GAME_OBJECT.h"
#include "VECTOR2.h"
#include "PLAYER_BULLETS.h"
class ITEM :
    public GAME_OBJECT
{
public:
	struct  DATA
	{
		int img = 0;			//画像のハンドル
		double exRate = 0;		//画像の拡大率
		double angle = 0;		//画像の角度
		VECTOR2 pos = 0;		//座標
		float fallSpeed = 0;	//落下速度
		int limitW = 0;			//x座標の移動範囲制限
		//当たり判定
		bool active = 0;		//ITEMが有効かどうかを表す
		float bcRadius = 0;		//当たり判定の円の半径
	};
private:
	DATA Item;

public:
    ITEM(GAME* game);
    ~ITEM();
	void create();
	void init();
	void update();
		void move();
		void collision();
	void draw();
};