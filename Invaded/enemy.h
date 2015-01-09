#pragma once

#include "entity.h"
#include "entity_manager.h"

extern float direction;
extern int ammo;

class Enemy : public Entity
{
public:
	Enemy(EntityManager* manager, float x, float y);
	void Update(sf::RenderWindow* window);
	void Collision(Entity* entity);
private:
	EntityManager* manager;
};