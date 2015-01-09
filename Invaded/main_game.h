#pragma once

#include "entity_manager.h"
#include "game_state.h"
#include "score.h"

class main_game : public tiny_state
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	Score* score;
	sf::Text* pausedText;

	sf::Font* font;

	bool paused, enterKey;

	EntityManager* manager;
};