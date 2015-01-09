#include "entity.h"

Entity::Entity()
{
	this->texture = new sf::Texture();
	this->active = 1;
	this->groupId = 0;
}

void Entity::Load(std::string filename)
{
	this->texture->loadFromFile("Graphics/sprites/" + filename);
	this->setTexture(*this->texture);
}

void Entity::Update(sf::RenderWindow* window)
{
	this->move(this->velocity);
}
void Entity::Collision(Entity* entity)
{
}

bool Entity::CheckCollision(Entity* entity)
{
	return this->getGlobalBounds().intersects(entity->getGlobalBounds());
}

int Entity::GroupID()
{
	return this->groupId;
}

int Entity::Active()
{
	return this->active;
}

void Entity::Destroy()
{
	this->active = 0;
}

Entity::~Entity()
{
	delete this->texture;
}