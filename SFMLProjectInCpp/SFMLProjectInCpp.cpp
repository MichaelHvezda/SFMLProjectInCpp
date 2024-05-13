// SFMLProjectInCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Logger.hpp>
#include <Game.hpp>


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	Game game(&window);
	window.setFramerateLimit(144);

	window.setKeyRepeatEnabled(false);
	while (window.isOpen())
	{
		window.clear();

		game.Update();

		window.display();
	}

	return 0;
}