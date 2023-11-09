#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Logger.hpp>
#include <Consts.hpp>
#include <Textures.hpp>
#include <Sprites.hpp>

class Projectile
{
public:
	std::unique_ptr<sf::Sprite> sprite;
	std::shared_ptr<TextureWithProperties> texture;
	sf::Vector2f direction;
	int textureCount = 0;
	int healt = 1;
	bool isAlive = true;
	float bornTime;
	//sf::Vector2u vectorSize;
public:
	Projectile(std::shared_ptr<TextureWithProperties>& t, sf::Vector2f pos, float gameTime);
	~Projectile();
public:
	void Draw(float gameTime, sf::RenderWindow* w);
	void Move();
};

#endif // EVENTS_H
