#include "Bullet.h"
#include "Score.h"

Bullet::Bullet(const CVector2D& pos) :Base(eType_Bullet)
{
    m_img.Load("Image/Bullet.png");
    m_pos = pos;
    m_rad = 16;
    m_img.SetSize(32, 32);
    m_img.SetCenter(16, 16);

}
void Bullet::Update()
{
    const int move_speed = 16;
    m_pos.x += move_speed;
    if (m_pos.x > 1900) {
        SetKill();
    }
}
void Bullet::Draw()
{
    m_img.SetPos(m_pos);
    m_img.Draw();
    Utility::DrawCircle(m_pos, m_rad, CVector4D(0, 5, 0, 0.5));
}
void Bullet::Collision(Base* b)
{
    switch (b->GetType()) {
    case eType_Enemy:
        if (Base::CollisionCircle(this, b))
        {
            b->SetKill();
            SetKill();
            Score::s_score += 100;
        }
        break;
    }
}