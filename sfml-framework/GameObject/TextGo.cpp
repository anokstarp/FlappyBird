#include "stdafx.h"
#include "TextGo.h"
#include "Utils.h"
#include "ResourceMgr.h"

TextGo::TextGo(const std::string n, const std::string rId)
	: GameObject(n), resourceId(rId)
{
}

TextGo::~TextGo()
{
}

void TextGo::SetPosition(const sf::Vector2f& p)
{
	position = p;
	text.setPosition(p);
}

void TextGo::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	text.setPosition(position);
}

void TextGo::SetOrigin(Origins origin)
{
	Utils::SetOrigin(text, origin);

	if (this->origin != Origins::CUSTOM)
	{
		Utils::SetOrigin(text, origin);
	}
}

void TextGo::SetOrigin(float x, float y)
{
	GameObject::SetOrigin(x, y);
	text.setOrigin(x, y);
}

void TextGo::Init()
{
}

void TextGo::Release()
{
}

void TextGo::Reset()
{
	auto font = RESOURCE_MGR.GetFont(resourceId);
	if (font != nullptr)
	{
		text.setFont(*font);
	}
}

void TextGo::Update(float dt)
{
}

void TextGo::Draw(sf::RenderWindow& window)
{
	window.draw(text);
}

void TextGo::SetString(const std::string str)
{
	text.setString(str);
}

void TextGo::SetString(const char* ch)
{
	std::string str(ch);
	text.setString(str);
}

void TextGo::SetColor(sf::Color color)
{
	text.setFillColor(color);
}

void TextGo::SetCharSize(int size)
{
	text.setCharacterSize(size);
}

int TextGo::GetCharSize()
{
	return text.getCharacterSize();
}

sf::FloatRect TextGo::GetGlobalBounds()
{
	return text.getGlobalBounds();
}