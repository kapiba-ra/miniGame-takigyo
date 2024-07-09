#pragma once
#include "GAME_OBJECT.h"
#include "VECTOR2.h"

class BOSS :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img = 0;                //�摜�`��p�̃n���h��
        double exRate = 0;          //�摜�g�嗦
        double angle = 0;           //�摜�̊p�x
        //�G�̈ʒu
        VECTOR2 pos;                //���S���W
        float xSpeed = 0;           //x�������̃X�s�[�h
        float ySpeed = 0;           //y�������̃X�s�[�h
        float targetPosY = 0;       //y���W�̍ő�l
        //�e�̔���
        float triggerErapsedTime = 0;       //�o�ߎ���
        float triggerInterval = 0;          //���˂̊Ԋu
        float ofstLaunchDist = 0;           //���ˈʒu�̒���
        //�����蔻��
        float bcRadius = 0;                 //�����蔻��p�̉~�̔��a
        float invincibleTime = 0;           //�G�ɂ��킸���ɖ��G���Ԃ�ݒ肷��
        float invincibleRestTime = 0;       //���G���Ԏc��
        //hp
        VECTOR2 hpGaugeOfst = 0;    //hp�Q�[�W�\���ʒu����
        int hp = 0;
        int hpColor = 0;
    };
private:
    DATA Boss;     //�f�[�^�̎���
public:
    BOSS(class GAME* game);
    ~BOSS();
    void create();
    void init();
    void update();              //�ȉ���3�̊֐����񂵑�����(�����t��)
        void move();            //�G�̈ړ�
        void collision();       //�����蔻��
        void launch();          //�e�̔��ˈʒu�ƊԊu�̊֐�
    void rotate();          //��]������
    void draw();
    int hp() const { return Boss.hp; }   //STAGE�N���A�̏����Ɏg��
};

