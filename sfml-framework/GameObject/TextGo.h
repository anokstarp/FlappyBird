#pragma once
#include "GameObject.h"
class TextGo : public GameObject
{
protected:
	sf::Text text;
	std::string resourceId;

public:
	TextGo(const std::string n = "", const std::string rId = "");
	virtual ~TextGo() override;

	virtual void SetPosition(const sf::Vector2f& p);
	virtual void SetPosition(float x, float y);

	virtual void SetOrigin(Origins origin);
	virtual void SetOrigin(float x, float y);

	virtual void Init() override;
	virtual void Release() override;
	virtual void Reset() override;
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void SetString(const std::string str);
	void SetString(const char* ch);
	void SetColor(sf::Color color);
	void SetCharSize(int size);
	int GetCharSize();


	sf::FloatRect GetGlobalBounds();
};
