#pragma once
#include "DxLib.h"
 
class SOUND
{
private:
	int pBulletSE = 0;			//player�̒e��se
	int upBulletSE = 0;			//PowerUp���player�̒e��se
public:
	SOUND();
	~SOUND();
	void loadPlayerSound();		//SOUND�̐ݒ�(player)
	//�eSE�̃Q�b�^�[�֐�
	int pBulletSEget() { return pBulletSE; }
	int upBulletSEget() { return upBulletSE; }
};