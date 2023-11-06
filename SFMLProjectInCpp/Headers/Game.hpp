#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <Sprites.hpp>
#include <Textures.hpp>
#include <Projectile.hpp>
#include <Player.hpp>

class Game {
public:
	//std::vector<std::unique_ptr<SpriteWithType>> sprites;
	std::vector<std::shared_ptr<TextureWithType>> textures;
	std::vector<std::unique_ptr<Projectile>> projectiles;
	std::vector<std::unique_ptr<sf::Sprite>> enemies;
	std::unique_ptr<Player> player;
	sf::RenderWindow* window;
	sf::Clock clock;
	float gameTime;
	int moveFrameCount;
public:
	Game(sf::RenderWindow* w);
	virtual ~Game();
public:
	void Draw();
	void MakeActions();

private:
	bool IsInsideWindow(sf::Vector2f pos);
};

#endif // EVENTS_H
