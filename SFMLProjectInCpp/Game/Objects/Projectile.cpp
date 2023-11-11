#include <Projectile.hpp>

Projectile::Projectile(std::shared_ptr<TextureWithProperties>& t, sf::Vector2f pos, float gameTime, sf::Vector2f dir, sf::Vector2f scale)
{
	bornTime = gameTime;
	texture = t;
	sprite = std::make_unique<sf::Sprite>();
	//LoadTexture(texture);
	CreateSprite(sprite, texture);
	//sprite->scale(sf::Vector2f(3.f, 3.f));
	//sprite->setTextureRect(sf::IntRect(0, 0, Consts::TEXTURE_SIZE, Consts::TEXTURE_SIZE));
	//sprite->setTextureRect(sf::IntRect(64, 0, 32, 32));

	auto pros = texture->props;
	sprite->setOrigin(sf::Vector2f(pros.sizeX / 2.f, pros.sizeY / 2.f));
	//sprite->scale();
	sprite->setPosition(pos);
	sprite->scale(sf::Vector2f(0.5f * scale.x, 0.5f * scale.y));

	float rotation = (float)(atan2(dir.x, dir.y) / (2 * Consts::PI)) * 360.f - 180.f;
	sprite->setRotation(rotation);

	textureCount = texture->props.animationsCount;
	direction = dir;
}
Projectile::~Projectile()
{
}

void Projectile::Move()
{
	if (healt > 0)
		sprite->move(direction);
}

void Projectile::Draw(float gameTime, sf::RenderWindow* w)
{

	int animationPos = static_cast<int>((gameTime - bornTime) / Consts::ANIMATE_EVERY_X_SECOUND);
	int animation = animationPos % textureCount;


	if (healt > 0)
	{
		sprite->setTextureRect(sf::IntRect(animation * texture->props.sizeX, 0, texture->props.sizeX, texture->props.sizeY));
	}
	else
	{
		if (!texture->props.haveDeadAnimation)
		{
			isAlive = false;
			return;
		}
		sprite->setTextureRect(sf::IntRect(animation * texture->props.sizeX, texture->props.sizeY, texture->props.sizeX, texture->props.sizeY));
		if (animationPos == textureCount)
		{
			isAlive = false;
			return;
		}
	}

	if (isAlive) {
		w->draw(*sprite);
	}
}
