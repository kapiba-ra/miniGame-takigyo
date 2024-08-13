#include "DxLib.h"
#include "TITLE.h"
#include "STAGE.h"
#include "GAME_CLEAR.h"
#include "GAME_OVER.h"
#include "CONTAINER.h"
#include "PLAYER.h"
#include "ENEMIES.h"
#include "BOSS.h"
#include "PLAYER_BULLETS.h"
#include "ENEMY_BULLETS.h"
#include "BOSS_BULLETS.h"
#include "HP_GAUGE.h"
#include "GAME.h"

GAME::GAME(){
	Container = new CONTAINER;
	//�����Ƃ���GAME�N���X�̃C���X�^���X"game"�̃|�C���^��ݒ�
	//game�|�C���^�͍ŏI�I�ɁA�ȉ��ŃC���X�^���X�����ꂽ�N���X�̊��N���X"GAME_OBJECT"�֓n�����
	//���������đS�Ă̔h���N���X��GAME�N���X�̃����o�ɃA�N�Z�X�ł���悤�ɂȂ�
	Scenes[TITLE_ID] = new TITLE(this);
	Scenes[STAGE_ID] = new STAGE(this);
	Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
	Scenes[GAME_OVER_ID] = new GAME_OVER(this);
	CurSceneId = TITLE_ID;
	//
	Player = new PLAYER(this);
	Enemies = new ENEMIES(this);
	Boss = new BOSS(this);
	PlayerBullets = new PLAYER_BULLETS(this);
	EnemyBullets = new ENEMY_BULLETS(this);
	BossBullets = new BOSS_BULLETS(this);
	HpGauge = new HP_GAUGE(this);
	Item = new ITEM(this);
}
GAME::~GAME(){
	delete Item;
	delete HpGauge;
	delete BossBullets;
	delete EnemyBullets;
	delete PlayerBullets;
	delete Boss;
	delete Enemies;
	delete Player;
	for (int i = 0; i < NUM_SCENES; i++) {
		delete Scenes[i];
	}
	delete Container;
}
//�����I��main�֐�
void GAME::run(){	
	//����ʏ����ȂǏ��X�̐ݒ�
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) { DxLib_End(); }
	SetDrawScreen(DX_SCREEN_BACK);
	SetBackgroundColor(100, 150, 200, 128);			//������TITLE�̔w�i�F��ݒ肷��
	//CONTAINER�N���X�ɂ���e�N���X�̃f�[�^�\����(�������n�܂�)�Ƀf�[�^��ݒ肷��B
	Container->load();
	//�e�N���X�̃f�[�^�\����(�啶���n�܂�)�ɁAload()�Őݒ肵���f�[�^������B
	Player->create();
	Enemies->create();
	Boss->create();
	PlayerBullets->create();
	EnemyBullets->create();
	BossBullets->create();
	HpGauge->create();
	Item->create();
	//TITEL��init()���Ăяo�����
	Scenes[CurSceneId]->init();

	while ((ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)){
		//���ꂼ���update(),draw(),nextScene()���Ăяo�����
		Scenes[CurSceneId]->proc();
	}
	DxLib_End();
}

//�V�[���̐؂�ւ�
void GAME::changeScene(SCENE_ID sceneId) {
	CurSceneId = sceneId;
	Scenes[CurSceneId]->init();
}
//�`��
void GAME::draw(){
	Player->draw();
	Enemies->draw();
	Boss->draw();
	PlayerBullets->draw();
	EnemyBullets->draw();
	BossBullets->draw();
	Item->draw();
}