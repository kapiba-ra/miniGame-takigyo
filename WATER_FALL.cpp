#include "WATER_FALL.h"
#include <cmath>

constexpr float PI = 3.1415926f;		//constexprにしてコンパイル時に評価されるように

WATER_FALL::WATER_FALL(){
	init();
	Color = GetColor(100, 100, 200);
}

WATER_FALL::~WATER_FALL(){
}

void WATER_FALL::init()		//この部分は何回も呼び出すので、そのままコンストラクタには入れない
{
	Len = rand() % 1000 + 100.0f;			//"+100.0f"は最低の長さ(長さ0を防ぐ)
	SWeight = rand() % 2 + 3.0f;			//"+1.0f"は最低の太さ(太さ0を防ぐ)
	StartPos.x = rand() % 640 + 1.0f;		//始点のx座標,+1.0fでfloat型にする
	StartPos.y = (rand() % 200) * -1.0f;	//始点のy座標
	Speed = rand() % 5 + 5.0f;				
	float angle = rand() % 3 + 89.0f;		//89°から91°までの範囲でずらす
	Vec.x = cos(angle * PI / 180.0f);		//ラジアンへの変換
	Vec.y = sin(angle * PI / 180.0f);		
	EndPos = StartPos - Vec * Len;			//終点の位置
	Vec *= Speed;
}

void WATER_FALL::perform()		//毎回呼び出すものなので計算はできるだけ少なくしたい。
{
	//移動
	StartPos += Vec;
	EndPos += Vec;
	//画面外へ出たら初期化
	if (EndPos.y > 480)init();		
	//描画処理
	DrawLineAA(StartPos.x, StartPos.y, EndPos.x, EndPos.y,
		Color, SWeight);
}