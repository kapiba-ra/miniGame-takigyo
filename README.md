#概要

・DXライブラリを使用しています。  
・管理用にGAMEクラスを用意する、GAME_OBJECTクラスの派生クラスとしてSCENEやキャラクタのクラスを作っていくという基本的なクラスの構造は、他の方のソースコードを参考にしました。    
・クラスのprivateなメンバの名前は大文字始まりにしています。  
・各データの実体は基本privateにしており外部からアクセスできないようにしています。  
・CONTAINERクラスに各クラスのデータをまとめることで保守性の確保を試みています。   

技術的な未解決の課題(自覚する範囲で)：  
①いくつかマジックナンバーが残ってしまいました(PLAYER_BULLETS.cpp、背景色の設定等)。  
②フレームレート60が前提になっているので環境によっては動きが変わってしまいます。  
③ITEMを取ったときに弾を強化する関数をPLAYER_BULLETSクラスに設定しています。
  色々試した末に、現状はContainer(データ群)の情報を直接書き換えて後で戻すという事をしており、
	あまり好ましくない方法かもしれないです...
