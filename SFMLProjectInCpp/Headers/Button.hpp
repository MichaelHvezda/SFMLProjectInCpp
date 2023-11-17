#pragma once
#ifndef BUTTON_H
#define BUTTON_H


#include <SFML/Graphics.hpp>
#include <Logger.hpp>
#include <Vector>
#include <string>
#include <Consts.hpp>
class Game;

class Button
{
public:
	bool isSelected;
public:
	void Draw(sf::RenderWindow* window, sf::Shader* selectedShader);
	void Resize(sf::Vector2f position, sf::Vector2f scale);
	void SetPosition(float x, float y);
	void SetActive(sf::Vector2i mousePos);
	bool ClickInside(sf::Vector2i mousePos);
	sf::Vector2f GetPosition();
public:
	Button(sf::Vector2f size, sf::Font& font, std::string text);
	~Button();
private:
	sf::Text text;
	sf::Sprite sprite;
	sf::Texture texture;
};

struct ButtonWithType
{
public:
	Button btn;
	Consts::MenuPlace place;
	Consts::MenuButtonType type;
};

#endif
