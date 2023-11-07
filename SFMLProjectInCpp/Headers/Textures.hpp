#ifndef TEXTURES_H
#define TEXTURES_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Logger.hpp>
#include <Consts.hpp>

struct TextureWithProperties
{
public:
	sf::Texture texture;
	Consts::TextureProperies props;
public:
	TextureWithProperties(Consts::TextureProperies p) : props(p) {};
};

void LoadTexture(const std::shared_ptr<TextureWithProperties>& texture, const std::string& file);

#endif // EVENTS_H
