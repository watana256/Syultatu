#include "Result.h"
#include "Title/Title.h"
#include "Game/Score.h"


Result::Result():Base(eType_UI)
{
	m_img = COPY_RESOURCE("Result", CImage);
	m_img.SetSize(1920, 1080);
	m_score = COPY_RESOURCE("Score", CImage);

}

void Result::Update()
{
	if (m_cnt++ > 60 && PUSH(CInput::eButton5)) {
		KillAll();
		new Title();
	}
}

void Result::Draw()
{
	m_img.Draw();
	int Resultscore = Score::s_score;
	for (int i = 0; i < 6; i++, Resultscore /= 10) {
		int r = Resultscore % 10;
		m_score.SetRect(100 * r, 0, 100 * r + 100, 128);
		m_score.SetSize(200, 200);
		m_score.SetPos(1180 - 128 * i, 415);
		m_score.Draw();
	}
}