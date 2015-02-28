#pragma once

#include "entity.h"
#include "entity_manager.h"
#include "lives.h"

extern float direction;
extern int ammo;

class Enemy : public Entity
{
public:
	Enemy(Lives* lives, EntityManager* manager, float x, float y, int difficulty = 0);
	void Update(sf::RenderWindow* window);
	void Collision(Entity* entity);
private:
	float direction;
	EntityManager* manager;
	Lives* lives;
	float yTraveled;
	float maxYTravel;
};