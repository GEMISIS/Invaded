#pragma once

#include "game_state.h"

class main_menu : public tiny_state
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	sf::Font* font;
	sf::Text* title;
	sf::Text* play;
	sf::Text* quit;

	int selected;

	bool upKey, downKey;
};