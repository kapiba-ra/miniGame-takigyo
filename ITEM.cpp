#include "CONTAINER.h"
#include "GAME.h"
#include "ITEM.h"

ITEM::ITEM(GAME* game) :
	GAME_OBJECT(game){
}
ITEM::~ITEM(){
}

void ITEM::create(){
	Item = game()->container()->itemData();
}

void ITEM::init(){
	//x���W��PLAYER�̈ړ��͈͂�菭���������͈͂Ń����_���ɐݒ�
	Item.pos.x = static_cast<float>(Item.limitW) + rand() % (game()->container()->SCREEN_WIDTH - 2 * Item.limitW);
	Item.pos.y = game()->container()->itemData().pos.y;
	Item.active = game()->container()->itemData().active;
}

void ITEM::update(){
	//Item���L���̎��Ɋ֐����Ăяo��
	if (Item.active) {
		move();
		collision();
	}
}

void ITEM::move(){
	Item.pos.y += Item.fallSpeed;	//ITEM����葬�x�ŗ��Ƃ�
	if (Item.pos.y >= game()->container()->SCREEN_HEIGHT) {
		Item.active = false;		//��ʊO�֍s������ITEM�𖳌���
	}
}

void ITEM::collision(){
	//sqDistance(square distance)�́A�����蔻����s���Œ������̓��
	float distance = game()->container()->playerData().bcRadius + Item.bcRadius;
	float sqDistance = distance * distance;
	//ITEM����PLAYER�ւ̋���
	VECTOR2 vec = game()->playerInst()->pos() - Item.pos;
	//(ITEM����PLAYER�ւ̋����̂Q��)<=(�����蔻����s���Œ������̂Q��)��ITEM�𖳌���
	if (sqLength(vec)<=sqDistance && Item.active){
		Item.active = false;
		game()->playerBulletsInst()->powerUpBullets();		//�e����������
		game()->playerInst()->itemHit();					//PLAYER�̒ʏ펞�摜��ς���
	}
}

void ITEM::draw() {
	//Item���L���̎��Ɋ֐����Ăяo��
	if (Item.active) {
	DrawRotaGraphF(Item.pos.x, Item.pos.y, Item.exRate, Item.angle, Item.img, TRUE);
	}
}
