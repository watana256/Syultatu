#pragma once
#include "../Base/Base.h"

class Game : public Base {
private:
	CImage m_BackGround;
	int m_cnt;
	int m_score;
public:
	Game();
	~Game();
	void EnemyArmy();
	void Update();
	int m_step;
	void Draw();
};