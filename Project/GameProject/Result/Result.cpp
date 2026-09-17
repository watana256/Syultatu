#include "Result.h"
#include "Title/Title.h"

Result::Result(const CVector2D& p):Base(eType_Scene)
{
	m_img = COPY_RESOURCE("", CImage);
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
	
}