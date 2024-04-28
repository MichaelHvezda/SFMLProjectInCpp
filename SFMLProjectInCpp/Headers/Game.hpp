#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <Sprites.hpp>
#include <Textures.hpp>
#include <Projectile.hpp>
#include <Player.hpp>
#include <Events.hpp>
#include <Menu.hpp>
#include <Enemy.hpp>
#include <Consts.hpp>

#include <EntitiesManager.hpp>

class Game
{
public:
	//std::vector<std::unique_ptr<SpriteWithType>> sprites;
	std::unordered_map<Consts::GraphicObjectType, std::shared_ptr<TextureWithProperties>> textures;
	//std::vector<std::shared_ptr<Projectile>> projectiles;
	//std::vector<std::shared_ptr<Enemy>> enemies;
	//std::unique_ptr<Player> player;
	sf::RenderWindow* window;
	std::unique_ptr<Menu> menu;
	sf::Clock clock;
	sf::Vector2f scale;
	float gameTime;
	int moveFrameCount;
	bool isGameStart;
public:
	Game(sf::RenderWindow* w);
	virtual ~Game();
public:
	void Update();
	void MakeActions();
	void Collisions();
private:
	bool IsInsideWindow(sf::Vector2f pos);
	void UpdateGame();
	void UpdateMenu();

private:
	EntitiesManager manager;
};

#endif // EVENTS_H
