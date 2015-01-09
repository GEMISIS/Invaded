#pragma once

#include "entity_manager.h"
#include "score.h"

extern int playerAmmo;
extern int ammo;
extern bool gameOver;

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