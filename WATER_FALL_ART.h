#pragma once

class WATER_FALL_ART
{
private:
    int Num = 0;                                //Num�͐��̖{��
    class WATER_FALL* Waterfalls = nullptr;     //WATER_FALL�̃|�C���^��p��
public:
    WATER_FALL_ART();
    ~WATER_FALL_ART();
    void perform();
};