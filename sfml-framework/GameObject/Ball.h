#pragma once
#include "GameObject.h"

class Ball : public GameObject
{
protected:
	sf::CircleShape ball;
	sf::Vector2f ballDir;

public:
	Ball(const std::string n = "");
	virtual ~Ball();

	virtual void SetPosition(const sf::Vector2f& p);
	virtual void SetPosition(float x, float y);

	virtual void SetOrigin(Origins origin);
	virtual void SetOrigin(float x, float y);

	virtual void Init() override;
	virtual void Release() override;
	virtual void Reset() override;
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void SetRadius(float rad);
	float GetRadius() const;
	void SetDir(sf::Vector2f dir);
	void SetDir(float xDir = 0, float yDir = 0);

	void ReverseDirX();
	void ReverseDirY();
	void MoveBall();

	sf::Vector2f GetDir();

	sf::FloatRect GetGlobalBounds();
};