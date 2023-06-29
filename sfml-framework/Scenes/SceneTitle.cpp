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
	resources.push_back(std::make_tuple(ResourceTypes::Texture, "graphics/Wall1.png"));

	screenSize = FRAMEWORK.GetWindowSize();
}

void SceneTitle::Init()
{
	Release();

	//AddGo로 gameObjects에 push_back
	AddGo(new SpriteGo("Bird"));
	
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

	SpriteGo* bird = (SpriteGo*)FindGo("Bird");
	bird->sprite.setTexture(*RESOURCE_MGR.GetTexture("graphics/Wall1.png"));
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
}

void SceneTitle::Draw(sf::RenderWindow& window)
{	
	Scene::Draw(window);
}