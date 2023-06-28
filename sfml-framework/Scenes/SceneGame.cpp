#include "stdafx.h"
#include "SceneGame.h"
#include "InputMgr.h"
#include "SceneMgr.h"
#include "ResourceMgr.h"
#include "SpriteGo.h"
#include "Framework.h"
#include "Block.h"

#define BLOCKS 4
#define SQUARE 30.0


SceneGame::SceneGame()
	:Scene(SceneId::Game), playerSpeed(0.1f), gravity(0.1f), jumpForce(10.f), 
	accumTime(0), ySpeed(0), countSecond(0), isJump(false)
{
	screenSize = FRAMEWORK.GetWindowSize();
}

SceneGame::~SceneGame()
{
	//Release();
}

void SceneGame::Init()
{
	Release();

	playerSpeed = 400.f;
	gravity = 3.f;
	jumpForce = 1500.f;
	accumTime = 0.f;
	ySpeed = 0;
	countSecond = 0;
	isJump = false;

	for (int i = 0; i < BLOCKS; i++)
	{
		std::string name = "Block";
		std::string num = std::to_string(i + 1);

		AddGo(new Block(name + num));
	}
	AddGo(new Block("Player"));

	for (auto go : gameObjects)
	{
		go->Init();
	}
}

void SceneGame::Release()
{
	for (auto go : gameObjects)
	{
		//go->Release();
		delete go;
	}
}

void SceneGame::Enter()
{
	Scene::Enter();


	Block* block = (Block*)FindGo("Block1");
	block->SetSize(300.f, 200.f);
	block->SetOrigin(Origins::BL);
	block->SetFillColor(sf::Color::White);
	block->SetPosition(0, screenSize.y);

	block = (Block*)FindGo("Block2");
	block->SetSize(300.f, 300.f);
	block->SetOrigin(300.f, 300.f);
	block->SetFillColor(sf::Color::White);
	block->SetPosition(screenSize.x, screenSize.y);

	block = (Block*)FindGo("Block3");
	block->SetSize(300.f, 100.f);
	block->SetOrigin(Origins::MC);
	block->SetFillColor(sf::Color::White);
	block->SetPosition(250.f, 150.f);


	block = (Block*)FindGo("Block4");
	block->SetSize(250.f, 100.f);
	block->SetOrigin(Origins::MC);
	block->SetFillColor(sf::Color::White);
	block->SetPosition(650.f, 250.f);
	block->SetBlockState(2);

	Block* player = (Block*)FindGo("Player");
	player->SetSize(SQUARE, SQUARE);
	player->SetOrigin(Origins::BC);
	player->SetFillColor(sf::Color::Cyan);
	player->SetPosition(screenSize.x * 0.5f, screenSize.y);
}

void SceneGame::Exit()
{
	Scene::Exit();
}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);

	accumTime += dt;

	MovePlayer(dt);
	CheckBlockCollision();

	if (accumTime >= 1.f / 60.f)
	{
		accumTime -= 1.f / 60.f;
	}
	

	if (INPUT_MGR.GetKeyDown(sf::Keyboard::Escape))
	{
		SCENE_MGR.ChangeScene(SceneId::Title);
	}
}

void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

void SceneGame::MovePlayer(float dt)
{
	Block* player = (Block*)FindGo("Player");
	sf::Vector2f curPos = player->GetPosition();

	if (INPUT_MGR.GetKey(sf::Keyboard::Left))
	{
		player->SetPosition(curPos.x - playerSpeed * dt, curPos.y);
	}
	if (INPUT_MGR.GetKey(sf::Keyboard::Right))
	{
		player->SetPosition(curPos.x + playerSpeed * dt, curPos.y);
	}
	if (INPUT_MGR.GetKeyDown(sf::Keyboard::X))
	{
		ySpeed = jumpForce;
		isJump = true;
	}

	curPos = player->GetPosition();

	if (isJump)
	{
		player->SetPosition(curPos.x, curPos.y - ySpeed * dt);
	}

	if (player->GetPosition().y >= screenSize.y)
	{
		player->SetPosition(player->GetPosition().x, screenSize.y);
		ySpeed = 0;
		isJump = false;
	}
	else if(isJump = true)
	{
		ySpeed -= gravity;
		if (ySpeed <= -1000) ySpeed = -1000;
	}
}

void SceneGame::CheckBlockCollision()
{
	Block* player = (Block*)FindGo("Player");
	Block* block;

	sf::Vector2f curPos = player->GetPosition();

	for (int i = 0; i < BLOCKS; i++)
	{
		std::string name = "Block";
		std::string num = std::to_string(i + 1);

		block = (Block*)FindGo(name + num);
		sf::FloatRect blockRect = block->GetGlobalBounds();

		switch (block->CheckCollision(player->GetGlobalBounds()))
		{
		case 1: //오른쪽
			player->SetPosition(blockRect.left + blockRect.width + (SQUARE * 0.5), player->GetPosition().y);
			break;
		case 2: //왼쪽
			player->SetPosition(blockRect.left - (SQUARE * 0.5), player->GetPosition().y);
			break;
		case 3: //아래
			player->SetPosition(player->GetPosition().x, blockRect.top + blockRect.height + SQUARE);
			ySpeed = -10;
			break;
		case 4: //위에
			player->SetPosition(player->GetPosition().x, blockRect.top);
			isJump = false;
			break;
		case 5:
	
			break;
		case 6:
			ySpeed = 100;
			break;
		default:
			break;
		}
	}
}
