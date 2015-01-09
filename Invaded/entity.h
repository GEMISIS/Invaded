#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Entity : public sf::Sprite
{
public:
	sf::Vector2f velocity;

	Entity();

	void Load(std::string filename);

	virtual void Update(sf::RenderWindow* window);

	bool CheckCollision(Entity* entity);

	virtual void Collision(Entity* entity);

	int GroupID();

	int Active();

	void Destroy();

	~Entity();
protected:
	int active;
	int groupId;
private:
	sf::Texture* texture;
};

