#include <Menu.hpp>


Menu::Menu(sf::Vector2u size)
{
	isOpen = true;

	if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		Logger("Font not exist");
	}

	sf::Text textProp;
	textProp.setFont(font);
	textProp.setFillColor(sf::Color::White);
	textProp.setCharacterSize(20);
	textProp.setString("Play");
	text.push_back(textProp);

	textProp.setString("Options");
	text.push_back(textProp);

	textProp.setString("Exit");
	text.push_back(textProp);

	auto textSize = text.size();

	int i = 1;
	for (auto& t : text)
	{
		auto tSize = t.getGlobalBounds().getSize();
		t.setOrigin(tSize.x / 2.f, tSize.y / 2.f);
		t.setPosition(size.x / 2.f, (size.y / (textSize + 1.f)) * i );
		i++;
	}
}

Menu::~Menu()
{

}

void Menu::Draw(sf::RenderWindow* window)
{
	for (auto& t : text) {
		window->draw(t);
	}
}
void Menu::Resize(sf::Vector2u size, sf::Vector2f scale)
{
	for (auto& t : text) {
		t.setCharacterSize(t.getCharacterSize() * scale.x);
	}
}