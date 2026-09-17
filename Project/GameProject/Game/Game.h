#pragma once
#include "../Base/Base.h"

class Game : public Base {
private:
	CImage m_BackGround;
	int m_cnt;
public:
	Game();
	~Game();
	void Update();
	int m_step;
	void Draw();
};