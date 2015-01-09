#pragma once

#include "entity.h"
#include "entity_manager.h"
#include "lives.h"

extern float direction;
extern int ammo;

class Enemy : public Entity
{
public:
	Enemy(Lives* lives, EntityManager* manager, float x, float y);
	void Update(sf::RenderWindow* window);
	void Collision(Entity* entity);
private:
	EntityManager* manager;
	Lives* lives;
};