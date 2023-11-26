#include <EntitiesManager.hpp>

namespace Entity {
	EntitiesManager::EntitiesManager(sf::RenderWindow* w) : window(w)
	{
	}

	EntitiesManager::~EntitiesManager()
	{
	}
	void EntitiesManager::Update()
	{
	}
	void EntitiesManager::Draw()
	{
	}

	Entity EntitiesManager::CreateEntity()
	{
		return { registry.create(), this };
	}

}