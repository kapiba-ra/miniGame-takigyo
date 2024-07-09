#pragma once
#include "SCENE.h"

class GAME_CLEAR :
    public SCENE
{
public:
    struct DATA {
        int textColor = 0;              //�e�L�X�g�̐F
        int textSize = 0;               //�T�C�Y
        VECTOR2 pos = 0;                //�ꏊ�̎w��
        int messageFont = 0;            //�t�H���g
        char endMessage[20] = {};       //�N���A���b�Z�[�W
        char toTitleMessage[20] = {};   //�^�C�g����
    };
private:
    DATA GameClear;        //��̍\���̂̎���
public:
    GAME_CLEAR(class GAME* game);
    ~GAME_CLEAR();
    void init();
    void update();
    void draw();
    void nextScene();
};