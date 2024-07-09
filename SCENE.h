#pragma once
#include "GAME_OBJECT.h"

class SCENE 
    : public GAME_OBJECT
{
public:
    SCENE(class GAME* game);
    //���z�֐��ɂ��邱�ƂŔh���N���X�̊֐����Ăяo�����
    virtual ~SCENE();
    virtual void create();
    virtual void init();
    virtual void proc(); //procedure
        virtual void update();
        virtual void draw();
        virtual void nextScene();
public:
    //�e�V�[����Z�L�[�������ςȂ��ŘA���Ő؂�ւ��̂�h��
    bool ChangeStopFlag = true;
};