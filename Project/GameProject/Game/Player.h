#pragma once
#include "../Base/Base.h"

class Player : public Base
{
private:
	enum {
		eState_Right,
		eState_left,
		eState_Stillness
	};
	int m_state;
	CImage m_img;

	enum {
		eAnimRight,
		eAnimleft,
		eAnimStillness,
	};
	void StateStillness();
	void StateRight();
	void Stateleft();

public:
	Player(const CVector2D& pos);
	static TexAnimData _anim_data[];
	void Update();
	void Draw();
};