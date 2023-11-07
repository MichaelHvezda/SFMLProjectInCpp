// SFMLProjectInCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Logger.hpp>
#include <Game.hpp>


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);
	Game game(&window);
	window.setFramerateLimit(144);

	/*sf::Text text;
	text.setCharacterSize(24);

	text.setFillColor(sf::Color::White);*/

	//sf::Font font;
	//if (!font.loadFromFile("Fonts/arial.ttf"))
	//{
	//	Logger("Font not exist");
	//}
	//text.setFont(font);

	while (window.isOpen())
	{
		//float currentTime = clock.restart().asSeconds();
		//float fps = 1.f / currentTime;
		////Logger("fps :", fps);
		//text.setString(std::to_string(fps));

		window.clear();
		//std::vector<Consts::Direction> directions;
		game.Update();
		//window.draw(text);
		//window.draw(shape);
		window.display();

	}

	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
