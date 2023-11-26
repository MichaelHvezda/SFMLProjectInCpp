#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <entt.hpp>
#include <SFML/Graphics.hpp>


namespace Entity {
	class EntitiesManager;
	class Entity
	{
	public:
		Entity(entt::entity entity, EntitiesManager* manager);
		~Entity();

	public:
		template<typename... T>
		bool HaveComponents();
		template<typename T, typename...Args>
		decltype(auto) AddComponents(Args&&... components);
		template<typename... T>
		decltype(auto) GetComponents();

	public:
		entt::entity entity;
		EntitiesManager* manager;
	};
}
#endif