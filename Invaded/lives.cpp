#include "lives.h"

Lives::Lives(sf::Font &font, unsigned int size) : sf::Text("Lives: 3", font, size)
{
	this->value = 3;
}

void Lives::RemoveLife()
{
	this->value -= 1;
}

int Lives::Value()
{
	return this->value;
}

void Lives::Update()
{
	this->setString("Lives: " + std::to_string(this->value));
}