#ifndef CONSTS_H
#define CONSTS_H
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
namespace Consts {
	//static const std::string TEXTURE_ROCKET = "Textures/RocketSpite.png";


	static const int TEXTURE_SIZE = 32;
	static const float MOVE_SIZE = 0.5f;

	static const float ANIMATE_EVERY_X_SECOUND = 1/8.f;
	static const float MOVE_EVERY_X_SECOUND = 1/60.f;
	static const float COLDDOWN_TIME_SECOUND = 2.f;

	enum class Direction {
		None = 0, Left, Right, Up, Down
	};

	enum class Action {
		None = 0, Shoot, Imortality
	};

	enum class GraphicObjectType {
		Projectile,Enemy,Player
	};

	template<typename T>
	struct KeyMap {
	public:
		const std::vector<sf::Keyboard::Key> keys;
		T action;
	public:
		KeyMap(std::vector<sf::Keyboard::Key> k, T a) : keys(k), action(a) {}
		//KeyMap(sf::Keyboard::Key k, T a): keys(k),action(a) {}
	};

	struct TextureFilepath {
	public:
		const std::string path;
		GraphicObjectType type;
	public:
		TextureFilepath(std::string p, GraphicObjectType t) : path(p), type(t) {}
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
		{  "Textures/RocketSpite.png", GraphicObjectType::Player },
		{  "Textures/Projectil1.png", GraphicObjectType::Projectile },
	};

}
#endif // EVENTS_H
