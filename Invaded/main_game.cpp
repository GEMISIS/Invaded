#include "main_game.h"
#include "main_menu.h"
#include "game_over.h"
#include "win_screen.h"

#include "ship.h"
#include "enemy.h"

bool gameOver = false;
int enemyCount = 0;

void main_game::Initialize(sf::RenderWindow* window)
{
	this->font = new sf::Font();
	this->font->loadFromFile("Graphics/font.ttf");
	this->score = new Score(*font, 64U);
	this->lives = new Lives(*font, 64U);
	this->lives->setPosition(window->getSize().x - this->lives->getGlobalBounds().width, 0);

	this->pausedText = new sf::Text("Paused\nPress Escape to Quit", *font, 64U);
	this->pausedText->setOrigin(this->pausedText->getGlobalBounds().width / 2, this->pausedText->getGlobalBounds().height / 2);
	this->pausedText->setPosition(window->getSize().x / 2, window->getSize().y / 2);

	this->paused = false;
	this->enterKey = false;

	manager = new EntityManager();

	this->manager->Add("ship", new Ship(this->score, this->manager, window->getSize().x / 2, window->getSize().y));

	for (int y = 0; y < 5; y += 1)
	{
		for (int x = 0; x < 10; x += 1)
		{
			this->manager->Add("enemy", new Enemy(this->lives, this->manager, 16 + 48 * x, 64 + 48 * y));
			enemyCount += 1;
		}
	}

	direction = 0.75f;
	ammo = ENEMY_AMMO;
	playerAmmo = PLAYER_AMMO;
}
void main_game::Update(sf::RenderWindow* window)
{
	if (this->paused)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && !this->enterKey)
		{
			this->paused = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			coreState.SetState(new main_menu());
			return;
		}
	}
	else
	{
		this->manager->Update(window);
		this->score->Update();
		this->lives->Update();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && !this->enterKey)
		{
			this->paused = true;
		}
	}
	if (enemyCount <= 0)
	{
		enemyCount = 0;
		gameOver = false;
		coreState.SetState(new win_screen());
		return;
	}
	if (gameOver || this->lives->Value() <= 0)
	{
		gameOver = false;
		coreState.SetState(new game_over());
		return;
	}
	this->enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
}
void main_game::Render(sf::RenderWindow* window)
{
	this->manager->Render(window);
	window->draw(*this->score);
	window->draw(*this->lives);

	if (this->paused)
	{
		window->draw(*this->pausedText);
	}
}
void main_game::Destroy(sf::RenderWindow* window)
{
	delete this->score;
	delete this->lives;
	delete this->pausedText;
	delete this->font;

	delete this->manager;
}
