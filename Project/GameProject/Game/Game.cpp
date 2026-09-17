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


	// Enemy P0
	
	// ?:敵の出てくるスピードどうしたら？
	// ?:速度変化をつけ方不明　速度をパターンが固定の場合、新しいパターンを用いる
	// ?:ランダムな場合、もうよくわからんから3年生頼れアホ(笑)(笑)(笑)(笑)(笑)

	// !:新しいパターンを作った場合、EnemyのSwitch文にも加えてね
	// !:新しいパターンを作る場合、10 20とする

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(1900 + (80 * j), 400 + (32 * i)), true, 0);
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(2300 + (80 * j), 600 + (32 * i)), true, 0);
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(2700 + (80 * j), 500 + (32 * i)), true, 0);
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(3100 + (80 * j), 200 + (32 * i)), true, 0);
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(3700 + (80 * j), 800 + (32 * i)), true, 0);
		}
	}


	// Enemy P1
	// 上下に動くやつ

	// !:新しいパターンを作る場合、11 21とする
	// ?:もし速度変化をする場合は、P0参照 Y軸も同様

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(1900 + (80 * j), 300 + (32 * i)), true, 1);
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(2300 + (80 * j), 800 + (32 * i)), true, 1);
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(2700 + (80 * j), 500 + (32 * i)), true, 1);
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(3100 + (80 * j), 400 + (32 * i)), true, 1);
		}
	}

	// Enemy P2
	// 途中で向きとスピードが変わるやつ


	// ?:移動の速度変化は必要か
	

	//　下から上に

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(1900 + (80 * j), 800 + (32 * i)), true, 2);
		}
	}

	//　上から下に

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(2300 + (80 * j), 200 + (32 * i)), true, 22);
		}
	}

	//　下から上に

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(2700 + (80 * j), 800 + (32 * i)), true, 2);
		}
	}

	//　上から下に

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(3100 + (80 * j), 200 + (32 * i)), true, 22);
		}
	}

	// Enemy P3
	// 敵が降りてくる
	
	// !:新しいパターンを作る場合、13 23とする
 
	// ?:敵が降りてくるのは固定でいいのか？
	// ?:団体か、個別か　話す

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			new Enemy(CVector2D(900 + (80 * j), -100 + (32 * i)), true, 3);
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