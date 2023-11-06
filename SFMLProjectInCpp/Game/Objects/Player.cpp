#include <Player.hpp>

Player::Player(std::shared_ptr<TextureWithType>& t)
{
	texture = t;
	sprite = std::make_unique<sf::Sprite>();
	//LoadTexture(texture);
	CreateSprite(sprite, texture);
	//sprite->scale(sf::Vector2f(3.f, 3.f));
	//sprite->setTextureRect(sf::IntRect(0, 0, Consts::TEXTURE_SIZE, Consts::TEXTURE_SIZE));
	//sprite->setTextureRect(sf::IntRect(64, 0, 32, 32));

	vectorSize = sprite->getTexture()->getSize();
	textureCount = vectorSize.x / Consts::TEXTURE_SIZE;
}

Player::~Player()
{
}

void Player::Draw(int frameAnimation, sf::RenderWindow* w)
{
	int animation = frameAnimation % textureCount;
	sprite->setTextureRect(sf::IntRect(animation * Consts::TEXTURE_SIZE, 0, Consts::TEXTURE_SIZE, Consts::TEXTURE_SIZE));

	w->draw(*sprite);
}

void Player::SetDefaultPosition(sf::RenderWindow* w) {
	auto size = w->getSize();

	sprite->setPosition(sf::Vector2f(size.x / 2, size.y - Consts::TEXTURE_SIZE));
}


void Player::Move()
{

	//if (drawCount % 32 == 0) {
	//	return;
	//}
	sf::Vector2f vec(0.f, 0.f);

	for (const auto& dir : directions)
	{
		switch (dir)
		{
		case Consts::Direction::Left:
			vec.x += -Consts::MOVE_SIZE;
			//sprite->move(sf::Vector2f(-0.05f, 0.f));
			break;
		case Consts::Direction::Right:
			vec.x += Consts::MOVE_SIZE;
			//sprite->move(sf::Vector2f(0.05f, 0.f));
			break;
		case Consts::Direction::Up:
			vec.y += -Consts::MOVE_SIZE;
			//sprite->move(sf::Vector2f(0.f, -0.05f));
			break;
		case Consts::Direction::Down:
			vec.y += Consts::MOVE_SIZE;
			//sprite->move(sf::Vector2f(0.f, 0.05f));
			break;
		case Consts::Direction::None:
			break;
		default:
			break;
		}
	}
	if (directions.size() > 1) {
		vec /= 2.f;
	}

	sprite->move(vec);
}
