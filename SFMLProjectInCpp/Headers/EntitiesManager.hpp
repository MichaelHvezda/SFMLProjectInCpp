#pragma once
#ifndef COMPONENTS_MANAGER_H
#define COMPONENTS_MANAGER_H


#include <entt.hpp>
#include <Entity.hpp>

namespace Entity {
	class EntitiesManager
	{
	public:
		EntitiesManager(sf::RenderWindow* w);
		~EntitiesManager();
	public:
		void Update();
		void Draw();

		Entity CreateEntity();
	private:
		entt::registry registry;
		sf::RenderWindow* window;
	private:
		friend class Entity;
	};
}


#endif