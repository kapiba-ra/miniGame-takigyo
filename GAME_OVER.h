#pragma once
#include "SCENE.h"

class GAME_OVER :
    public SCENE
{
public:
    struct DATA {
        int textColor = 0;              //テキストの色
        int textSize = 0;               //サイズ
        VECTOR2 pos = 0;                //場所の指定
        int messageFont = 0;            //フォント
        char endMessage[16] = {};       //文字の配列(4の倍数で設定)
    };
private:
    DATA GameOver;        //上の構造体の実体
public:
    GAME_OVER(class GAME* game);
    ~GAME_OVER();
    void init();
    void update();
    void draw();
    void nextScene();
};