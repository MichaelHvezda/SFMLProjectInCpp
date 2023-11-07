#ifndef SPRITES_H
#define SPRITES_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <Logger.hpp>
#include <Textures.hpp>

struct SpriteWithType
{
	sf::Sprite sprite;
	Consts::GraphicObjectType type;
};

void CreateSprite(const std::unique_ptr<sf::Sprite>& sprite, const std::shared_ptr<TextureWithProperties>& texture);


#endif // EVENTS_H
