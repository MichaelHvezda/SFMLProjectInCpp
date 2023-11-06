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
	std::shared_ptr<TextureWithType> texture;
	sf::Vector2f direction;
	int textureCount = 0;
	sf::Vector2u vectorSize;
public:
	Projectile(std::shared_ptr<TextureWithType>& t, sf::Vector2f pos);
	~Projectile();
public:
	void Draw(int syncImageCount, sf::RenderWindow* w);
};

#endif // EVENTS_H
