#include <Sprites.hpp>


void CreateSprite(const std::unique_ptr<sf::Sprite>& sprite, const std::shared_ptr<TextureWithProperties>& texture)
{

	sprite->setTexture(texture->texture);
}