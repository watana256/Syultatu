#include "Game.h"
#include "Result/Result.h"

Game::Game():Base(eType_Scene)
	,m_step(0)
	
{
}

Game::~Game()
{
}

void Game::Update()
{
	switch (m_step)
	{
	case 0:// ゲーム開始する
		   // PlayerやEnemyの出現
	{
		m_step++;
	}
	case 1:// 全ての機体が消えたらリザルトへ
	{

	}

	}
				
	/*if (m_cnt++ > 60 && PUSH(CInput::eButton5)) {
 		Base::KillAll();
		new Result();
	}*/
}

void Game::Draw()
{

}