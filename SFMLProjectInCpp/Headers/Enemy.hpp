#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Consts.hpp>
#include <Sprites.hpp>

class Enemy
{
public:
	std::unique_ptr<sf::Sprite> sprite;
	std::shared_ptr<TextureWithProperties> texture;
	std::vector<std::shared_ptr<TextureWithProperties>> otherTextures;
	sf::Vector2f direction;
	int textureCount = 0;
	float actionColdDown = 0;
	float bornTime;
	float healt = 1;
	float damage = 1;
	bool isAlive = true;
public:
	Enemy(std::shared_ptr<TextureWithProperties>& t, sf::Vector2f pos, float gameTime, sf::Vector2f dir, sf::Vector2f scale);
	virtual ~Enemy();
public:
	void Draw(float gameTime, sf::RenderWindow* w);
	void Move(const sf::Vector2u& windowSize, const sf::Vector2f& playerPosition);
};


float CalculLength(const sf::Vector2f& dif);

float CalculLength(const sf::Vector2u& dif);
#endif