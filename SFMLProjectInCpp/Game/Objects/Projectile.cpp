#include <Projectile.hpp>

Projectile::Projectile(std::shared_ptr<TextureWithProperties>& t, sf::Vector2f pos)
{
	texture = t;
	sprite = std::make_unique<sf::Sprite>();
	//LoadTexture(texture);
	CreateSprite(sprite, texture);
	//sprite->scale(sf::Vector2f(3.f, 3.f));
	//sprite->setTextureRect(sf::IntRect(0, 0, Consts::TEXTURE_SIZE, Consts::TEXTURE_SIZE));
	//sprite->setTextureRect(sf::IntRect(64, 0, 32, 32));
	sprite->setOrigin(sf::Vector2f(texture->props.sizeX / 2.f, 0.f));
	sprite->scale(sf::Vector2f(0.5f, 0.5f));
	sprite->setPosition(pos);

	textureCount = texture->props.animationsCount;
	direction.y = -Consts::MOVE_SIZE;
}
Projectile::~Projectile()
{
}

void Projectile::Move() {
	sprite->move(direction);
}

void Projectile::Draw(int syncImageCount, sf::RenderWindow* w) {

	int animation = syncImageCount % textureCount;

	sprite->setTextureRect(sf::IntRect(animation * texture->props.sizeX, 0, texture->props.sizeX, texture->props.sizeY));
	w->draw(*sprite);

}
