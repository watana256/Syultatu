#include "Enemy.h"
#include "Player.h"
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
Enemy::Enemy(const CVector2D& pos,bool flip) :Base(eType_Enemy) {
    m_img.Load("Image/Enemy.png");
    m_pos = pos;
    m_flip = flip;
    m_rad = 25;
    m_img.SetSize(50, 50);
    m_img.SetCenter(25, 25);
}
void Enemy::Movepattern()
{

}
void Enemy::Update()
{
    const int move_speed = 5;
    if (m_pos.x <= -64) {
        SetKill();
    }
    else {


    
        m_pos.x -= move_speed;
        m_pos.y += move_speed_y;

        
        if (m_pos.y >= 1000) {
            m_pos.y = 1000;
            move_speed_y *= -1;
        }
        else if (m_pos.y <= 64) {
            m_pos.y = 64;
            move_speed_y *= -1;
        }
    }
}

void Enemy::Draw()
{
    m_img.SetRect(128, 0, 192, 64);
    m_img.SetPos(GetScreenPos(m_pos));
    m_img.SetFlipH(m_flip);
    m_img.Draw();
    Utility::DrawCircle(m_pos, m_rad, CVector4D(5, 0, 0, 0.5));
}