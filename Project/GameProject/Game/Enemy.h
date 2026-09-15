#pragma once
#include "Base/Base.h"
class Enemy : public Base {
private:

    //アニメーションの種類
    enum {
        eAnimIdle = 0,
    };
    int m_state;
    enum {
        eState_Idle,
    };
    void StateIdle();

public:
    Enemy(const CVector2D& pos,bool flip);
    CImage m_img;
    int m_cnt;
    bool m_flip;
    void Update();
    void Draw();
    static TexAnimData _anim_data[];
};