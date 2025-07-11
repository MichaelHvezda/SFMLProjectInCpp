#include <Menu.hpp>
#include <Game.hpp>

Menu::Menu(sf::Vector2u size)
{
	isOpen = true;

	if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		Logger("Font not exist");
	}
	menuPlace = Consts::MenuPlace::MainMenu;

	//sf::Text textProp;
	//textProp.setFont(font);
	//textProp.setFillColor(sf::Color::White);
	//textProp.setOutlineThickness(10.f);
	//textProp.setOutlineColor(sf::Color::Blue);
	//textProp.setCharacterSize(20);
	//textProp.setString("Play");

	CreateAllMenuButtons(size);

	SwitchMenuLocation();

	shader.loadFromFile("Shaders/Menu/Selected.vert", "Shaders/Menu/Selected.frag");
}

Menu::~Menu()
{

}

void Menu::Draw(sf::RenderWindow* window)
{
	int i = 0;
	for (auto& b : selectedBtns) {
		//if (i == 0)
		//{
		//	window->draw(t, &shader);
		//	continue;
		//}

		b->btn.Draw(window, &shader);
	}
}
void Menu::Resize(const sf::Event::SizeEvent& newSize, sf::Vector2u oldSize) const
{
	sf::Vector2f scale(newSize.width / static_cast<float>(oldSize.x), newSize.height / static_cast<float>(oldSize.y));

	auto textSize = buttons.size();
	int i = 1;
	for (auto& b : buttons) {
		auto pos = b->btn.GetPosition();

		auto rateX = pos.x / (newSize.width / scale.x);
		auto rateY = pos.y / (newSize.height / scale.y);

		//sf::Vector2f scaleBtn(btnSize.x * scale.x, btnSize.y * scale.y);
		//sf::Vector2f posBtn(size.x / 2.f, (size.y / (textSize + 1.f)) * i);
		sf::Vector2f posBtn(rateX * newSize.width, rateY * newSize.height);
		b->btn.Resize(posBtn, scale);

		//b->SetPosition(btnSize.x * scale.x, btnSize.y * scale.y);
		//b->SetPosition(size.x / 2.f, (size.y / (textSize + 1.f)) * i);
		i++;
	}
}

void Menu::SetActive(sf::Vector2i mousePos) {
	for (auto& b : selectedBtns) {

		if (b->type == Consts::MenuButtonType::Text) {
			continue;
		}

		b->btn.SetActive(mousePos);
	}
}
void Menu::SetPressed(sf::RenderWindow* window, Game* game, sf::Vector2i mousePos)
{
	for (const auto& b : selectedBtns) {
		if (b->btn.ClickInside(mousePos))
		{
			ProcessMenuBtnClick(window, game, *b);
		}
	}
}



void Menu::CreateAllMenuButtons(sf::Vector2u size) {
	auto defaultSize = sf::Vector2f(100, 50);

	std::vector<std::shared_ptr<ButtonWithType>> mainMenu;
	mainMenu.push_back(std::make_shared<ButtonWithType>(ButtonWithType{
	{ defaultSize, font, "Play" }, Consts::MenuPlace::MainMenu, Consts::MenuButtonType::Play
		}));
	mainMenu.push_back(std::make_shared<ButtonWithType>(ButtonWithType{
		{defaultSize, font, "Options"}, Consts::MenuPlace::MainMenu, Consts::MenuButtonType::Options
		}));
	mainMenu.push_back(std::make_shared<ButtonWithType>(ButtonWithType{
		{defaultSize, font, "Credits"}, Consts::MenuPlace::MainMenu, Consts::MenuButtonType::Credits
		}));
	mainMenu.push_back(std::make_shared<ButtonWithType>(ButtonWithType{
		{defaultSize, font, "Exit"}, Consts::MenuPlace::MainMenu, Consts::MenuButtonType::Exit
		}));

	auto mainMenuSize = mainMenu.size();
	int i = 1;
	for (const auto& b : mainMenu)
	{
		b->btn.SetPosition(size.x / 2.f, (size.y / (mainMenuSize + 1.f)) * i);

		i++;
	}

	std::vector<std::shared_ptr<ButtonWithType>> setting;
	setting.push_back(std::make_shared<ButtonWithType>(ButtonWithType{
		{defaultSize, font, "Back"}, Consts::MenuPlace::Options, Consts::MenuButtonType::Back
		}));

	setting[0]->btn.SetPosition(size.x / 2.f, size.y / 5.f * 4.f);

	std::vector<std::shared_ptr<ButtonWithType>> credits;
	credits.push_back(std::make_shared<ButtonWithType>(ButtonWithType{
		{defaultSize, font, "Back"}, Consts::MenuPlace::Credits, Consts::MenuButtonType::Back
		}));
	credits.push_back(std::make_shared<ButtonWithType>(ButtonWithType{
		{defaultSize, font, "Made by Gogousek"}, Consts::MenuPlace::Credits, Consts::MenuButtonType::Text
		}));

	credits[0]->btn.SetPosition(size.x / 2.f, size.y / 5.f * 4.f);
	credits[1]->btn.SetPosition(size.x / 2.f, size.y / 5.f * 2.f);

	buttons.reserve(11);
	buttons.insert(buttons.end(), mainMenu.begin(), mainMenu.end());
	buttons.insert(buttons.end(), setting.begin(), setting.end());
	buttons.insert(buttons.end(), credits.begin(), credits.end());
}

void Menu::SwitchMenuLocation() {
	selectedBtns.clear();
	for (const auto& btn : buttons)
	{
		btn->btn.isSelected = false;
		if (btn->place == menuPlace)
		{
			selectedBtns.push_back(btn);
		}
	}
}

void Menu::ProcessMenuBtnClick(sf::RenderWindow* window, Game* game, const ButtonWithType& btnWithType) {
	switch (btnWithType.type)
	{
	case Consts::MenuButtonType::Play:
		isOpen = false;
		game->isGameStart = true;
		//sprite->move(sf::Vector2f(-0.05f, 0.f));
		break;
	case Consts::MenuButtonType::Options:
		menuPlace = Consts::MenuPlace::Options;
		SwitchMenuLocation();
		break;
	case Consts::MenuButtonType::Credits:
		menuPlace = Consts::MenuPlace::Credits;
		SwitchMenuLocation();
		break;
	case Consts::MenuButtonType::Exit:
		window->close();
		break;
	case Consts::MenuButtonType::Back:
		menuPlace = Consts::MenuPlace::MainMenu;
		SwitchMenuLocation();
		break;
	case Consts::MenuButtonType::Text:
		break;
	default:
		break;
	}
}
