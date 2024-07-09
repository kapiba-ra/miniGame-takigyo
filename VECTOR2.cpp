#include "VECTOR2.h"
#include <cmath>

VECTOR2::VECTOR2(float x, float y) : x(x), y(y) {}

VECTOR2 VECTOR2::operator+ (const VECTOR2& v) const {
    return VECTOR2(x + v.x, y + v.y);
}

VECTOR2 VECTOR2::operator- (const VECTOR2& v) const {
    return VECTOR2(x - v.x, y - v.y);
}

VECTOR2 VECTOR2::operator* (float f) const {
    return VECTOR2(x * f, y * f);
}

//VECTOR2 VECTOR2::operator/ (float f) const {
//    return VECTOR2(x / f, y / f);
//}

//VECTOR2 VECTOR2::operator- () const {
//    return VECTOR2(-x, -y);
//}

void VECTOR2::operator+= (const VECTOR2& v) {
    x += v.x;
    y += v.y;
}

//void VECTOR2::operator-= (const VECTOR2& v) {
//    x -= v.x;
//    y -= v.y;
//}

void VECTOR2::operator*= (float f) {
    x *= f;
    y *= f;
}

//void VECTOR2::operator/= (float f) {
//    x /= f;
//    y /= f;
//}

//VECTOR2 operator* (float f, const VECTOR2& v) {
//    return VECTOR2(v.x * f, v.y * f);
//}

float length(const VECTOR2& a) {
    return std::sqrt(a.x * a.x + a.y * a.y);
}

float sqLength(const VECTOR2& a) {
    return a.x * a.x + a.y * a.y;
}

VECTOR2 normalize(const VECTOR2& a) {
    float len = length(a);
    if (len != 0.0f) {
        return VECTOR2(a.x / len, a.y / len);
    }
    return VECTOR2(0, 0);
}

//float dot(const VECTOR2& a, const VECTOR2& b) {
//    return a.x * b.x + a.y * b.y;
//}
//
//float cross(const VECTOR2& a, const VECTOR2& b) {
//    return a.x * b.y - a.y * b.x;
//}
