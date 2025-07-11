#include <KeyPress.hpp>
void ProcessKeyPressed(sf::RenderWindow* window, const sf::Event& event, Game* game)
{

	//Logger("Key pressed: ", event.key.scancode, event.key.code);

	if (event.key.code == sf::Keyboard::Escape)
	{
		//return coz it not nesesery process others
		if (!game->menu->isOpen) {
			game->menu->isOpen = true;
			return;
		}
		window->close();
		Logger("window close by ESCAPE key pressed");
		return;
	}

	if (event.key.code == sf::Keyboard::P)
	{
		game->menu->isOpen = !game->menu->isOpen;
		game->isGameStart = !game->isGameStart;
		//Logger("window close by P key pressed");
	}
	//game->player.directions.clear();
	for (const auto& maps : Consts::KeyActionMap)
	{
		SetActions(event, maps, game->actions);
	}

	for (const auto& maps : Consts::KeyDirectionMap)
	{
		SetActions(event, maps, game->actions);
	}
	//Logger("preseerd: ", game->actions);
	//SetActions(game);
}

void ProcessKeyReleased(sf::RenderWindow* window, const sf::Event& event, Game* game)
{
	//Logger("Key released: ", event.key.scancode, event.key.code);

	for (const auto& maps : Consts::KeyActionMap)
	{
		EraseActions(event, maps, game->actions);
	}

	//game->player.directions.clear();
	for (const auto& maps : Consts::KeyDirectionMap)
	{
		EraseActions(event, maps, game->actions);
	}

	//Logger("relesed: ", game->actions);
}

void ProcessMouseMoved(sf::RenderWindow* window, const sf::Event& event, Game* game)
{
	if (game->menu->isOpen)
	{
		/*auto mousePos = sf::Mouse::getPosition();
		auto mausCords = window->mapPixelToCoords(mousePos);
		auto mausPix = window->mapCoordsToPixel(sf::Vector2f(mausCords.x, mausCords.y));
		Logger("mousePos:", mousePos.x, mousePos.y);
		Logger("mausCords:", mausCords.x,mausCords.y);
		Logger("mausPix:", mausPix.x, mausPix.y);*/
		//Logger("move:", event.mouseMove.x, event.mouseMove.y);
		game->menu->SetActive(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
	}
}
void ProcessMousePressed(sf::RenderWindow* window, const sf::Event& event, Game* game)
{

	if (!game->menu->isClicked && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && game->menu->isOpen)
	{
		game->menu->isClicked = true;
		game->menu->SetPressed(window, game, sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
	}
}
void ProcessMouseReleased(sf::RenderWindow* window, const sf::Event& event, Game* game)
{
	if (game->menu->isClicked)
	{
		game->menu->isClicked = false;
	}
}

template<typename T>
void SetActions(const sf::Event& event, const Consts::KeyMap<T>& keyMap, uint64_t& action)
{
	for (const auto& key : keyMap.keys)
	{
		if (event.key.code == key)
		{
			action = action | static_cast<uint64_t>(keyMap.action);
			return;
		}
	}
}

template<typename T>
void EraseActions(const sf::Event& event, const Consts::KeyMap<T>& keyMap, uint64_t& action)
{
	for (const auto& key : keyMap.keys)
	{
		if (event.key.code == key)
		{
			action = action & (~static_cast<uint64_t>(keyMap.action));
			return;
		}
	}
}