#include "Player.h"


Player::Player(const CVector2D& pos) :Base(eType_Player)
{
	m_img = COPY_RESOURCE("Player", CImage);
    m_pos = pos;
}
void Player::Update()
{
    const int move_speed = 4;
    if (HOLD(CInput::eUp)) {
        m_pos.y -= move_speed;
    }
    if (HOLD(CInput::eDown)) {
        m_pos.y += move_speed;
    }
    if (PUSH(CInput::eButton1)) {
        //new Bullet(m_pos);
    }
    m_img.UpdateAnimation();
}
void Player::Draw()
{
    m_img.SetPos(m_pos);
	m_img.Draw();
	//DrawRect();
}

void Player::StateMove() 
{

}
