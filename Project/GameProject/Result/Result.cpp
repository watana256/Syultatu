#include "Result.h"
#include "Title/Title.h"

Result::Result():Base(eType_Scene)
{
	m_img = COPY_RESOURCE("Result", CImage);
	m_img.SetSize(1920, 1080);
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
}