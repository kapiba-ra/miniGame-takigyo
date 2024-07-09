#pragma once
#include "DxLib.h"
#include "GAME_OBJECT.h"
#include "VECTOR2.h"
#include "SOUND.h"

class PLAYER :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img = 0;                    //�摜(�ʏ펞)
        int hitImg = 0;                 //�摜(hit��)
        int awakenImg = 0;              //�摜(Item�擾��)
        float angle = 0;                //�摜�̊p�x
        float exRate = 0;               //�摜�̊g�嗦
        int graphic = 0;                //�摜�n���h��
        VECTOR2 pos = 0;                //�ʒu
        float advSpeed = 0;             //�ړ����x
        float limitW = 0;               //x���W�̈ړ��͈͂̐���
    //����(launch)�p
        VECTOR2 launchVec = 0;          //���˕���
        float triggerErapsedTime = 0;   //�o�ߎ���
        float triggerInterval = 0;      //���˂̊Ԋu
        float ofstLaunchDist = 0;       //���ˏꏊ���w�肷��
        int bulletSE = 0;               //�e��SE
    //�����蔻��
        float bcRadius = 0;
        float invincibleTime = 0;       //���G����
        float invincibleRestTime = 0;   //���G���Ԏc��
    //hp
        VECTOR2 hpGaugeOfst = 0;        ////hp�Q�[�W�\���ʒu����
        int hp = 0;
        int hpColor = 0;
    //sound
    //    SOUND sound;
    };
private:
    DATA Player;
    int screenWidth = 0;  // ��ʂ̕���ێ����郁���o�ϐ�
public:
    PLAYER(class GAME* game);
    ~PLAYER();
    void create();
    void init();
    void update();          //�ȉ��̂R���܂Ƃ߂��֐�
        void move();        //�G�̈ړ�
        void launch();      //�e�̔��ˈʒu�ƊԊu�̊֐�
        void collision();   //�����蔻��
        void zoom();
    void draw();
    VECTOR2 pos() const { return Player.pos; }
    int hp() const { return Player.hp; }
    void itemHit();         //ITEM�N���X�ŌĂяo��
};

