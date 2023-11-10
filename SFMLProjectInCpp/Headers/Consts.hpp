#ifndef CONSTS_H
#define CONSTS_H
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <math.h>
namespace Consts {
	//static const std::string TEXTURE_ROCKET = "Textures/RocketSpite.png";

	static const int TEXTURE_ANIMATIONS = 4;
	static const float MOVE_SIZE = 2.0f;

	static const float ANIMATE_EVERY_X_SECOUND = 1 / 8.f;
	static const float MOVE_EVERY_X_SECOUND = 1 / 60.f;
	static const float COLDDOWN_TIME_SECOUND = 1.f;
	static const float PI = (atan(1) * 4);;

	enum class Direction
	{
		None = 0, Left, Right, Up, Down
	};

	enum class Action
	{
		None = 0, Shoot, Imortality
	};

	enum class GraphicObjectType
	{
		Projectile, Enemy, Player, PlayerProjectile
	};

	template<typename T>
	struct KeyMap
	{
	public:
		const std::vector<sf::Keyboard::Key> keys;
		T action;
	public:
		KeyMap(std::vector<sf::Keyboard::Key> k, T a) : keys(k), action(a) {}
		//KeyMap(sf::Keyboard::Key k, T a): keys(k),action(a) {}
	};

	struct TextureProperies
	{
	public:
		GraphicObjectType type;
		int sizeX;
		int sizeY;
		int animationsCount;
		bool haveDeadAnimation;
		int level;
	public:
		TextureProperies(GraphicObjectType t, const int sX, const int sY, const int animatedC)
			: type(t), sizeX(sX), sizeY(sY), animationsCount(animatedC), haveDeadAnimation(false), level(1) {}
		TextureProperies(GraphicObjectType t, const int sX, const int sY, const int animatedC, const bool deadA, int l)
			: type(t), sizeX(sX), sizeY(sY), animationsCount(animatedC), haveDeadAnimation(deadA), level(l) {}
	};

	struct TextureFilepath
	{
	public:
		const std::string path;
		TextureProperies props;
	public:
		TextureFilepath(std::string p, TextureProperies properies) : path(p), props(properies) {}
		//KeyMap(sf::Keyboard::Key k, T a): keys(k),action(a) {}
	};


	static const std::vector<KeyMap<Direction>> KeyDirectionMap = {
		{ { sf::Keyboard::Up,sf::Keyboard::W }, Direction::Up },
		{ { sf::Keyboard::Down,sf::Keyboard::S }, Direction::Down },
		{ { sf::Keyboard::Left,sf::Keyboard::A }, Direction::Left },
		{ { sf::Keyboard::Right,sf::Keyboard::D }, Direction::Right },
	};

	static const std::vector<KeyMap<Action>> KeyActionMap = {
	{ { sf::Keyboard::Space }, Action::Shoot },
	};

	static const std::vector<TextureFilepath> TexturesToLoad = {
		{  "Textures/RocketSpite.png", { GraphicObjectType::Player, 32, 32, TEXTURE_ANIMATIONS}},
		{  "Textures/Projectil1.png", { GraphicObjectType::PlayerProjectile, 8, 32, TEXTURE_ANIMATIONS,true,1 }},
		{  "Textures/Projectil1.png", { GraphicObjectType::Projectile, 8, 32, TEXTURE_ANIMATIONS,true,1 }},
	};

}
#endif // EVENTS_H
