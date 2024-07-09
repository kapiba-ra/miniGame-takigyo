#pragma once
#include "SCENE.h"
#include "WATER_FALL_ART.h"

class STAGE :
    public SCENE        //SCENEの継承
{
public:
    struct DATA {
        int textColor = 0;              //テキストの色
        int textSize = 0;               //サイズ
        VECTOR2 pos = 0;                //場所の指定
        int messageFont = 0;            //フォント
        char moveMessage[32] = {};      //移動方法
        char shotMessage[32] = {};      //弾を打つ
    };
private:
    DATA Stage;        //上の構造体の実体
public:
    STAGE(class GAME* game);
    ~STAGE();
    void init();
    void update();
    void draw();
    void nextScene();
    //背景の実体を持つ
    WATER_FALL_ART WaterFallArt;
};

