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
        int textColor = 0;      //テキストの色
        int textSize = 0;       //サイズ
        int countTime = 0;      //startで設定した文字を点滅させるのに使う
        VECTOR2 pos = 0;        //場所の指定(左上)
        int startFont = 0;      //フォントの種類
        int titleNameFont = 0;  //同上
        char start[16] = {};     //文字の配列(4の倍数で設定)
        char titleName[16] = {}; //同上
    };
private:
    DATA Title;             //上の構造体の実体
public:
    TITLE(class GAME* game);
    ~TITLE();
    void init();
    //Sceneクラスのproc()で呼び出される
    void draw();
    void nextScene();
};

