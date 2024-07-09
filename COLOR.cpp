//#include "COLOR.h"
//
//// デフォルトコンストラクタ
//COLOR::COLOR() : r(0), g(0), b(0), a(0) {}
//
//// RGBのみ指定するコンストラクタ
//COLOR::COLOR(int r, int g, int b) : r(r), g(g), b(b), a(1) {}
//
//// RGBAを指定するコンストラクタ
//COLOR::COLOR(int r, int g, int b, int a) : r(r), g(g), b(b), a(a) {}
//
//// unsigned整数から色を指定するコンストラクタ
//// 例えば0xFFFFFFは白色を示す
//COLOR::COLOR(unsigned c) {
//    r = static_cast<int>((c >> 16) & 0xFF) / 255;
//    g = static_cast<int>((c >> 8) & 0xFF) / 255;
//    b = static_cast<int>(c & 0xFF) / 255;
//    a = 1;
//}
//
//// スカラー倍の演算子オーバーロード
////COLOR operator*(int f) const {
////    return COLOR(r * f, g * f, b * f, a);
////}