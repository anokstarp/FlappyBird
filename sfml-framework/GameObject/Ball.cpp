#include "stdafx.h"
#include "Ball.h"

Ball::Ball(const std::string n)
	:GameObject(n), ballDir(0.3f, 0.3f)
{
}

Ball::~Ball()
{
	Release();
}

void Ball::SetPosition(const sf::Vector2f& p)
{
	position = p;
	ball.setPosition(p);
}

void Ball::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	ball.setPosition(position);
}

void Ball::SetOrigin(Origins origin)
{
	GameObject::SetOrigin(origin);
	if (this->origin != Origins::CUSTOM)
	{
		Utils::SetOrigin(ball, origin);
	}
}

void Ball::SetOrigin(float x, float y)
{
	GameObject::SetOrigin(x, y);
	ball.setOrigin(x, y);
}
void Ball::Init()
{
}

void Ball::Release()
{
}

void Ball::Reset()
{
}

void Ball::Update(float dt)
{
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(ball);
}

void Ball::SetRadius(float rad)
{
	ball.setRadius(rad);
}

float Ball::GetRadius() const
{
	return ball.getRadius();
}

void Ball::SetDir(sf::Vector2f dir)
{
	ballDir = dir;
}

void Ball::SetDir(float xDir, float yDir)
{
	ballDir.x = xDir;
	ballDir.y = yDir;
}

void Ball::ReverseDirX()
{
	ballDir.x = -ballDir.x;
}

void Ball::ReverseDirY()
{
	ballDir.y = -ballDir.y;
}

void Ball::MoveBall()
{
	ball.move(ballDir);
}

sf::Vector2f Ball::GetDir()
{
	return ballDir;
}

sf::FloatRect Ball::GetGlobalBounds()
{
	return ball.getGlobalBounds();
}
