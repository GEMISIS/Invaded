#pragma once

#include "entity_manager.h"
#include "game_state.h"
#include "score.h"
#include "lives.h"

#define ENEMY_AMMO 5
#define PLAYER_AMMO 3

extern bool gameOver;
extern int enemyCount;

class main_game : public tiny_state
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	Score* score;
	Lives* lives;
	sf::Text* pausedText;
	sf::Text* startingText;

	sf::Font* font;

	bool starting;
	bool paused, enterKey;

	EntityManager* manager;
};