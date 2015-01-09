#include "ship.h"
#include "bullet.h"

int playerAmmo = 3;

Ship::Ship(Score* score, EntityManager* manager, float x, float y)
{
	this->active = 1;
	this->groupId = 1;
	this->Load("ship.png");
	this->setColor(sf::Color::Green);

	this->setPosition(x - this->getGlobalBounds().width / 2, y - this->getGlobalBounds().height / 2);
	this->space = false;

	this->manager = manager;
	this->score = score;
}

void Ship::Update(sf::RenderWindow* window)
{
	this->velocity.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	if (!this->space && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		if (playerAmmo > 0)
		{
			this->manager->Add("bullet", new Bullet(this->score, this->getPosition().x, this->getPosition().y - 32, -1, true));
			playerAmmo -= 1;
		}
	}
	this->space = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
	Entity::Update(window);
}

void Ship::Collision(Entity* entity)
{
	switch (entity->GroupID())
	{
	case 2:
		gameOver = true;
		break;
	}
}