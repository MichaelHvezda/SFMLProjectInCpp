#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H

#include <SFML/Graphics.hpp>
#include <Consts.hpp>


struct SpriteComponent
{

	sf::Sprite sprite;

	SpriteComponent() = default;
	SpriteComponent(const SpriteComponent&) = default;
	SpriteComponent(const sf::Sprite& sprite) :sprite(sprite) {};
};

struct PositionComponent
{
	sf::Vector2f position;
	sf::Vector2f scale;
	sf::Vector2u baseSize;

	PositionComponent() = default;
	PositionComponent(const PositionComponent&) = default;
	PositionComponent(sf::Vector2f position, sf::Vector2f scale, sf::Vector2u baseSize) :position(position), scale(scale), baseSize(baseSize) {};
};

struct MomentumComponent
{
	sf::Vector2f momentum;
};

struct ShootComponent
{
	sf::Sprite shootSprite;
	float damage;
	float actionColdDown;
};

struct HealthComponent
{
	HealthComponent() = default;
	HealthComponent(const HealthComponent&) = default;
	HealthComponent(const float health) :health(health) {};
	float health;
};

struct AnimationComponent
{
	bool haveDeadAnimation;
	int textureCount;
	int animationsCount;
	float bornTime;
};

struct TypeComponent
{
	Consts::GraphicObjectType type;

	TypeComponent() = default;
	TypeComponent(const TypeComponent&) = default;
	TypeComponent(Consts::GraphicObjectType type) :type(type) {};
};
#endif