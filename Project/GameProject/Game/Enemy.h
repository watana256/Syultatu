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
    Enemy(const CVector2D& pos, bool flip);//,int pattern);
    CImage m_img;
    float move_speed_y = 4.0f;


    bool m_flip;
    void Movepattern();
    void Update();
    void Draw();
    void Collision(Base* b);

    static TexAnimData _anim_data[];
};