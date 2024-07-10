#pragma once

//2次元ベクトルの配列と、ベクトル同士の計算のための定義(演算子のオーバーロード)
//必要最低限のものだけ用意しています。

class VECTOR2 {
public:
    float x, y;
    VECTOR2(float x = 0, float y = 0);
    VECTOR2 operator+ (const VECTOR2& v) const;
    VECTOR2 operator- (const VECTOR2& v) const;
    VECTOR2 operator* (float f) const;
    void operator+= (const VECTOR2& v);
    void operator*= (float f);
};

float length(const VECTOR2& a);
float sqLength(const VECTOR2& a);
VECTOR2 normalize(const VECTOR2& a);