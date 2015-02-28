#include "enemy.h"
#include "bullet.h"

int ammo = 5;

#define MIN_SPEED_X 1.0f
#define MAX_SPEED_X 1.5f
#define MIN_SPEED_Y 16
#define MAX_SPEED_Y 32

Enemy::Enemy(Lives* lives, EntityManager* manager, float x, float y, int difficulty)
{
	this->active = 1;
	this->groupId = 2;
	this->Load("ship.png");
	this->setColor(sf::Color::Red);

	this->setPosition(x - this->getGlobalBounds().width / 2, y - this->getGlobalBounds().height / 2);

	switch (difficulty)
	{
	case 1:
	default:
		this->direction = MIN_SPEED_X;
		this->maxYTravel = MIN_SPEED_Y;
		break;
	case 2:
		this->direction = MIN_SPEED_X;
		this->maxYTravel = MAX_SPEED_Y;
		break;
	case 3:
		this->direction = MAX_SPEED_X;
		this->maxYTravel = MAX_SPEED_Y;
		break;
	}

	this->manager = manager;
	this->lives = lives;
	this->velocity.x = this->direction;
	this->yTraveled = 0;
}

void Enemy::Update(sf::RenderWindow* window)
{
	if (ammo > 0)
	{
		int chance = rand() % 100 + 1;
		if (chance < 2)
		{
			this->manager->Add("bullet", new Bullet(this->lives, this->getPosition().x, this->getPosition().y + 32, 1, false));
			ammo -= 1;
		}
	}

	if (this->velocity.x != direction)
	{
		this->move(0, 1);
		this->yTraveled += 1;
	}
	if (this->yTraveled >= this->maxYTravel)
	{
		this->velocity.x = direction;
		this->yTraveled = 0;
	}

	if (this->velocity.x == direction)
	{
		Entity::Update(window);
		if ((this->getPosition().x <= 0 || this->getPosition().x + this->getGlobalBounds().width >= window->getSize().x))
		{
			direction *= -1;
		}
	}
}

void Enemy::Collision(Entity* entity)
{
}