#pragma once
class GAME
{
public:
	GAME();
	~GAME();
	void run();
//CONTAINER�̃f�[�^�ւ̃A�N�Z�X�p
private:	
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }
//SCENE �萔��0���珇�ɗ^������B
public:
	enum SCENE_ID {
		TITLE_ID,
		STAGE_ID,
		GAME_CLEAR_ID,
		GAME_OVER_ID,
		NUM_SCENES		//4�ł��傤�Ǐ�ʂ̑����ɂȂ�B
	};
	void changeScene(SCENE_ID sceneId);
private:
	class SCENE* Scenes[NUM_SCENES];	//���N���X�uSCENE�v�̂S�̃|�C���^���p�ӂ����B
	SCENE_ID CurSceneId;	//Current SceneId
//�L�����N�^
private:	//�e�N���X�̃|�C���^��ݒ�
	class PLAYER* Player;
	class ENEMIES* Enemies;
	class BOSS* Boss;
	class PLAYER_BULLETS* PlayerBullets;
	class ENEMY_BULLETS* EnemyBullets;
	class BOSS_BULLETS* BossBullets;
	class HP_GAUGE* HpGauge;
	class ITEM* Item;
public:		//�e�N���X�̃|�C���^�̃Q�b�^�[�֐��BInst��Instance�Ƃ���playerData()���Ƌ��
	class PLAYER* playerInst() { return Player; };
	class ENEMIES* enemiesInst() { return Enemies; }
	class BOSS* bossInst() { return Boss; }
	class PLAYER_BULLETS* playerBulletsInst(){ return PlayerBullets; }
	class ENEMY_BULLETS* enemyBulletsInst(){ return EnemyBullets; }
	class BOSS_BULLETS* bossBulletsInst(){ return BossBullets; }
	class HP_GAUGE* hpGaugeInst(){ return HpGauge; }
	class ITEM* itemInst(){ return Item; }
	void draw();
};