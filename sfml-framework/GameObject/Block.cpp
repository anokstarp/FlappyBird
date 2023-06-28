#include "stdafx.h"
#include "Block.h"

Block::Block(const std::string n)
	:GameObject(n), blockState(1)
{
	block.setSize({ 45.f, 45.f });
}

Block::~Block()
{
	Release();
}

void Block::SetPosition(const sf::Vector2f& p)
{
	position = p;
	block.setPosition(p);
}

void Block::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	block.setPosition(position);
}

void Block::SetOrigin(Origins origin)
{
	GameObject::SetOrigin(origin);
	if (this->origin != Origins::CUSTOM)
	{
		Utils::SetOrigin(block, origin);
	}
}

void Block::SetOrigin(float x, float y)
{
	GameObject::SetOrigin(x, y);
	block.setOrigin(x, y);
}

void Block::Init()
{
}

void Block::Release()
{
}

void Block::Reset()
{
}

void Block::Update(float dt)
{
}

void Block::Draw(sf::RenderWindow& window)
{
	window.draw(block);
}

void Block::SetSize(sf::Vector2f size)
{
	block.setSize(size);
}

void Block::SetSize(float xSize, float ySize)
{
	block.setSize({ xSize, ySize });
}

void Block::SetFillColor(sf::Color color)
{
	block.setFillColor(color);
}

sf::FloatRect Block::GetGlobalBounds()
{
	return block.getGlobalBounds();
}

int Block::CheckCollision(sf::FloatRect ballRect)
{
	if (blockState == 1)
	{
		return CheckCollisionState_1(ballRect);
	}
	else if (blockState == 2)
	{
		return CheckCollisionState_2(ballRect);
	}
	
	 
}

int Block::CheckCollisionState_1(sf::FloatRect ballRect)
{
	sf::FloatRect intersect;
	sf::FloatRect blockRect = block.getGlobalBounds();

	float ballVerticalMid = ((ballRect.left * 2) + ballRect.width) * 0.5f;
	float ballHorizontalMid = ((ballRect.top * 2) + ballRect.height) * 0.5f;

	float blockVerticalMid = ((blockRect.left * 2) + blockRect.width) * 0.5f;
	float blockHorizontalMid = ((blockRect.top * 2) + blockRect.height) * 0.5f;


	//intersect에 겹치는 부분의 rect가 들어온다
	if (blockRect.intersects(ballRect, intersect))
	{
		if (intersect.width < intersect.height) //높이가 넓이보다 클 때 == 옆에서 부딪힘
		{	
			if (ballVerticalMid > blockVerticalMid) //가운데 수직선 기준으로 블록보다 오른쪽 == 오른쪽에서 부딪힘
			{
				block.setFillColor(sf::Color::Red);
				return 1;
			}
			else //왼쪽에서 부딪힘
			{
				block.setFillColor(sf::Color::Green);
				return 2;
			}
		}
		else //넓이가 높이보다 클 때 == 위아래서 부딪힘
		{
			if (ballHorizontalMid > blockHorizontalMid) //가운데 수평선 기준으로 블록보다 아래 == 아래에서 부딪힘
			{
				block.setFillColor(sf::Color::Magenta);
				return 3;
			}
			else //위에서 부딪힘
			{
				block.setFillColor(sf::Color::Yellow);
				return 4;
			}
		}
	}
	return 0;
}

//바닥 뚫려야됨
int Block::CheckCollisionState_2(sf::FloatRect ballRect)
{
	sf::FloatRect intersect;
	sf::FloatRect blockRect = block.getGlobalBounds();

	float ballVerticalMid = ((ballRect.left * 2) + ballRect.width) * 0.5f;
	float ballHorizontalMid = ((ballRect.top * 2) + ballRect.height) * 0.5f;

	float blockVerticalMid = ((blockRect.left * 2) + blockRect.width) * 0.5f;
	float blockHorizontalMid = ((blockRect.top * 2) + blockRect.height) * 0.5f;

	//intersect에 겹치는 부분의 rect가 들어온다
	if (blockRect.intersects(ballRect, intersect))
	{
		if (ballRect.top + ballRect.height <= blockRect.top)
		{
			return 5;
		}
		if (ballRect.top + ballRect.height > blockRect.top)
		{
			block.setFillColor(sf::Color::Blue);
			return 6;
		}
	}
	return 0;
}

int Block::GetBlockState()
{
	return blockState;
}

void Block::SetBlockState(int state)
{
	blockState = state;
}
