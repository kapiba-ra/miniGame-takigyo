#include "SOUND.h"

SOUND::SOUND(){
}
SOUND::~SOUND(){
}

void SOUND::loadPlayerSound(){
	pBulletSE = LoadSoundMem("sounds\\se_shot.mp3");
	upBulletSE = LoadSoundMem("sounds\\se_upshot.mp3");
	ChangeVolumeSoundMem(255 * 50 / 100, pBulletSE);
	ChangeVolumeSoundMem(255 * 50 / 100, upBulletSE);
}