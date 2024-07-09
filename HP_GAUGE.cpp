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
//hpによって呼び出すhpゲージの色を変える
	if (hp > 1) HpGauge.Color = HpGauge.safeColor;
	else	    HpGauge.Color = HpGauge.dangerColor;
//描画	hpの幅はhpによって変わる
	if (hp > 0) {		//hpゲージがマイナスになったら表示しない。
		DrawBoxAA(pos.x - hp * HpGauge.hpWidth, pos.y - ofst.y - HpGauge.hpHeight,
			pos.x + hp * HpGauge.hpWidth, pos.y - ofst.y, HpGauge.Color, TRUE, 2.0f);
	}
}
