#include "bullet.h"

Bullet::Bullet(Lives* lives, float x, float y, float direction, bool good)
{
	this->active = 1;
	if (good)
	{
		this->groupId = 3;
	}
	else
	{
		this->groupId = 4;
	}
	this->Load("ship.png");
	this->setColor(sf::Color::White);
	this->setScale(0.25f, 0.5f);

	this->velocity.y = direction;

	this->setPosition(x - this->getGlobalBounds().width / 2, y - this->getGlobalBounds().height / 2);

	this->lives = lives;
}

Bullet::Bullet(Score* score, float x, float y, float direction, bool good)
{
	this->active = 1;
	if (good)
	{
		this->groupId = 3;
	}
	else
	{
		this->groupId = 4;
	}
	this->Load("ship.png");
	this->setColor(sf::Color::White);
	this->setScale(0.25f, 0.5f);

	this->velocity.y = direction;

	this->score = score;

	this->setPosition(x - this->getGlobalBounds().width / 2, y - this->getGlobalBounds().height / 2);
}

void Bullet::Update(sf::RenderWindow* window)
{
	if (this->getPosition().y <= 0 || this->getPosition().y + this->getGlobalBounds().height >= window->getSize().y)
	{
		if (this->GroupID() == 4)
		{
			ammo += 1;
		}
		else if (this->GroupID() == 3)
		{
			playerAmmo += 1;
		}
		this->Destroy();
	}
	Entity::Update(window);
}

void Bullet::Collision(Entity* entity)
{
	if (this->groupId == 3)
	{
		switch (entity->GroupID())
		{
		case 1:
		case 3:
		case 4:
			break;
		case 2:
			playerAmmo += 1;
			enemyCount -= 1;
			this->score->IncrementScore();
			entity->Destroy();
			this->Destroy();
			break;
		}
	}
	else if (this->groupId == 4)
	{
		switch (entity->GroupID())
		{
		case 2:
		case 3:
		case 4:
			break;
		default:
			ammo += 1;
			this->lives->RemoveLife();
			this->Destroy();
			break;
		}
	}
}