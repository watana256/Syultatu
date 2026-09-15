#include "Title.h"
#include "Game/Game.h"

Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 100)
{
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

}