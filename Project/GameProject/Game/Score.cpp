#include "Score.h"

Score::Score():Base(eType_UI)
{
	m_img = COPY_RESOURCE("Score", CImage);
	m_img.SetSize(1920, 1080);
}

void Score::Draw()
{
	int score = 100;
	for (int i = 0; i < 6; i++, score /= 10) {
		int s = score % 10;
		m_img.SetRect(100 * s, 0, 100 * s + 100, 128);
		m_img.SetSize(150, 110);
		m_img.SetPos(1700 - 102 * i, 10);
    m_img.Draw();
	}
}