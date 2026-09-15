#pragma once
#include "../Base/Base.h"

class Player : public Base
{
private:
	enum {
		eStae_Right,
		eStae_left,
		eStae_stillness
	};
	CImage m_img;

	void StateMove();

public:
	Player(const CVector2D& pos);
	static TexAnimData _anim_data[];
	void Update();
	void Draw();
};