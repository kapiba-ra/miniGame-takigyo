#pragma once

class WATER_FALL_ART
{
private:
    int Num = 0;                                //Numは線の本数
    class WATER_FALL* Waterfalls = nullptr;     //WATER_FALLのポインタを用意
public:
    WATER_FALL_ART();
    ~WATER_FALL_ART();
    void perform();
};