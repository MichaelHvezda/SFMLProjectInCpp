#ifndef BUTTON_H
#define BUTTON_H


#include <SFML/Graphics.hpp>
#include <Logger.hpp>
#include <Vector>
#include <string>

class Button
{
public:
	bool isSelected;
public:
	void Draw(sf::RenderWindow* window, sf::Shader* selectedShader);
	void Resize(sf::Vector2f position, sf::Vector2f scale);
	void SetPosition(float x, float y);
	void SetActive(sf::Vector2i mousePos);
	sf::Vector2f GetSize();
public:
	Button(sf::Vector2f size, sf::Font& font, std::string text);
	~Button();
private:
	sf::Text text;
	sf::Sprite sprite;
	sf::Texture texture;
};
#endif
