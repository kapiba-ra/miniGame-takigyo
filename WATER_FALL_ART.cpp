#include "WATER_FALL_ART.h"
#include "WATER_FALL.h"

//����̐��̖{����ς�����B

WATER_FALL_ART::WATER_FALL_ART(){
	Num = 200;
	Waterfalls = new WATER_FALL[Num];		//Num�̐������z������A���ꂼ��̃A�h���X���|�C���^��
}
WATER_FALL_ART::~WATER_FALL_ART(){
	delete[]Waterfalls;
}

void WATER_FALL_ART::perform(){
	for (int i = 0; i < Num; i++) {
		Waterfalls[i].perform();		//WATER_FALL��perform()���Ăяo���B
	}
}
