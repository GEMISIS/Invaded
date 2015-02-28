#include <SFML/Audio.hpp>
#include <Windows.h>

#include "game_state.h"
#include "main_menu.h"

game_state coreState;
bool quitGame = false;

#ifdef _DEBUG
int main()
#else
int CALLBACK WinMain(
	_In_  HINSTANCE hInstance,
	_In_  HINSTANCE hPrevInstance,
	_In_  LPSTR lpCmdLine,
	_In_  int nCmdShow
	)
#endif
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Invaded", sf::Style::Close);

	coreState.SetWindow(&window);
	coreState.SetState(new main_menu());

	sf::Clock timer;
	sf::Time elapsed;

	sf::SoundBuffer musicBuffer;
	musicBuffer.loadFromFile("Sounds/music.wav");
	sf::Sound music(musicBuffer);

	music.setLoop(true);
	music.setVolume(10);
	music.play();

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		elapsed = timer.getElapsedTime();

		if (elapsed.asMicroseconds() > 16666)
		{
			window.clear(sf::Color::Black);

			coreState.Update();
			coreState.Render();

			window.display();

			if (quitGame)
			{
				window.close();
			}

			timer.restart();
		}
	}

	music.stop();

	return 0;
}
