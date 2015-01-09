#pragma once

#include "entity_manager.h"
#include "score.h"

extern int ammo;

class Ship : public Entity
{
public:
	Ship(Score* score, EntityManager* manager, float x, float y);
	void Update(sf::RenderWindow* window);
	void Collision(Entity* entity);
private:
	EntityManager* manager;
	Score* score;
	bool space;
};