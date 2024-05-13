#pragma once
#ifndef COMPONENTS_MANAGER_H
#define COMPONENTS_MANAGER_H


#include <entt.hpp>
#include <SFML/Graphics.hpp>
//#include <Entity.hpp>
class Entity;
class EntitiesManager
{
public:
	EntitiesManager(sf::RenderWindow* w, const float& gameTime, const uint64_t& action);
	~EntitiesManager();
public:
	void Update();
	void Draw();
	void ResizeAll(const sf::Event::SizeEvent& newSize, sf::Vector2u oldSize);

	Entity CreateEntity();
private:
	entt::registry registry;
	sf::RenderWindow* window;
	const float& gameTime;
	const uint64_t& action;
private:
	friend class Entity;
};


#endif