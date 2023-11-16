#ifndef MENU_H
#define MENU_H


#include <Button.hpp>

class Menu
{
public:
	bool isOpen;
public:
	void Draw(sf::RenderWindow* window);
	void Resize(sf::Vector2f size, sf::Vector2f scale);
	void SetActive(sf::Vector2i mousePos);
public:
	Menu(sf::Vector2u size);
	~Menu();

private:
	std::vector<std::unique_ptr<Button>> buttons;
	sf::Font font;
	sf::Shader shader;
};


#endif