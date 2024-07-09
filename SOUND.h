#pragma once
#include "DxLib.h"
 
class SOUND
{
private:
	int pBulletSE = 0;			//playerの弾のse
	int upBulletSE = 0;			//PowerUp後のplayerの弾のse
public:
	SOUND();
	~SOUND();
	void loadPlayerSound();		//SOUNDの設定(player)
	//各SEのゲッター関数
	int pBulletSEget() { return pBulletSE; }
	int upBulletSEget() { return upBulletSE; }
};