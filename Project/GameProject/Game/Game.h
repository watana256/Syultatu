#pragma once
#include "../Base/Base.h"

class Game : public Base {
private:
	int m_cnt;
public:
	Game();
	~Game();
	void Update();
};