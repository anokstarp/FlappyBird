#include "stdafx.h"
#include "SceneTitle.h"
#include "InputMgr.h"
#include "SceneMgr.h"
#include "ResourceMgr.h"
#include "SpriteGo.h"
#include "Framework.h"

#define BLOCKS 42

SceneTitle::SceneTitle()
	:Scene(SceneId::Title)
{
	//생성자에서 resources 배열에 삽입
	resources.push_back(std::make_tuple(ResourceTypes::Font, "fonts/DS-DIGI.ttf"));
	resources.push_back(std::make_tuple(ResourceTypes::Texture, "graphics/bee.png"));

	screenSize = FRAMEWORK.GetWindowSize();
}

void SceneTitle::Init()
{
	Release();

	gravity = 1.3f;
	jumpForce = 900.f;
	ySpeed = 0;
	blockSpeed = 500.f;

	//AddGo로 gameObjects에 push_back
	AddGo(new SpriteGo("Bee"));
	AddGo(new Block("BlockTop"));
	AddGo(new Block("BlockBottom"));
	
	for (auto go : gameObjects)
	{
		go->Init();
	}
}

void SceneTitle::Release()
{
	for (auto go : gameObjects)
	{
		//go->Release();
		delete go;
	}
}

void SceneTitle::Enter()
{
	Scene::Enter();

	SpriteGo* bee = (SpriteGo*)FindGo("Bee");
	bee->sprite.setTexture(*RESOURCE_MGR.GetTexture("graphics/bee.png"));
	bee->sprite.setScale(-1.f, 1.f);
	bee->SetPosition(screenSize.x * 0.3f, screenSize.y * 0.5f);

	Block* block = (Block*)FindGo("BlockTop");
	block->SetSize(100.f, 300.f);
	block->SetOrigin(Origins::TC);
	block->SetPosition(screenSize.x, 0);

	block = (Block*)FindGo("BlockBottom");
	block->SetSize(100.f, 150.f);
	block->SetOrigin(Origins::BC);
	block->SetPosition(screenSize.x, screenSize.y);
}

void SceneTitle::Exit()
{
	Scene::Exit();
}

void SceneTitle::Update(float dt)
{
	Scene::Update(dt);

	if (INPUT_MGR.GetKeyDown(sf::Keyboard::Escape))
	{
		SCENE_MGR.ChangeScene(SceneId::Game);
	}

	MoveBlock(dt);
	JumpPlayer(dt);
}

void SceneTitle::Draw(sf::RenderWindow& window)
{	
	Scene::Draw(window);
}

void SceneTitle::JumpPlayer(float dt)
{
	if (INPUT_MGR.GetKeyDown(sf::Keyboard::Space))
	{
		ySpeed = jumpForce;
	}
	SpriteGo* bee = (SpriteGo*)FindGo("Bee");
	sf::Vector2f curPos = bee->GetPosition();

	bee->SetPosition(curPos.x, curPos.y - ySpeed * dt);

	ySpeed -= gravity;
	if (ySpeed <= -800) ySpeed = -800;
}

void SceneTitle::MoveBlock(float dt)
{
	Block* block = (Block*)FindGo("BlockTop");
	sf::Vector2f blockPos = block->GetPosition();
	block->SetPosition(blockPos.x - blockSpeed * dt, blockPos.y);
	
	block = (Block*)FindGo("BlockBottom");
	blockPos = block->GetPosition();
	block->SetPosition(blockPos.x - blockSpeed * dt, blockPos.y);

	if (blockPos.x <= -200.f)
	{
		ResetBlock();
	}
}

void SceneTitle::ResetBlock()
{
	int rnd = Utils::RandomRange(1, 10);
	float size = 650.f;
	size = 650.f - (rnd * 60.f);

	Block* block = (Block*)FindGo("BlockTop");
	block->SetSize(100.f, rnd * 40.f);
	block->SetOrigin(Origins::TC);
	block->SetPosition(screenSize.x, 0);
	
	block = (Block*)FindGo("BlockBottom");
	block->SetSize(100.f, size);
	block->SetOrigin(Origins::BC);
	block->SetPosition(screenSize);

}
