#pragma once
#include "VECTOR2.h"
#include "DxLib.h"

//最終的に線を複数描画して上から下に流し、滝の流れのように表現する。
//ここは線一本一本についてのクラス。

class WATER_FALL
{
private:
	float Len;					//線の長さ
	float SWeight = 0;			//Stroke Weight　線の太さ・輪郭
	VECTOR2 StartPos, EndPos;	//線の両端
	VECTOR2 Vec;				//1フレームで進むx,y座標を表す
	float Speed = 0;			//線が落ちるスピード		
	int Color;					//線の色
public:
	WATER_FALL();
	~WATER_FALL();
	void init();
	void perform();				//WATER_FALL_ARTクラスで線の数だけ呼び出される。
};
