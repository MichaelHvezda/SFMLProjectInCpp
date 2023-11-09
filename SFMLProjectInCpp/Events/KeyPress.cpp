#include <KeyPress.hpp>
void ProcessKeyPressed(sf::RenderWindow* window, const sf::Event& event, Game* game) {

	Logger("Key pressed: ", event.key.scancode, event.key.code);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		window->close();
		Logger("window close by ESCAPE key pressed");
	}

	//game->player.directions.clear();
	for (const auto& maps : Consts::KeyActionMap) {
		SetActions(maps, game->player->actions);
	}

	for (const auto& maps : Consts::KeyDirectionMap) {
		SetActions(maps, game->player->directions);
	}
	//SetActions(game);
}

void ProcessKeyReleased(sf::RenderWindow* window, const sf::Event& event, Game* game) {

	Logger("Key released: ", event.key.scancode, event.key.code);

	for (const auto& maps : Consts::KeyActionMap) {
		EraseActions(maps, game->player->actions);
	}

	//game->player.directions.clear();
	for (const auto& maps : Consts::KeyDirectionMap) {
		EraseActions(maps, game->player->directions);

	}

}


template<typename T>
void SetActions(const Consts::KeyMap<T>& keyMap, std::vector<T>& list) {
	for (const auto& key : keyMap.keys)
	{
		if (sf::Keyboard::isKeyPressed(key)) {

			bool exist = false;

			for (auto& dir : list) {
				if (dir == keyMap.action) {
					exist = true;
					break;
				}
			}

			if(!exist)
				list.push_back(keyMap.action);
		}
	}
}

template<typename T>
void EraseActions(const Consts::KeyMap<T>& keyMap, std::vector<T>& list) {
	int i = 0;
	for (auto& dir : list) {
		if (dir == keyMap.action)
		{
			bool del = false;
			for (const auto& key : keyMap.keys)
			{
				if (sf::Keyboard::isKeyPressed(key)) {
					del = true;
				}
			}
			if (!del)
				list.erase(list.begin() + i);
		}
		i++;
	}

}