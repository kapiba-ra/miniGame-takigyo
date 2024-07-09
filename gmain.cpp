#include "GAME.h"
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	GAME game;
	game.run();
	return 0;
}

//・クラスのprivateなメンバは基本的に大文字始まりにしています。
//・各データの実体はprivateにしており外部からアクセスできないようにしています。
//・getter関数は基本ヘッダで定義することでインライン展開を期待しています。
//・CONTAINERクラスに各クラスのデータをまとめることで保守性の確保を試みています。
//・backgroundについては他のクラスに容易にアクセスできなくても特に問題ないかなと考え、
//	独立して定義してみました。

//技術的な未解決の課題：
//①いくつかマジックナンバーが残ってしまいました(PLAYER_BULLETS.cpp、背景色の設定等)。
//②フレームレート60が前提になっているので環境によっては動きが変わってしまいます。
//③ITEMを取ったときに弾を強化する関数をPLAYER_BULLETSクラスに設定しています。
//  色々試した末に、現状はContainer(データ群)の情報を直接書き換えて後で戻すという事をしており、
//	あまり好ましくない方法を取っています。他のスマートな方法を模索中です。