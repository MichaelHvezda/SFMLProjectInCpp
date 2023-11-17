#include <KeyPress.hpp>
void ProcessKeyPressed(sf::RenderWindow* window, const sf::Event& event, Game* game)
{

	//Logger("Key pressed: ", event.key.scancode, event.key.code);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		game->menu->isOpen = !game->menu->isOpen;
		game->isGameStart = true;
		Logger("window close by ESCAPE key pressed");
	}

	//game->player.directions.clear();
	for (const auto& maps : Consts::KeyActionMap)
	{
		SetActions(maps, game->player->actions);
	}

	for (const auto& maps : Consts::KeyDirectionMap)
	{
		SetActions(maps, game->player->directions);
	}
	//SetActions(game);
}

void ProcessKeyReleased(sf::RenderWindow* window, const sf::Event& event, Game* game)
{

	//Logger("Key released: ", event.key.scancode, event.key.code);

	for (const auto& maps : Consts::KeyActionMap)
	{
		EraseActions(maps, game->player->actions);
	}

	//game->player.directions.clear();
	for (const auto& maps : Consts::KeyDirectionMap)
	{
		EraseActions(maps, game->player->directions);
	}

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
void SetActions(const Consts::KeyMap<T>& keyMap, std::vector<T>& list)
{
	for (const auto& key : keyMap.keys)
	{
		if (sf::Keyboard::isKeyPressed(key))
		{

			bool exist = false;

			for (auto& dir : list)
			{
				if (dir == keyMap.action)
				{
					exist = true;
					break;
				}
			}

			if (!exist)
				list.push_back(keyMap.action);
		}
	}
}

template<typename T>
void EraseActions(const Consts::KeyMap<T>& keyMap, std::vector<T>& list)
{
	int i = 0;
	for (auto& dir : list)
	{
		if (dir == keyMap.action)
		{
			bool del = false;
			for (const auto& key : keyMap.keys)
			{
				if (sf::Keyboard::isKeyPressed(key))
				{
					del = true;
				}
			}
			if (!del)
				list.erase(list.begin() + i);
		}
		i++;
	}

}