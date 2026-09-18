#include "Enemy.h"
#include "Player.h"
#include "Score.h"
static TexAnim _idle[] = {
    { 0,2 },
    { 1,2 },
    { 2,2 },
    { 3,2 },
    { 4,2 },
};
TexAnimData Enemy::_anim_data[] = {
    ANIMDATA(_idle)
};
Enemy::Enemy(const CVector2D& pos,bool flip,int movetype, float Speed_x, float Speed_y) :Base(eType_Enemy) {
    m_img.Load("Image/Enemy.png");
    m_pos = pos;
    m_flip = flip;
    m_rad = 25;
    m_img.SetSize(50, 50);
    m_img.SetCenter(25, 25);
    m_movetype= movetype;    
    m_speed_x = Speed_x;
    m_speed_y = Speed_y;
}
void Enemy::Update()
{
 // switch(movetype=2){
 switch (m_movetype) {
     case 0:
         StateMove0();
         break;
     case 1:
         StateMove1();
         break;

     case 2:
         StateMove2();
         break;
     case 22:
         StateMove22();
         break;

     case 3:
         StateMove3();
         break;
     case 30:
         StateMove30();
         break;
 }
}

// ↓敵の動きはここから

void Enemy::StateMove0() {
    if (m_pos.x <= -64) {
        SetKill();
    }
    else {
        m_pos.x -= m_speed_x;
        }
    }


void Enemy::StateMove1() {
    if (m_pos.x <= -64) {
        SetKill();
    }
    else {


        if (m_pos.y <= 150||m_pos.y >= 1000) {
            m_speed_y *= -1;
        }

        m_pos.x -= m_speed_x;
        m_pos.y -= m_speed_y;
    }
}

void Enemy::StateMove2() {
    m_speed_x = 2;
    m_pos.x -= m_speed_x;
    m_speed_y = 0;
    m_pos.y -= m_speed_y;
    if (m_pos.x <= -64) {
        SetKill();
    }
    else {

            if (m_pos.x <= 1200) {
                m_speed_y = 4;
                m_speed_x = 7;
            }

            m_pos.y -= m_speed_y;
            m_pos.x -= m_speed_x;
        }
    }

void Enemy::StateMove22() {
    m_speed_x = 2;
    m_pos.x -= m_speed_x;
    m_speed_y = 0;
    m_pos.y -= m_speed_y;
    if (m_pos.x <= -64) {
        SetKill();
    }
    else {

        if (m_pos.x <= 1200) {
            m_speed_y = -4;
            m_speed_x = 7;
        }

        m_pos.y -= m_speed_y;
        m_pos.x -= m_speed_x;
    }
}

void Enemy::StateMove3() {
    if (m_pos.y >= 2000) {
        SetKill();
    }
    else {

    m_pos.y += m_speed_y;
    m_vec.y += m_speed_y;
    }
}

void Enemy::StateMove30() {
    if (m_pos.y <= -100) {
        SetKill();
    }
    else {

        m_pos.y -= m_speed_y;
        m_vec.y -= m_speed_y;
    }
}

// 敵の動きここまで

void Enemy::Collision(Base* b)
{
    switch (b->m_type)
    {
    case eType_Player:
        // b を Player 型にキャスト
        if (Player* p = dynamic_cast<Player*>(b)) {
            // 矩形判定（または Base::CollisionCircle(this, b)）で接触判定
            if (Base::CollisionCircle(this, b)) {

                // 1. プレイヤーにダメージを与える（HP制の場合）
                p->TakeDamage(10);

                // 2. 敵自身を消去する
                SetKill();
                
            }
        }
        break;
    }
}

void Enemy::Draw()
{
    m_img.SetRect(128, 0, 192, 64);
    m_img.SetPos(GetScreenPos(m_pos));
    m_img.SetFlipH(m_flip);
    m_img.Draw();
    //Utility::DrawCircle(m_pos, m_rad, CVector4D(5, 0, 0, 0.5));
}