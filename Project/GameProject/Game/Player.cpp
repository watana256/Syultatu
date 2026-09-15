#include "Player.h"

Player::Player(const CVector2D& pos) :Base(eType_Player)
{
	m_img = COPY_RESOURCE("Player", CImage);
}
void Player::Update()
{

}
void Player::Draw()
{
	m_img.Draw();
	//DrawRect();
}
