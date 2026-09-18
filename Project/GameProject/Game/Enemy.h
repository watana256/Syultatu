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
    int m_speed_x;
    int m_speed_y;
    void StateMove0();
    void StateMove1();
    void StateMove2();
    void StateMove22();
    void StateMove3();
public:
    Enemy(const CVector2D& pos, bool flip,int Movetype,float Speed_x, float Speed_y);
    CImage m_img;

    bool m_flip;
    void Update();
    void Draw();
    void Collision(Base* b);

    static TexAnimData _anim_data[];
};