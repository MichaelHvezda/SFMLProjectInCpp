#ifndef TEXTURES_H
#define TEXTURES_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Logger.hpp>
#include <Consts.hpp>

struct TextureWithType
{
public:
	sf::Texture texture;
	Consts::GraphicObjectType type;
public:
	TextureWithType(Consts::GraphicObjectType t) : type(t) {};
};

void LoadTexture(const std::shared_ptr<TextureWithType>& texture, const std::string& file);

#endif // EVENTS_H
