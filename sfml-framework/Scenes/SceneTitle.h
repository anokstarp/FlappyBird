#pragma once
#include "Scene.h"
#include "Block.h"
#include "Ball.h"
#include "TextGo.h"

class SceneTitle : public Scene
{
protected:
	sf::Vector2f screenSize;

	float ySpeed;
	float gravity;
	float jumpForce;
	float blockSpeed;


public:
	SceneTitle();
	virtual ~SceneTitle() override = default;

	virtual void Init() override;
	virtual void Release() override;

	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void JumpPlayer(float dt);
	void MoveBlock(float dt);
	void ResetBlock();
};

