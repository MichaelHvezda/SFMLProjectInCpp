#include <Projectile.hpp>

Projectile::Projectile(std::shared_ptr<TextureWithProperties>& t, sf::Vector2f pos,float gameTime)
{
	bornTime = gameTime;
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
	if(healt > 0)
		sprite->move(direction);
}

void Projectile::Draw(float gameTime, sf::RenderWindow* w) {

	int animationPos = static_cast<int>((gameTime - bornTime) / Consts::ANIMATE_EVERY_X_SECOUND);
	int animation = animationPos % textureCount;

	if(healt > 0)
		sprite->setTextureRect(sf::IntRect(animation * texture->props.sizeX, 0, texture->props.sizeX, texture->props.sizeY));
	else {

		sprite->setTextureRect(sf::IntRect(animation * texture->props.sizeX, texture->props.sizeY, texture->props.sizeX, texture->props.sizeY));
		if (animationPos == textureCount)
			isAlive = false;
	}
	if(isAlive)
		w->draw(*sprite);
}
