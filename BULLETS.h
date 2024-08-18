#pragma once
#include "Dxlib.h"
#include "GAME.h"
#include "GAME_OBJECT.h"
#include "VECTOR2.h"
#include "SOUND.h"
#include "PoolAllocator.h"

//PLAYER_BULLETS,ENEMY_BULLETS�̊��N���X

class BULLETS :
    public GAME_OBJECT
{
public:
    struct DATA {
        int totalNum = 0;       //�ő吔
        int curNum = 0;         //���ݔ��ł���e�̐�
        int img = 0;            //�摜�`��p�̃n���h��
        double exRate = 0;      //�摜�g�嗦
        double angle = 0;       //�摜�̊p�x
        float advSpeed = 0;     //�ړ����x
        float angSpeed = 0;     //��]���x
        float bcRadius = 0;     //bounding circle�@�����蔻��̉~
        int damage = 0;         //�e�̃_���[�W
        SOUND sound;            //�e��se
    };
private:
    //���ʃf�[�^
    DATA Bullet;
    //�P�̃f�[�^�̔z��
    struct BULLET {
        VECTOR2 pos = 0;        //�ʒu
        VECTOR2 vec = 0;        //���˕���
    };
    //BULLET* Bullets;            //�z��͕����`
    PoolAllocator<BULLET, 20> Bullets;  // �A���P�[�^�̎��������݂�

    int screenWidth = 0;
    int screenHeight = 0;
protected:
    //�h���N���X��create()�ŌĂяo���̂�protected
    void SetBullets(const BULLETS::DATA& data);
public:
    BULLETS(class GAME* game);
    ~BULLETS();
    void init();
    void launch(const VECTOR2& pos, const VECTOR2& vec);
    void update();
    void kill(int i);
    void draw();
    //�e�̏��𓾂�getter����
    VECTOR2 pos(int i) { return Bullets[i].pos; }
    float bcRadius() const { return Bullet.bcRadius; }
    int curNum() const { return Bullet.curNum; }
    int damage() const { return Bullet.damage; }
};