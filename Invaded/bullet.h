#pragma once

#include "entity.h"
#include "score.h"

extern int ammo;

class Bullet : public Entity
{
public:
	Bullet(float x, float y, float direction, bool good);
	Bullet(Score* score, float x, float y, float direction, bool good);
	void Update(sf::RenderWindow* window);
	void Collision(Entity* entity);
private:
	Score* score;
};