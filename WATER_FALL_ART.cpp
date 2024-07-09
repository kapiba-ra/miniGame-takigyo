#include "WATER_FALL_ART.h"
#include "WATER_FALL.h"

//流れの線の本数を変えられる。

WATER_FALL_ART::WATER_FALL_ART(){
	Num = 200;
	Waterfalls = new WATER_FALL[Num];		//Numの数だけ配列を作り、それぞれのアドレスをポインタへ
}
WATER_FALL_ART::~WATER_FALL_ART(){
	delete[]Waterfalls;
}

void WATER_FALL_ART::perform(){
	for (int i = 0; i < Num; i++) {
		Waterfalls[i].perform();		//WATER_FALLのperform()を呼び出す。
	}
}
