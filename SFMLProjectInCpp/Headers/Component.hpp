#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H

#include <SFML/Graphics.hpp>
#include <Consts.hpp>
#include <Textures.hpp>


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
	std::shared_ptr<TextureWithProperties> shootTextureWithProps;
	float damage;
	float actionColdDown;
};

struct HealthComponent
{
	float health;
	bool isAlive = true;
	HealthComponent() = default;
	HealthComponent(const HealthComponent&) = default;
	HealthComponent(const float health) :health(health) {};
};

struct AnimationComponent
{
	sf::Vector2i textureSize;
	bool haveDeadAnimation;
	//int textureCount;
	int animationsCount;
	float bornTime;

	AnimationComponent() = default;

	AnimationComponent(const sf::Vector2i& textureSize, bool haveDeadAnimation, int animationsCount, float bornTime)
		: textureSize(textureSize), haveDeadAnimation(haveDeadAnimation), animationsCount(animationsCount), bornTime(bornTime)
	{
	}
};

struct TypeComponent
{
	Consts::GraphicObjectType type;

	TypeComponent() = default;
	TypeComponent(const TypeComponent&) = default;
	TypeComponent(Consts::GraphicObjectType type) :type(type) {};
};

#endif