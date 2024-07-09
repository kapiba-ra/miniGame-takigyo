#pragma once
#include "SCENE.h"

class GAME_CLEAR :
    public SCENE
{
public:
    struct DATA {
        int textColor = 0;              //テキストの色
        int textSize = 0;               //サイズ
        VECTOR2 pos = 0;                //場所の指定
        int messageFont = 0;            //フォント
        char endMessage[20] = {};       //クリアメッセージ
        char toTitleMessage[20] = {};   //タイトルへ
    };
private:
    DATA GameClear;        //上の構造体の実体
public:
    GAME_CLEAR(class GAME* game);
    ~GAME_CLEAR();
    void init();
    void update();
    void draw();
    void nextScene();
};