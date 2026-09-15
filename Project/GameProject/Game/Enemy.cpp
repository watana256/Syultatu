#include "Enemy.h"
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
    m_cnt = 0;  
    m_rad = 40;
    m_img.SetSize(80, 80);
    m_img.SetCenter(40, 40);
}
void Enemy::Update()
{
    const int move_speed = 32;
    m_cnt++;
    if (m_cnt >= 30) {
        m_pos.x -= move_speed;
        m_cnt = 0;
    }
    if (m_pos.y > 1080) {
        SetKill();
    }
}
void Enemy::Draw()
{
    m_img.SetPos(m_pos);
    m_img.SetRect(128, 0, 192, 64);
    m_img.Draw();
    Utility::DrawCircle(m_pos, m_rad, CVector4D(0, 0, 1, 0.5));
}