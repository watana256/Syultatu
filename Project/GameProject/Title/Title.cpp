#include "Title.h"
#include "Game/Game.h"

Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 100)
{
	m_img = COPY_RESOURCE("Title", CImage);
	m_img.SetSize(1920, 1080);
}

void Title::Update()
{
	if (m_cnt++ > 60 && PUSH(CInput::eButton5)) {
		Base::KillAll();
		//Base::Add(new Game());
	}
}

void Title::Draw()
{
	m_img.SetPos(0, 0);
	m_img.Draw();
}