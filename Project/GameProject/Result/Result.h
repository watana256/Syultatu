#pragma once
#include "../Base/Base.h"

class Result : public Base {
public:
	CImage m_img;
	int result;
	int m_cnt;
	Result();
	void Update();
	void Draw();
};
