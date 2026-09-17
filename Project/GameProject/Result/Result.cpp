#pragma once
#include "../Base/Base.h"

class Result : public Base {
public:
	static int p;
	static int g1;
	static int g2;
	static int m;
	CImage m_perfect;
	CImage m_great;
	CImage m_good;
	CImage m_miss;
	CImage m_img;
	CImage m_screen;
	CImage m_Onp;
	CImage m_eva;
	int result;
	int m_cnt;
	Result(const CVector2D& p);
	void Update();
	void Draw();
};