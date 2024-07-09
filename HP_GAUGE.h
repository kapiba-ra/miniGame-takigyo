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
		int Color = 0;				//F‚Ìƒnƒ“ƒhƒ‹
			int safeColor = 0;		//’Êí
			int dangerColor = 0;	//hp1ˆÈ‰º
		float hpHeight = 0;			//‚‚³
		float hpWidth = 0;			//•
	};
private:
	DATA HpGauge;
public:
	HP_GAUGE(class GAME* game);
	~HP_GAUGE();
	void create();
	void draw(VECTOR2 pos, VECTOR2 ofst, int hp);
};

