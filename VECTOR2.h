#pragma once

//2�����x�N�g���̔z��ƁA�x�N�g�����m�̌v�Z�̂��߂̒�`(���Z�q�̃I�[�o�[���[�h)
//�K�v�Œ���̂��̂����p�ӂ��Ă��܂��B

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