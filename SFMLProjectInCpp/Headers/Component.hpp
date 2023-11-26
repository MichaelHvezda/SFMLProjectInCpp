#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H

#include <SFML/Graphics.hpp>
#include <Consts.hpp>
#include <set>

namespace Entity {

	struct SpriteComponent
	{
		sf::Sprite sprite;
	};

	struct PositionComponent
	{
		sf::Vector2f position;
		sf::Vector2f scale;
		int xBase, yBase;
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
		float health;
	};

	struct AnimationComponent
	{
		bool haveDeadAnimation;
		int textureCount;
		float bornTime;
	};

	struct TypeComponent
	{
		Consts::GraphicObjectType type;
	};
}
#endif