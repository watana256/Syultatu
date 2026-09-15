#include "Enemy.h"
Enemy::Enemy(const CVector2D& pos) :Base(eType_Enemy) {
    m_img.Load("Image/Enemy.png");
    m_pos = pos;
    m_cnt = 0;  
    m_rad = 16;
    m_img.SetSize(32, 32);
    m_img.SetCenter(16, 16);
}
void Enemy::Update()
{
    const int move_speed = 32;
    m_cnt++;
    if (m_cnt >= 30) {
        m_pos.y += move_speed;
        m_cnt = 0;
    }
    if (m_pos.y > 1080) {
        SetKill();
    }
}
void Enemy::Draw()
{
    m_img.SetPos(m_pos);
    m_img.Draw();
    Utility::DrawCircle(m_pos, m_rad, CVector4D(0, 0, 1, 0.5));
}