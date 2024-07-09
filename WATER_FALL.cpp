#include "WATER_FALL.h"
#include <cmath>

constexpr float PI = 3.1415926f;		//constexpr�ɂ��ăR���p�C�����ɕ]�������悤��

WATER_FALL::WATER_FALL(){
	init();
	Color = GetColor(100, 100, 200);
}

WATER_FALL::~WATER_FALL(){
}

void WATER_FALL::init()		//���̕����͉�����Ăяo���̂ŁA���̂܂܃R���X�g���N�^�ɂ͓���Ȃ�
{
	Len = rand() % 1000 + 100.0f;			//"+100.0f"�͍Œ�̒���(����0��h��)
	SWeight = rand() % 2 + 3.0f;			//"+1.0f"�͍Œ�̑���(����0��h��)
	StartPos.x = rand() % 640 + 1.0f;		//�n�_��x���W,+1.0f��float�^�ɂ���
	StartPos.y = (rand() % 200) * -1.0f;	//�n�_��y���W
	Speed = rand() % 5 + 5.0f;				
	float angle = rand() % 3 + 89.0f;		//89������91���܂ł͈̔͂ł��炷
	Vec.x = cos(angle * PI / 180.0f);		//���W�A���ւ̕ϊ�
	Vec.y = sin(angle * PI / 180.0f);		
	EndPos = StartPos - Vec * Len;			//�I�_�̈ʒu
	Vec *= Speed;
}

void WATER_FALL::perform()		//����Ăяo�����̂Ȃ̂Ōv�Z�͂ł��邾�����Ȃ��������B
{
	//�ړ�
	StartPos += Vec;
	EndPos += Vec;
	//��ʊO�֏o���珉����
	if (EndPos.y > 480)init();		
	//�`�揈��
	DrawLineAA(StartPos.x, StartPos.y, EndPos.x, EndPos.y,
		Color, SWeight);
}