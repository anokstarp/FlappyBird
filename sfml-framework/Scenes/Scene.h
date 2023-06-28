#pragma once

class GameObject;

class Scene
{
protected:
	SceneId sceneId;

	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;

	std::list<GameObject*> gameObjects;
	std::vector<std::tuple<ResourceTypes, std::string>> resources;

public:
	Scene(SceneId id = SceneId::None);
	virtual ~Scene();

	GameObject* FindGo(const std::string& name);
	void FindGos(std::list<GameObject*>& list, const std::string& name);
	bool Exist(GameObject* go);
	void AddGo(GameObject* go);
	void RemoveGo(GameObject* go);
	void SortGos();

	virtual void Init() = 0;
	virtual void Release();

	virtual void Enter();
	virtual void Exit();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);
};

