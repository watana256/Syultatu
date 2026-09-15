#pragma once
#include "../Base/Base.h"


class Title : public Base {
    //画像オブジェクト
    CImage m_img;
    int m_cnt;
    //文字表示オブジェクト
    CFont m_title_text;
public:
    Title();
    void Update();
    void Draw();
};

