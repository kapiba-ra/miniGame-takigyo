#pragma once
#include "VECTOR2.h"
#include "DxLib.h"

//�ŏI�I�ɐ��𕡐��`�悵�ďォ�牺�ɗ����A��̗���̂悤�ɕ\������B
//�����͐���{��{�ɂ��ẴN���X�B

class WATER_FALL
{
private:
	float Len;					//���̒���
	float SWeight = 0;			//Stroke Weight�@���̑����E�֊s
	VECTOR2 StartPos, EndPos;	//���̗��[
	VECTOR2 Vec;				//1�t���[���Ői��x,y���W��\��
	float Speed = 0;			//����������X�s�[�h		
	int Color;					//���̐F
public:
	WATER_FALL();
	~WATER_FALL();
	void init();
	void perform();				//WATER_FALL_ART�N���X�Ő��̐������Ăяo�����B
};
