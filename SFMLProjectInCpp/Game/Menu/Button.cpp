#include <Button.hpp>

Button::Button(sf::Vector2f size, sf::Font& font, std::string text)
{
	isSelected = false;

	this->text.setFont(font);
	this->text.setFillColor(sf::Color::Red);
	//this->text.setOutlineThickness(10.f);
	//this->text.setOutlineColor(sf::Color::Blue);
	this->text.setCharacterSize(20);
	this->text.setString(text);
	auto textSize = this->text.getGlobalBounds().getSize() / 2.f;
	textSize += this->text.getGlobalBounds().getPosition();
	this->text.setOrigin(textSize);

	texture.create(static_cast<int>(size.x), static_cast<int>(size.y));
	std::vector<sf::Uint8> pixels(size.x * size.y * 4, 0);
	texture.update(&pixels[0]);
	sprite.setTexture(texture);
	auto btnSize = sprite.getGlobalBounds().getSize();
	sprite.setOrigin(btnSize.x / 2.f, btnSize.y / 2.f);
}

void Button::SetPosition(float x, float y)
{
	text.setPosition(x, y);
	sprite.setPosition(x, y);
}

void Button::SetActive(sf::Vector2i mousePos)
{
	auto bound = sprite.getGlobalBounds();
	if (bound.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		isSelected = true;
		return;
	}
	isSelected = false;
}

bool Button::ClickInside(sf::Vector2i mousePos)
{
	auto bound = sprite.getGlobalBounds();
	if (bound.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		return true;
	}
	return false;
}

void Button::Draw(sf::RenderWindow* window, sf::Shader* selectedShader)
{
	if (isSelected)
	{
		window->draw(sprite, selectedShader);
		window->draw(text);
		return;
	}

	window->draw(sprite);
	window->draw(text);
}

void Button::Resize(sf::Vector2f position, sf::Vector2f scale)
{
	text.setCharacterSize(static_cast<int>(text.getCharacterSize() * scale.x));
	//text.scale(scale);

	auto textSize = text.getLocalBounds().getSize() / 2.f;
	textSize += text.getLocalBounds().getPosition();
	text.setOrigin(textSize);

	text.setPosition(position);

	sprite.scale(scale);
	sprite.setPosition(position);

}
sf::Vector2f Button::GetPosition()
{
	return sprite.getPosition();
}

Button::~Button() {

}
