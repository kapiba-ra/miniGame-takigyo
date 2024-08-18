#pragma once
#include "Dxlib.h"
#include "GAME.h"
#include "GAME_OBJECT.h"
#include "VECTOR2.h"
#include "SOUND.h"
#include "PoolAllocator.h"

//PLAYER_BULLETS,ENEMY_BULLETSの基底クラス

class BULLETS :
    public GAME_OBJECT
{
public:
    struct DATA {
        int totalNum = 0;       //最大数
        int curNum = 0;         //現在飛んでいる弾の数
        int img = 0;            //画像描画用のハンドル
        double exRate = 0;      //画像拡大率
        double angle = 0;       //画像の角度
        float advSpeed = 0;     //移動速度
        float angSpeed = 0;     //回転速度
        float bcRadius = 0;     //bounding circle　当たり判定の円
        int damage = 0;         //弾のダメージ
        SOUND sound;            //弾のse
    };
private:
    //共通データ
    DATA Bullet;
    //単体データの配列
    struct BULLET {
        VECTOR2 pos = 0;        //位置
        VECTOR2 vec = 0;        //発射方向
    };
    //BULLET* Bullets;            //配列は複数形
    PoolAllocator<BULLET, 20> Bullets;  // アロケータの実装を試みる

    int screenWidth = 0;
    int screenHeight = 0;
protected:
    //派生クラスのcreate()で呼び出すのでprotected
    void SetBullets(const BULLETS::DATA& data);
public:
    BULLETS(class GAME* game);
    ~BULLETS();
    void init();
    void launch(const VECTOR2& pos, const VECTOR2& vec);
    void update();
    void kill(int i);
    void draw();
    //弾の情報を得るgetterたち
    VECTOR2 pos(int i) { return Bullets[i].pos; }
    float bcRadius() const { return Bullet.bcRadius; }
    int curNum() const { return Bullet.curNum; }
    int damage() const { return Bullet.damage; }
};