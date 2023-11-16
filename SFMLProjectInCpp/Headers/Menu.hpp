#ifndef MENU_H
#define MENU_H


#include <SFML/Graphics.hpp>
#include <Logger.hpp>
#include <Vector>

class Menu
{
public:
	bool isOpen;
public:
	void Draw(sf::RenderWindow* window);
	void Resize(sf::Vector2u size, sf::Vector2f scale);
public:
	Menu(sf::Vector2u size);
	~Menu();

private:
	std::vector<sf::Text> text;
	sf::Font font;
};


#endif