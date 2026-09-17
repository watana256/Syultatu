#include "Base/Base.h"
#include "Game/Player.h"
#include "Game/Enemy.h"
#include "Game/HP.h"
#include "Game/Game.h"
#include "Result/Result.h"
#include "Title/Title.h"

Game::Game():Base(eType_Scene)
	,m_step(0)
	
{
	m_BackGround = COPY_RESOURCE("BackGround", CImage);
	m_BackGround.SetSize(1920, 1080);
}

Game::~Game()
{
}

void Game::EnemyArmy()
{
	// 縦　行　　横　列

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			int offsetY = rand() % 300;
			new Enemy(CVector2D(1900 + (80 * j), 400 + (32 * i) + offsetY), true, 0);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			int offsetY = rand() % 800;
			new Enemy(CVector2D(1900 + (80 * j), 300 + (32 * i) + offsetY), true, 1);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			int offsetY = rand() % 800;
			new Enemy(CVector2D(1900 + (80 * j), 700 + (32 * i) + offsetY), true, 2);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			int offsetY = rand() % 500;
			new Enemy(CVector2D(900 + (80 * j), -1000 + (32 * i) + offsetY), true, 3);
		}
	}
}

void Game::Update()
{
	switch (m_step)
	{
	case 0:// ゲーム開始する
		   // PlayerやEnemyの出現
	{
		new Player(CVector2D(72, 800));
		new HP();
		EnemyArmy();
		m_step++;
	}
	case 1:// 全ての機体が消えたらリザルトへ
	{

	}

	}
				
	if (m_cnt++ > 60 && PUSH(CInput::eButton5)) {
 		Base::KillAll();
		new Result();
	}
}

void Game::Draw()
{
	m_BackGround.Draw();
}