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
    int m_movetype;
    void StateMove0();
    void StateMove1();
    void StateMove2();
    void StateMove3();
public:
    Enemy(const CVector2D& pos, bool flip,int Movetype);
    CImage m_img;
    float move_speed_y = 4.0f;
    float move_speed_x = 2.0f;

    bool m_flip;
    void Update();
    void Draw();
    void Collision(Base* b);

    static TexAnimData _anim_data[];
};