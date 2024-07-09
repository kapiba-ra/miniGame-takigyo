#include "CONTAINER.h"
#include "GAME.h"
#include "HP_GAUGE.h"

HP_GAUGE::HP_GAUGE(GAME* game) :
	GAME_OBJECT(game){
}
HP_GAUGE::~HP_GAUGE(){
}

void HP_GAUGE::create() {
	HpGauge = game()->container()->hpGaugeData();
}

void HP_GAUGE::draw(VECTOR2 pos, VECTOR2 ofst, int hp){
//hp�ɂ���ČĂяo��hp�Q�[�W�̐F��ς���
	if (hp > 1) HpGauge.Color = HpGauge.safeColor;
	else	    HpGauge.Color = HpGauge.dangerColor;
//�`��	hp�̕���hp�ɂ���ĕς��
	if (hp > 0) {		//hp�Q�[�W���}�C�i�X�ɂȂ�����\�����Ȃ��B
		DrawBoxAA(pos.x - hp * HpGauge.hpWidth, pos.y - ofst.y - HpGauge.hpHeight,
			pos.x + hp * HpGauge.hpWidth, pos.y - ofst.y, HpGauge.Color, TRUE, 2.0f);
	}
}
