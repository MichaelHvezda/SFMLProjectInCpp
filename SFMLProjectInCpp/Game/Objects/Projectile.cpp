#include <Projectile.hpp>

Projectile::Projectile(std::shared_ptr<TextureWithType>& t, sf::Vector2f pos)
{
	texture = t;
	sprite = std::make_unique<sf::Sprite>();
	//LoadTexture(texture);
	CreateSprite(sprite, texture);
	//sprite->scale(sf::Vector2f(3.f, 3.f));
	//sprite->setTextureRect(sf::IntRect(0, 0, Consts::TEXTURE_SIZE, Consts::TEXTURE_SIZE));
	//sprite->setTextureRect(sf::IntRect(64, 0, 32, 32));

	sprite->setPosition(pos);
	vectorSize = sprite->getTexture()->getSize();
	textureCount = vectorSize.x / Consts::TEXTURE_SIZE;
	direction.y = -Consts::MOVE_SIZE;
}
Projectile::~Projectile()
{
}

void Projectile::Draw(int syncImageCount, sf::RenderWindow* w) {

	int framePos = ((syncImageCount + 1) % (textureCount * Consts::ANIMATE_EVERY_XFRAME)) / Consts::ANIMATE_EVERY_XFRAME;

	sprite->setTextureRect(sf::IntRect(framePos * Consts::TEXTURE_SIZE, 0, Consts::TEXTURE_SIZE, Consts::TEXTURE_SIZE));
	sprite->move(direction);
	w->draw(*sprite);

}
