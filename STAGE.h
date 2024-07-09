#pragma once
#include "SCENE.h"
#include "WATER_FALL_ART.h"

class STAGE :
    public SCENE        //SCENE�̌p��
{
public:
    struct DATA {
        int textColor = 0;              //�e�L�X�g�̐F
        int textSize = 0;               //�T�C�Y
        VECTOR2 pos = 0;                //�ꏊ�̎w��
        int messageFont = 0;            //�t�H���g
        char moveMessage[32] = {};      //�ړ����@
        char shotMessage[32] = {};      //�e��ł�
    };
private:
    DATA Stage;        //��̍\���̂̎���
public:
    STAGE(class GAME* game);
    ~STAGE();
    void init();
    void update();
    void draw();
    void nextScene();
    //�w�i�̎��̂�����
    WATER_FALL_ART WaterFallArt;
};

