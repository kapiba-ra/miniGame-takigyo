//#include "COLOR.h"
//
//// �f�t�H���g�R���X�g���N�^
//COLOR::COLOR() : r(0), g(0), b(0), a(0) {}
//
//// RGB�̂ݎw�肷��R���X�g���N�^
//COLOR::COLOR(int r, int g, int b) : r(r), g(g), b(b), a(1) {}
//
//// RGBA���w�肷��R���X�g���N�^
//COLOR::COLOR(int r, int g, int b, int a) : r(r), g(g), b(b), a(a) {}
//
//// unsigned��������F���w�肷��R���X�g���N�^
//// �Ⴆ��0xFFFFFF�͔��F������
//COLOR::COLOR(unsigned c) {
//    r = static_cast<int>((c >> 16) & 0xFF) / 255;
//    g = static_cast<int>((c >> 8) & 0xFF) / 255;
//    b = static_cast<int>(c & 0xFF) / 255;
//    a = 1;
//}
//
//// �X�J���[�{�̉��Z�q�I�[�o�[���[�h
////COLOR operator*(int f) const {
////    return COLOR(r * f, g * f, b * f, a);
////}