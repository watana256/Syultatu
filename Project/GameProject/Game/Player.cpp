#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Effect.h"

#define MUTEKI 1.0f

static TexAnim _Right[] =
{
    { 0,2 },
};
static TexAnim _left[] =
{
    { 3,2 },
};
static TexAnim _stillness[] =
{
    { 2,2 }
};

TexAnimData Player::_anim_data[] =
{
    ANIMDATA(_Right),
    ANIMDATA(_left),
    ANIMDATA(_stillness)
};

Player::Player(const CVector2D& pos) 
    :Base(eType_Player)
    , m_muteki_cnt(0)
{
	m_img = COPY_RESOURCE("Player", CImage);
    m_pos_old = m_pos = pos;
    m_img.SetSize(80, 80);
    m_img.SetCenter(40, 40);
    m_rad = 30;
    m_img.ChangeAnimation(eState_Stillness);
    m_hp = 100;
}


void Player::TakeDamage(int damage)
{
    if (m_muteki_cnt > 0) return;
    //HPå∏è≠ÅBâ∫å¿0
    m_hp = max(m_hp - damage, 0);
    m_muteki_cnt = MUTEKI;
    if (m_hp <= 0) {
        SetKill();
        new Effect(m_pos);
        SOUND("SE_Explosion")->Play();
    }

}


void Player::Update()
{
    m_img.UpdateAnimation();
    m_pos_old = m_pos;
    switch (m_state) {
    case eState_Stillness:
            StateStillness();
            break;
    case eState_Right:
        StateRight();
            break;
    case eState_left:
        Stateleft();
        break;

    }
    if (m_muteki_cnt > 0.0f)
    {
        m_muteki_cnt -= CFPS::GetDeltaTime();
    }

    if (m_pos.y < 130) {
        m_pos.y = 130;
    }
    if (m_pos.y >   1000) {
        m_pos.y =   1000;
    }
}
void Player::Draw()
{
    m_img.SetPos(m_pos);
	m_img.Draw();
	DrawRect();
    m_img.SetRect(128, 0, 192, 64);
    //Utility::DrawCircle(m_pos, m_rad, CVector4D(0, 0, 1, 0.5));
}

void Player::StateStillness()
{
    int Animu = eAnimStillness;
    const int move_speed = 4;

    if (PUSH(CInput::eButton1)) 
    {
        new Bullet(m_pos);
        SOUND("SE_Bullet")->Play();
    }
    if (HOLD(CInput::eUp)) 
    {
        m_pos.y -= move_speed;
        Animu = eAnimRight;
    }
    else if (HOLD(CInput::eDown)) 
    {
        m_pos.y += move_speed;
        Animu = eAnimleft;
    }
    m_img.ChangeAnimation(Animu);
}
void Player::StateRight() 
{
    m_img.ChangeAnimation(eAnimRight, false);
    if (m_img.CheckAnimationEnd()) {
        m_img.ChangeAnimation(eAnimRight, false);
        m_state = eState_Stillness;
    }
}
void Player::Stateleft()
{
    m_img.ChangeAnimation(eAnimleft, false);
    if (m_img.CheckAnimationEnd()) {
        m_img.ChangeAnimation(eAnimleft, false);
        m_state = eState_Stillness;
    }
}
