#pragma once
#include "../Base/Base.h"

class Result : public Base {
public:
	CImage m_img;
	CImage m_score;
	int result;
	int m_cnt;
	Result();
	void Update();
	void Draw();
};
