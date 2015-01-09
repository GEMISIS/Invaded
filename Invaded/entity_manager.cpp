#include "entity_manager.h"

EntityManager::EntityManager()
{
}

void EntityManager::Add(std::string name, Entity* entity)
{
	std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(name);
	while (found != this->entities.end())
	{
		name += "0";
		found = this->entities.find(name);
	}
	this->entities.insert(std::make_pair(name, entity));
}

void EntityManager::Update()
{
	for (auto& iterator : this->entities)
	{
		iterator.second->Update();
	}
}

void EntityManager::Render(sf::RenderWindow* window)
{
	for (auto& iterator : this->entities)
	{
		window->draw(*iterator.second);
	}
}

EntityManager::~EntityManager()
{
	this->entities.clear();
}