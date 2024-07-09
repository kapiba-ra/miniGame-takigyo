#pragma once
#include "GAME_OBJECT.h"
#include "VECTOR2.h"

class ENEMIES :
    public GAME_OBJECT
{
public:
    //���ʃf�[�^
    struct DATA {
        int totalNum = 0;           //�ő�̐�
        int curNum = 0;             //���݂̐�
        int img = 0;                //�摜�`��p�̃n���h��
        double exRate = 0;          //�摜�g�嗦
        double angle = 0;           //�摜�̊p�x
    //�G�̈ʒu
        float majRadius = 0;        //�ȉ~�̒����a
        float minRadius = 0;        //�ȉ~�̒Z���a
        VECTOR2 centerPos = 0;      //�ȉ~�̒��S�B�ȉ~���G������
        float fallSpeed = 0;        //�ȉ~�̒��S�����ɗ��鑬�x
        float targetPosY = 0;       //�ȉ~�̒��S��y���W�̍ő�l
        float refTheta = 0;         //�(reference)�p�x�B���ۂɉ�]���������������
        float thetaSpeed = 0;       //�p�x�𑫂��Ă���
    //�e�̔���
        float triggerInterval = 0;  //���˂̊Ԋu
        float ofstLaunchDist = 0;   //���ˈʒu�̒���
    //�����蔻��
        float bcRadius = 0;         //�����蔻��p�̉~�̔��a
        float invincibleTime = 0;   //�G�ɂ��킸���ɖ��G���Ԃ�ݒ肷��
    //hp
        VECTOR2 hpGaugeOfst = 0;    //hp�Q�[�W�\���ʒu����
        int initHp = 0;
        int hpColor = 0;
    };
private:
    DATA Enemy;     //���ʃf�[�^�̎���
    //�P�̃f�[�^�̔z��
    struct ENEMY {
        VECTOR2 pos;
        float ofstTheta = 0;                //�`��ʒu(���S����̊p�x)�̒���
        float triggerErapsedTime = 0;       //�o�ߎ���
        float invincibleRestTime = 0;       //���G���Ԏc��
        int hp = 0;
    };
    ENEMY* Enemies;
public:
    ENEMIES(class GAME* game);
    ~ENEMIES();
    void create();
    void init();
    void update();          //�ȉ���3�̊֐����񂵑�����
        void move();        //�G�̈ړ�
        void collision();   //�����蔻��
        void launch();      //�e�̔��ˈʒu�ƊԊu�̊֐�
    void draw();
    int curNum() const { return Enemy.curNum; }   //STAGE�N���A�̏����Ɏg��
};

