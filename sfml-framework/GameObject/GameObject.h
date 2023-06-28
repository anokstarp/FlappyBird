#pragma once
#include "stdafx.h"

class GameObject
{
protected:
	sf::Vector2f position;
	std::string name;
	bool isActive = true;	// 활성화: Update(), Draw()
	Origins origin;

public:

	int sortLayer = 0;
	int sortOrder = 0;

	GameObject(const std::string n = "");
	virtual ~GameObject();

	bool GetActive() const;
	void SetActive(bool active);

	std::string GetName();
	virtual void SetName(const std::string& n);

	sf::Vector2f GetPosition();

	virtual void SetPosition(float x, float y);
	virtual void SetPosition(const sf::Vector2f& p);

	virtual void SetOrigin(Origins origin);
	virtual void SetOrigin(float x, float y);

	virtual void Init() = 0;	//생성자 역할
	virtual void Release() {};	//소멸자 역할
	virtual void Reset() = 0;	//초기화

	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};