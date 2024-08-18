#include "BULLETS.h"
#include "CONTAINER.h"
BULLETS::BULLETS(class GAME* game) :
	GAME_OBJECT(game)
	//,Bullets(0)
{
	screenWidth = this->game()->container()->getScreenWidth();
	screenHeight = this->game()->container()->getScreenWidth();
}
BULLETS::~BULLETS(){
	//delete[] Bullets;
}

void BULLETS::SetBullets(const BULLETS::DATA& data){
	Bullet = data;
	//Bullets = new BULLET[Bullet.totalNum];		//�e�̍ő吔���|�C���^�z������
}

void BULLETS::init(){
	Bullet.curNum = 0;
}

void BULLETS::launch(const VECTOR2& pos, const VECTOR2& vec) {
	//���݂̒e�̐����ő吔�𒴂��Ă��Ȃ��Ƃ��ɏ���
	if (Bullet.curNum < Bullet.totalNum) {
		//���˂����Bullets[0]���珇�Ɉʒu�Ɣ��˕������ݒ肳���B
		BULLET* newBullet = Bullets.Alloc(); // PoolAllocator����V�����e���m��
		if (newBullet) {
			newBullet->pos = pos;
			newBullet->vec = vec;
			Bullet.curNum++;
		}
	}
}

void BULLETS::update() {
    BULLET* current = &Bullets[0];  // PoolAllocator�̐擪����J�n
    for (int i = 0; i < Bullet.curNum; i++) {
        if (current) {
            current->pos += current->vec * Bullet.advSpeed;  // �e�̈ʒu���X�V
            Bullet.angle += Bullet.angSpeed;                // �e����]������

            // ��ʊO�ɏo���Ƃ��ɏ�����悤�ɏ���
            if (current->pos.y < Bullet.bcRadius ||
                current->pos.y > screenHeight + Bullet.bcRadius ||
                current->pos.x < -Bullet.bcRadius ||
                current->pos.x > screenWidth + Bullet.bcRadius) {
                kill(i);  // �e���폜
            }
            current++; // ���̒e��
        }
    }
}

void BULLETS::kill(int i) {
    BULLET* lastBullet = &Bullets[Bullet.curNum - 1];  // �Ō�̒e
    BULLET* bulletToKill = &Bullets[i];                // �폜�Ώۂ̒e

    if (bulletToKill && lastBullet) {
        *bulletToKill = *lastBullet;  // �폜�Ώۂ̒e�ɍŌ�̒e���㏑��
        Bullets.Free(lastBullet);     // PoolAllocator������
        Bullet.curNum--;              // ���݂̒e�̐������炷
    }
}

void BULLETS::draw() {
    BULLET* current = &Bullets[0];  // PoolAllocator�̐擪����J�n
    for (int i = 0; i < Bullet.curNum; i++) {
        if (current) {
            DrawRotaGraphF(current->pos.x, current->pos.y, Bullet.exRate,
                Bullet.angle, Bullet.img, TRUE);
            current++;  // ���̒e��
        }
    }
}
