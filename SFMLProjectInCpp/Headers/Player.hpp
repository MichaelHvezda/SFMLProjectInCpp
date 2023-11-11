#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <Sprites.hpp>
#include <Consts.hpp>
//#include <Game.hpp>

class Player
{
public:
	std::unique_ptr<sf::Sprite> sprite;
	std::shared_ptr<TextureWithProperties> texture;
	std::vector<std::shared_ptr<TextureWithProperties>> otherTextures;
	std::vector<Consts::Direction> directions;
	std::vector<Consts::Action> actions;
	int textureCount = 0;
	float actionColdDown = 0;
	float bornTime;
	float healt = 1;
	float damage = 1;
	bool isAlive = true;
	//sf::Vector2u vectorSize;
public:
	Player(std::shared_ptr<TextureWithProperties>& t);
	~Player();
public:
	void Draw(float gameTime, sf::RenderWindow* w);
	void SetDefaultPosition(sf::RenderWindow* w);
	void Move(const sf::Vector2u& windowSize, sf::Vector2f scale);

};

class Game;
#endif