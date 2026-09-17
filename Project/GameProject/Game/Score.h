#pragma once
#include "../Base/Base.h"

class Score : public Base {
public:
    CImage m_img;
    int m_score;
    CFont* m_font;
public:
    Score();
    void Draw();
};
