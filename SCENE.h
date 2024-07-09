#pragma once
#include "GAME_OBJECT.h"

class SCENE 
    : public GAME_OBJECT
{
public:
    SCENE(class GAME* game);
    //仮想関数にすることで派生クラスの関数が呼び出される
    virtual ~SCENE();
    virtual void create();
    virtual void init();
    virtual void proc(); //procedure
        virtual void update();
        virtual void draw();
        virtual void nextScene();
public:
    //各シーンがZキー押しっぱなしで連続で切り替わるのを防ぐ
    bool ChangeStopFlag = true;
};