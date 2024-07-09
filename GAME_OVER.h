#pragma once
#include "SCENE.h"

class GAME_OVER :
    public SCENE
{
public:
    struct DATA {
        int textColor = 0;              //�e�L�X�g�̐F
        int textSize = 0;               //�T�C�Y
        VECTOR2 pos = 0;                //�ꏊ�̎w��
        int messageFont = 0;            //�t�H���g
        char endMessage[16] = {};       //�����̔z��(4�̔{���Őݒ�)
    };
private:
    DATA GameOver;        //��̍\���̂̎���
public:
    GAME_OVER(class GAME* game);
    ~GAME_OVER();
    void init();
    void update();
    void draw();
    void nextScene();
};