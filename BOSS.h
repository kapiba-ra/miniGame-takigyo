#pragma once
#include "GAME_OBJECT.h"
#include "VECTOR2.h"

class BOSS :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img = 0;                //画像描画用のハンドル
        double exRate = 0;          //画像拡大率
        double angle = 0;           //画像の角度
        //敵の位置
        VECTOR2 pos;                //中心座標
        float xSpeed = 0;           //x軸方向のスピード
        float ySpeed = 0;           //y軸方向のスピード
        float targetPosY = 0;       //y座標の最大値
        //弾の発射
        float triggerErapsedTime = 0;       //経過時間
        float triggerInterval = 0;          //発射の間隔
        float ofstLaunchDist = 0;           //発射位置の調整
        //当たり判定
        float bcRadius = 0;                 //当たり判定用の円の半径
        float invincibleTime = 0;           //敵にもわずかに無敵時間を設定する
        float invincibleRestTime = 0;       //無敵時間残り
        //hp
        VECTOR2 hpGaugeOfst = 0;    //hpゲージ表示位置調整
        int hp = 0;
        int hpColor = 0;
    };
private:
    DATA Boss;     //データの実体
public:
    BOSS(class GAME* game);
    ~BOSS();
    void create();
    void init();
    void update();              //以下の3つの関数を回し続ける(条件付き)
        void move();            //敵の移動
        void collision();       //当たり判定
        void launch();          //弾の発射位置と間隔の関数
    void rotate();          //回転させる
    void draw();
    int hp() const { return Boss.hp; }   //STAGEクリアの条件に使う
};

