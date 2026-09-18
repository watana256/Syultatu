#include "Base/Base.h"
#include "Game/Player.h"
#include "Game/Enemy.h"
#include "Game/HP.h"
#include "Game/Score.h"
#include "Game/Game.h"
#include "Result/Result.h"
#include "Title/Title.h"

#define RESULT_TIME 31.0f

Game::Game():Base(eType_Scene)
	,m_step(0)
	,m_cnt(0)
	,m_deathCnt(0)
	
{
	m_BackGround = COPY_RESOURCE("BackGround", CImage);
	m_BackGround.SetSize(1920, 1080);
}

Game::~Game()
{
}

void Game::EnemyArmy()
{
	// 縦i　行　　横j　列

	// Enemy P0
	
	// ?:敵の出てくるスピードどうしたら？
	// ?:速度変化をつけ方不明　速度をパターンが固定の場合、新しいパターンを用いる
	// ?:ランダムな場合、もうよくわからんから3年生頼れアホ(笑)(笑)(笑)(笑)(笑)

	// !:新しいパターンを作った場合、EnemyのSwitch文にも加えてね
	// !:新しいパターンを作る場合、10 20とする

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(1900 + (80 * j), 400 + (32 * i)), true, 0, 3.0, 0.0);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(2500 + (80 * j), 700 + (32 * i)), true, 0, 3.5, 0.0);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(2500 + (80 * j), 300 + (32 * i)), true, 0, 3.5, 0.0);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(3100 + (80 * j), 500 + (32 * i)), true, 0, 4.0, 0.0);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(3700 + (80 * j), 500 + (32 * i)), true, 0, 4.0, 0.0);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(4300 + (80 * j), 800 + (32 * i)), true, 0, 4.5, 0.0);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(5000 + (80 * j), 500 + (32 * i)), true, 0, 4.6, 0.0);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(5700 + (80 * j), 300 + (32 * i)), true, 0, 5.0, 0.0);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(6400 + (80 * j), 600 + (32 * i)), true, 0, 5.0, 0.0);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(7100 + (80 * j), 500 + (32 * i)), true, 0, 4.6, 0.0);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(7800 + (80 * j), 300 + (32 * i)), true, 0, 5.0, 0.0);
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			new Enemy(CVector2D(8400 + (80 * j), 300 + (32 * i)), true, 0, 5.0, 0.0);
		}
	}

	// Enemy P1
	// 上下に動くやつ

	// !:新しいパターンを作る場合、11 21とする
	// ?:もし速度変化をする場合は、P0参照 Y軸も同様

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(2500 + (80 * j), 300 + (32 * i)), true, 1, 2.5, 4.0);
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(3400 + (80 * j), 800 + (32 * i)), true, 1, 3.25, 4.0);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(4300 + (80 * j), 800 + (32 * i)), true, 1, 3.5, 4.0);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(4300 + (80 * j), 300 + (32 * i)), true, 1, 3.5, 4.0);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 1; j++) {
			new Enemy(CVector2D(5200 + (80 * j), 400 + (32 * i)), true, 1, 4.5, 4.0);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(6100 + (80 * j), 800 + (32 * i)), true, 1, 5.0, 4.0);
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(6900 + (80 * j), 400 + (32 * i)), true, 1, 4.5, 4.0);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(7800 + (80 * j), 800 + (32 * i)), true, 1, 5.0, 4.0);
		}
	}


	// Enemy P2
	// 途中で向きとスピードが変わるやつ


	// ?:移動の速度変化は必要か
	

	//　下から上に

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(2300 + (80 * j), 800 + (32 * i)), true, 2, 4.0, 0.0);
		}
	}

	//　上から下に

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(3200 + (80 * j), 200 + (32 * i)), true, 22, 4.0, 0.0);
		}
	}

	//　下から上に

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(3800 + (80 * j), 800 + (32 * i)), true, 2, 5.0, 0.0);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(3800 + (80 * j), 200 + (32 * i)), true, 22, 5.0, 0.0);
		}
	}

	//　上から下に こいつを基準に

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(4600 + (80 * j), 200 + (32 * i)), true, 22, 6.0, 0.0);
		}
	}

	//　下から上に

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(5400 + (80 * j), 800 + (32 * i)), true, 2, 5.0, 0.0);
		}
	}

	//　上から下に こいつを基準に

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(6000 + (80 * j), 200 + (32 * i)), true, 22, 6.0, 0.0);
		}
	}

	// Enemy P3
	// 敵が降りてくる
	
	// !:新しいパターンを作る場合、13 23とする
 
	// ?:敵が降りてくるのは固定でいいのか？

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(900 + (80 * j), -1000 + (32 * i)), true, 3, 0.0, 2.0);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(1300 + (80 * j), -2000 + (32 * i)), true, 3, 0.0, 2.0);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			new Enemy(CVector2D(500 + (80 * j), 3000 + (32 * i)), true, 30, 0.0, 2.0);
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(900 + (80 * j), -5000 + (32 * i)), true, 3, 0.0, 4.0);
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
		break;
	}
	case 1:// リザルトへ
	{
		if (Base* player = Base::FindObject(eType_Player))
		{
			if (m_cnt > RESULT_TIME)
			{
				Base::KillAll();
				new Result();
				break;
			}
		}
		else
		{
			if (m_deathCnt > 1.3f)
			{
				Base::KillAll();
				new Result();
				break;
			}
			m_deathCnt += CFPS::GetDeltaTime();
		}
	}
	}
	m_cnt += CFPS::GetDeltaTime();
}

void Game::Draw()
{
	/*int score = GameData::s\_score; for (int i = 0; i & lt; 8; i++, score /= 10) 
	{
		int s = score % 10;
		m_img.SetRect(16  * s, 16, 16  * s + 16, 32); m_img.SetSize(16, 16); m_img.SetPos(200 - 16  * i, 0);
		m_img.Draw();*/
	m_BackGround.Draw();
}