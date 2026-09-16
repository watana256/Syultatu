#include "Player.h"


static TexAnim _Right[] =
{
    { 0,2 },
    { 1,2 }
};
static TexAnim _left[] =
{
    { 3,2 },
    { 4,2 }
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

Player::Player(const CVector2D& pos) :Base(eType_Player)
{
	m_img = COPY_RESOURCE("Player", CImage);
    m_pos_old = m_pos = pos;
    m_img.SetSize(80, 80);
    m_img.SetCenter(40, 40);
    m_img.ChangeAnimation(eState_Stillness);
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
    /*const int move_speed = 4;
    if (HOLD(CInput::eUp)) {
        m_pos.y -= move_speed;
    }
    if (HOLD(CInput::eDown)) {
        m_pos.y += move_speed;
    }
    if (PUSH(CInput::eButton1)) {
        //new Bullet(m_pos);
    }*/
    

}
void Player::Draw()
{
    m_img.SetPos(m_pos);
	m_img.Draw();
	//DrawRect();
}
void Player::StateStillness()
{
    const int move_speed = 4;
    if (HOLD(CInput::eUp)) {
        m_pos.y -= move_speed;
        m_state = eState_Right;
    }
    if (HOLD(CInput::eDown)) {
        m_pos.y += move_speed;
        m_state = eState_left;
    }
    if (PUSH(CInput::eButton1)) {
        //new Bullet(m_pos);
    }
    else {
        m_img.ChangeAnimation(eAnimStillness);
    }
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
