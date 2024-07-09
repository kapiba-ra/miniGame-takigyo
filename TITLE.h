#pragma once
#include "SCENE.h"
#include "DxLib.h"
#include "VECTOR2.h"
#include "COLOR.h"
class TITLE :
    public SCENE
{
public:
    struct DATA {
        int textColor = 0;      //�e�L�X�g�̐F
        int textSize = 0;       //�T�C�Y
        int countTime = 0;      //start�Őݒ肵��������_�ł�����̂Ɏg��
        VECTOR2 pos = 0;        //�ꏊ�̎w��(����)
        int startFont = 0;      //�t�H���g�̎��
        int titleNameFont = 0;  //����
        char start[16] = {};     //�����̔z��(4�̔{���Őݒ�)
        char titleName[16] = {}; //����
    };
private:
    DATA Title;             //��̍\���̂̎���
public:
    TITLE(class GAME* game);
    ~TITLE();
    void init();
    //Scene�N���X��proc()�ŌĂяo�����
    void draw();
    void nextScene();
};

