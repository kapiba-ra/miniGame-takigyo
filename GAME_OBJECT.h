#pragma once

//GAME_OBJECTは、ゲーム内の名前がつくもの全ての基底クラス。
//game()は継承する全てのオブジェクトで呼び出すことができる。
//派生クラスでは以下のように使えるので便利。
//game()->container()->(クラス名)Data.(アクセスしたいデータ);

class GAME_OBJECT
{
public:
	GAME_OBJECT(class GAME* game);
	virtual ~GAME_OBJECT();
//GAMEクラスのポインタ"Game"の初期設定とゲッター関数"game()"。
private:
	class GAME* Game = 0;
public:
	class GAME* game() { return Game; }
};