#pragma once
#include "DxLib.h"
#include "GAME_OBJECT.h"
#include "VECTOR2.h"
#include "SOUND.h"

class PLAYER :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img = 0;                    //画像(通常時)
        int hitImg = 0;                 //画像(hit時)
        int awakenImg = 0;              //画像(Item取得時)
        float angle = 0;                //画像の角度
        float exRate = 0;               //画像の拡大率
        int graphic = 0;                //画像ハンドル
        VECTOR2 pos = 0;                //位置
        float advSpeed = 0;             //移動速度
        float limitW = 0;               //x座標の移動範囲の制限
    //発射(launch)用
        VECTOR2 launchVec = 0;          //発射方向
        float triggerErapsedTime = 0;   //経過時間
        float triggerInterval = 0;      //発射の間隔
        float ofstLaunchDist = 0;       //発射場所を指定する
        int bulletSE = 0;               //弾のSE
    //当たり判定
        float bcRadius = 0;
        float invincibleTime = 0;       //無敵時間
        float invincibleRestTime = 0;   //無敵時間残り
    //hp
        VECTOR2 hpGaugeOfst = 0;        ////hpゲージ表示位置調整
        int hp = 0;
        int hpColor = 0;
    //sound
    //    SOUND sound;
    };
private:
    DATA Player;
    int screenWidth = 0;  // 画面の幅を保持するメンバ変数
public:
    PLAYER(class GAME* game);
    ~PLAYER();
    void create();
    void init();
    void update();          //以下の３つをまとめた関数
        void move();        //敵の移動
        void launch();      //弾の発射位置と間隔の関数
        void collision();   //当たり判定
        void zoom();
    void draw();
    VECTOR2 pos() const { return Player.pos; }
    int hp() const { return Player.hp; }
    void itemHit();         //ITEMクラスで呼び出す
};

