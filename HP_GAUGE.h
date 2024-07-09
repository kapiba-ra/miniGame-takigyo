#pragma once
#include "GAME_OBJECT.h"
#include "DxLib.h"
#include "VECTOR2.h"
class HP_GAUGE :
    public GAME_OBJECT
{
public:
	struct  DATA
	{
		int Color = 0;				//�F�̃n���h��
			int safeColor = 0;		//�ʏ펞
			int dangerColor = 0;	//hp1�ȉ�
		float hpHeight = 0;			//����
		float hpWidth = 0;			//��
	};
private:
	DATA HpGauge;
public:
	HP_GAUGE(class GAME* game);
	~HP_GAUGE();
	void create();
	void draw(VECTOR2 pos, VECTOR2 ofst, int hp);
};

