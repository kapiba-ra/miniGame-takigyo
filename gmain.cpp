#include "GAME.h"
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	GAME game;
	game.run();
	return 0;
}

//概要
//・管理用にGAMEクラスを用意する、GAME_OBJECTクラスの派生クラスとしてSCENEやキャラクタのクラスを
//	作っていくという基本的なクラスの構造は、他の方のソースコードを参考にしました。
//・クラスのprivateなメンバの名前は大文字始まりにしています。
//・各データの実体は基本privateにしており外部からアクセスできないようにしています。
//・CONTAINERクラスに各クラスのデータをまとめることで保守性の確保を試みています。
//・getter関数は基本ヘッダで定義することでインライン展開を期待しています。

//技術的な未解決の課題(自覚する範囲で)：
//�@いくつかマジックナンバーが残ってしまいました(PLAYER_BULLETS.cpp、背景色の設定等)。
//�Aフレームレート60が前提になっているので環境によっては動きが変わってしまいます。
//�BITEMを取ったときに弾を強化する関数をPLAYER_BULLETSクラスに設定しています。
//  色々試した末に、現状はContainer(データ群)の情報を直接書き換えて後で戻すという事をしており、
//	あまり好ましくない方法を取っています。他のスマートな方法を模索中です。
//