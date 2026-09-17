#pragma once
#include "../Base/Base.h"

class Result : public Base {
public:
	CImage m_img;
	int result;
	int m_cnt;
	Result(const CVector2D& p);
	void Update();
	void Draw();
};
