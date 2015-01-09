#include "enemy.h"
#include "bullet.h"

float direction = 0.75f;
int ammo = 5;

Enemy::Enemy(EntityManager* manager, float x, float y)
{
	this->active = 1;
	this->groupId = 2;
	this->Load("ship.png");
	this->setColor(sf::Color::Red);

	this->setPosition(x - this->getGlobalBounds().width / 2, y - this->getGlobalBounds().height / 2);

	this->manager = manager;
}

void Enemy::Update(sf::RenderWindow* window)
{
	if (ammo > 0)
	{
		int chance = rand() % 100 + 1;
		if (chance < 2)
		{
			this->manager->Add("bullet", new Bullet(this->getPosition().x, this->getPosition().y + 32, 1, false));
			ammo -= 1;
		}
	}

	if (this->velocity.x != direction)
	{
		this->move(0, 32);
	}
	this->velocity.x = direction;

	Entity::Update(window);
	if (this->getPosition().x <= 0 || this->getPosition().x + this->getGlobalBounds().width >= window->getSize().x)
	{
		direction *= -1;
		this->velocity.x = direction;

		this->move(0, 32);
		Entity::Update(window);
		Entity::Update(window);
	}
}

void Enemy::Collision(Entity* entity)
{
}