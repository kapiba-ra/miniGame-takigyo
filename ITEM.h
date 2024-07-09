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
		int img = 0;			//�摜�̃n���h��
		double exRate = 0;		//�摜�̊g�嗦
		double angle = 0;		//�摜�̊p�x
		VECTOR2 pos = 0;		//���W
		float fallSpeed = 0;	//�������x
		int limitW = 0;			//x���W�̈ړ��͈͐���
		//�����蔻��
		bool active = 0;		//ITEM���L�����ǂ�����\��
		float bcRadius = 0;		//�����蔻��̉~�̔��a
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