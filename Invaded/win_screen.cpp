#include "win_screen.h"
#include "main_menu.h"

void win_screen::Initialize(sf::RenderWindow* window)
{
	enterKey = false;
	sf::Font* font = new sf::Font();
	font->loadFromFile("Graphics/font.ttf");

	this->winText = new sf::Text("You Win", *font, 100U);
	this->winText->setColor(sf::Color::Green);
	this->winText->setOrigin(sf::Vector2f(this->winText->getGlobalBounds().width / 2, this->winText->getGlobalBounds().height / 2));
	this->winText->setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
}
void win_screen::Update(sf::RenderWindow* window)
{
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && enterKey)
	{
		coreState.SetState(new main_menu());
	}
	enterKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
}
void win_screen::Render(sf::RenderWindow* window)
{
	window->draw(*this->winText);
}
void win_screen::Destroy(sf::RenderWindow* window)
{
	delete this->winText;
}
