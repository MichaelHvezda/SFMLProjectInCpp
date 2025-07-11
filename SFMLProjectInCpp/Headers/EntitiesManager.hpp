#pragma once
#ifndef COMPONENTS_MANAGER_H
#define COMPONENTS_MANAGER_H


#include <entt.hpp>
#include <SFML/Graphics.hpp>
#include <Component.hpp>
//#include <Entity.hpp>
class Entity;
class EntitiesManager
{
public:
	EntitiesManager(sf::RenderWindow* w, const float& gameTime, const uint64_t& action);
	~EntitiesManager();
public:
	void Update(float renderTime);
	void CreateShoot(const ShootComponent& shoot, const PositionComponent& pos);
	void Draw();
	void ResizeAll(const sf::Event::SizeEvent& newSize, const sf::Vector2u& oldSize);
	bool IsInsideWindow(const sf::Vector2f& pos) const;
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