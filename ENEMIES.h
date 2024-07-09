#pragma once
#include "GAME_OBJECT.h"
#include "VECTOR2.h"

class ENEMIES :
    public GAME_OBJECT
{
public:
    //共通データ
    struct DATA {
        int totalNum = 0;           //最大の数
        int curNum = 0;             //現在の数
        int img = 0;                //画像描画用のハンドル
        double exRate = 0;          //画像拡大率
        double angle = 0;           //画像の角度
    //敵の位置
        float majRadius = 0;        //楕円の長半径
        float minRadius = 0;        //楕円の短半径
        VECTOR2 centerPos = 0;      //楕円の中心。楕円上を敵が動く
        float fallSpeed = 0;        //楕円の中心が下に来る速度
        float targetPosY = 0;       //楕円の中心のy座標の最大値
        float refTheta = 0;         //基準(reference)角度。実際に回転させる役割を持つ
        float thetaSpeed = 0;       //角度を足していく
    //弾の発射
        float triggerInterval = 0;  //発射の間隔
        float ofstLaunchDist = 0;   //発射位置の調整
    //当たり判定
        float bcRadius = 0;         //当たり判定用の円の半径
        float invincibleTime = 0;   //敵にもわずかに無敵時間を設定する
    //hp
        VECTOR2 hpGaugeOfst = 0;    //hpゲージ表示位置調整
        int initHp = 0;
        int hpColor = 0;
    };
private:
    DATA Enemy;     //共通データの実体
    //単体データの配列
    struct ENEMY {
        VECTOR2 pos;
        float ofstTheta = 0;                //描画位置(中心からの角度)の調整
        float triggerErapsedTime = 0;       //経過時間
        float invincibleRestTime = 0;       //無敵時間残り
        int hp = 0;
    };
    ENEMY* Enemies;
public:
    ENEMIES(class GAME* game);
    ~ENEMIES();
    void create();
    void init();
    void update();          //以下の3つの関数を回し続ける
        void move();        //敵の移動
        void collision();   //当たり判定
        void launch();      //弾の発射位置と間隔の関数
    void draw();
    int curNum() const { return Enemy.curNum; }   //STAGEクリアの条件に使う
};

