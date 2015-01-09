#pragma once

#include <unordered_map>
#include <vector>

#include "entity.h"

class EntityManager
{
public:
	EntityManager();

	void Add(std::string name, Entity* entity);
	Entity* Get(std::string name);

	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);

	~EntityManager();
private:
	std::unordered_map<std::string, Entity*> entities;
};