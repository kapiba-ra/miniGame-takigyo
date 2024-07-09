#include "BULLETS.h"
#include "CONTAINER.h"
BULLETS::BULLETS(class GAME* game) :
	GAME_OBJECT(game), Bullets(0){
	screenWidth = this->game()->container()->getScreenWidth();
	screenHeight = this->game()->container()->getScreenWidth();
}
BULLETS::~BULLETS(){
	delete[] Bullets;
}

void BULLETS::SetBullets(const BULLETS::DATA& data){
	Bullet = data;
	Bullets = new BULLET[Bullet.totalNum];		//�e�̍ő吔���|�C���^�z������
}

void BULLETS::init(){
	Bullet.curNum = 0;
}

void BULLETS::launch(const VECTOR2& pos, const VECTOR2& vec) {
	//���݂̒e�̐����ő吔�𒴂��Ă��Ȃ��Ƃ��ɏ���
	if (Bullet.curNum < Bullet.totalNum) {
		//���˂����Bullets[0]���珇�Ɉʒu�Ɣ��˕������ݒ肳���B
		int i = Bullet.curNum;
		Bullets[i].pos = pos;
		Bullets[i].vec = vec;
		Bullet.curNum++;
	}
}

void BULLETS::update(){
	//�e�̈ʒu�̍X�V(�z��폜���̎�Ԃ��l�����[�v�͌�납��)
	for (int i = Bullet.curNum - 1; i >= 0; i--) {
		Bullets[i].pos += Bullets[i].vec * Bullet.advSpeed;		//1�t���[����advSpeed�h�b�g�̋�����i��
		Bullet.angle += Bullet.angSpeed;						//�e����]������
		//��ʊO�ɏo���Ƃ��ɏ�����悤�ɏ���
		if (Bullets[i].pos.y < Bullet.bcRadius ||
			Bullets[i].pos.y>screenHeight + Bullet.bcRadius ||
			Bullets[i].pos.x < -Bullet.bcRadius ||
			Bullets[i].pos.x>screenWidth + Bullet.bcRadius) {
			kill(i);
		}
	}
}

void BULLETS::kill(int i) {
	Bullet.curNum--;							//���݂̒e�̐������炷
	Bullets[i] = Bullets[Bullet.curNum];		//���������e�ɔz��̍Ō�̒e�̏����㏑��
}

void BULLETS::draw(){
	for (int i = 0; i < Bullet.curNum; i++) {
		DrawRotaGraphF(Bullets[i].pos.x, Bullets[i].pos.y, Bullet.exRate,
			Bullet.angle, Bullet.img, TRUE);
	}
}