#pragma once
#ifndef MENU_H
#define MENU_H


#include <Button.hpp>
class Game;
class Menu
{
public:
	bool isOpen;
	bool isClicked;
public:
	void Draw(sf::RenderWindow* window);
	void Resize(sf::Vector2f size, sf::Vector2f scale);
	void SetActive(sf::Vector2i mousePos);
	void SetPressed(sf::RenderWindow* window, Game* game, sf::Vector2i mousePos);
public:
	Menu(sf::Vector2u size);
	~Menu();

private:
	std::vector<std::shared_ptr<ButtonWithType>> buttons;
	std::vector<std::shared_ptr<ButtonWithType>> selectedBtns; // yes i agree it is not good name for its purpuse :) but too lazy to refactor now
	Consts::MenuPlace menuPlace;
	sf::Font font;
	sf::Shader shader;

private:
	void CreateAllMenuButtons(sf::Vector2u size);
	void SwitchMenuLocation();
	void ProcessMenuBtnClick(sf::RenderWindow* window, Game* game, ButtonWithType& btnWithType);
};


#endif