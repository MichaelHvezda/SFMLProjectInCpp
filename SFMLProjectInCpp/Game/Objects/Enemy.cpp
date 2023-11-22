#include <Enemy.hpp>

Enemy::Enemy(std::shared_ptr<TextureWithProperties>& t, sf::Vector2f pos, float gameTime, sf::Vector2f dir, sf::Vector2f scale)
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

Enemy::~Enemy()
{
}

void Enemy::Draw(float gameTime, sf::RenderWindow* w)
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


void Enemy::Move(const sf::Vector2u& windowSize, const sf::Vector2f& playerPosition)
{
	auto dif = this->sprite->getPosition() - playerPosition;
	auto length = CalculLength(dif);

	auto lengthMax = CalculLength(windowSize);

	if (length < lengthMax / 3.f)
	{
		if (dif.x > dif.y)
		{
			sprite->move(sf::Vector2f(Consts::MOVE_ENEMY_SIZE, 0.f));
		}
		if (dif.x <= dif.y)
		{
			sprite->move(sf::Vector2f(-Consts::MOVE_ENEMY_SIZE, 0.f));
		}
		return;
	}

	sprite->move(sf::Vector2f(0.f, Consts::MOVE_ENEMY_SIZE));

	// do ai move here
}

float CalculLength(const sf::Vector2f& dif)
{
	return sqrt(dif.x * dif.x + dif.y * dif.y);
}

float CalculLength(const sf::Vector2u& dif)
{
	return sqrt(dif.x * dif.x + dif.y * dif.y);
}