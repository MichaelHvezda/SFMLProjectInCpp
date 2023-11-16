#include <Menu.hpp>

Menu::Menu(sf::Vector2u size)
{
	isOpen = true;

	if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		Logger("Font not exist");
	}

	//sf::Text textProp;
	//textProp.setFont(font);
	//textProp.setFillColor(sf::Color::White);
	//textProp.setOutlineThickness(10.f);
	//textProp.setOutlineColor(sf::Color::Blue);
	//textProp.setCharacterSize(20);
	//textProp.setString("Play");
	auto defaultSize = sf::Vector2f(100, 50);

	buttons.push_back(std::make_unique<Button>(defaultSize, font, "Play"));
	buttons.push_back(std::make_unique<Button>(defaultSize, font, "Options"));
	buttons.push_back(std::make_unique<Button>(defaultSize, font, "Credits"));
	buttons.push_back(std::make_unique<Button>(defaultSize, font, "Exit"));

	shader.loadFromFile("Shaders/Menu/Selected.vert", "Shaders/Menu/Selected.frag");

	auto textSize = buttons.size();
	int i = 1;
	for (const auto& b : buttons)
	{
		b->SetPosition(size.x / 2.f, (size.y / (textSize + 1.f)) * i);

		i++;
	}
}

Menu::~Menu()
{

}

void Menu::Draw(sf::RenderWindow* window)
{
	int i = 0;
	for (auto& b : buttons) {
		//if (i == 0)
		//{
		//	window->draw(t, &shader);
		//	continue;
		//}

		b->Draw(window, &shader);
	}
}
void Menu::Resize(sf::Vector2f size, sf::Vector2f scale)
{
	auto textSize = buttons.size();
	int i = 1;
	for (auto& b : buttons) {
		auto btnSize = b->GetSize();
		//sf::Vector2f scaleBtn(btnSize.x * scale.x, btnSize.y * scale.y);
		sf::Vector2f posBtn(size.x / 2.f, (size.y / (textSize + 1.f)) * i);
		b->Resize(posBtn, scale);

		//b->SetPosition(btnSize.x * scale.x, btnSize.y * scale.y);
		//b->SetPosition(size.x / 2.f, (size.y / (textSize + 1.f)) * i);
		i++;
	}
}

void Menu::SetActive(sf::Vector2i mousePos) {
	for (auto& b : buttons) {
		b->SetActive(mousePos);
	}
}
