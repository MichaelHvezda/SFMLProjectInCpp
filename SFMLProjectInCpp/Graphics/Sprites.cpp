#include <Sprites.hpp>


void CreateSprite(const std::unique_ptr<sf::Sprite>& sprite, const std::shared_ptr<TextureWithType>& texture) {

	sprite->setTexture(texture->texture);
}