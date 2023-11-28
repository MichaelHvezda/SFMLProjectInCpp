#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <entt.hpp>
#include <EntitiesManager.hpp>
#include <SFML/Graphics.hpp>
#include <utility>

class Entity
{
public:
	Entity(entt::entity entity, EntitiesManager* manager);
	Entity() = default;
	Entity(const Entity& other) = default;
	~Entity();

public:
	template<typename... T>
	bool HaveComponents()
	{
		return manager->registry.all_of<T...>(entity);
	}

	template<typename T, typename... Args>
	T& AddComponents(Args&&... components)
	{
		return manager->registry.emplace<T>(entity, std::forward<Args>(components)...);
	}

	template<typename T>
	T& GetComponents()
	{
		return manager->registry.get<T>(entity);
	}

	template<typename T>
	void RemoveComponent()
	{
		manager->registry.remove<T>(entity);
	}

public:
	entt::entity entity{ 0 };
	EntitiesManager* manager = nullptr;
};
#endif