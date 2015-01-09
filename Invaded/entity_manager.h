#pragma once

#include <unordered_map>

#include "entity.h"

class EntityManager
{
public:
	EntityManager();

	void Add(std::string name, Entity* entity);

	void Update();
	void Render(sf::RenderWindow* window);

	~EntityManager();
private:
	std::unordered_map<std::string, Entity*> entities;
};