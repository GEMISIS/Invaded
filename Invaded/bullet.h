#pragma once

#include "entity.h"
#include "score.h"
#include "lives.h"

extern int ammo;
extern int playerAmmo;
extern int enemyCount;

class Bullet : public Entity
{
public:
	Bullet(Lives* lives, float x, float y, float direction, bool good);
	Bullet(Score* score, float x, float y, float direction, bool good);
	void Update(sf::RenderWindow* window);
	void Collision(Entity* entity);
private:
	Score* score;
	Lives* lives;
};