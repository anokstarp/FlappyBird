#pragma once
#include "Scene.h"

class SceneGame : public Scene
{
protected:
	sf::Vector2f screenSize;
	float playerSpeed;
	float ySpeed;
	float gravity;
	float jumpForce;
	float accumTime;
	bool isJump;
	
	float countSecond;

public:
	SceneGame();
	virtual ~SceneGame() override;

	virtual void Init() override;
	virtual void Release() override;

	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void MovePlayer(float dt);
	void CheckBlockCollision();
};