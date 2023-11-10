#include <Player.hpp>

Player::Player(std::shared_ptr<TextureWithProperties>& t)
{
	texture = t;
	sprite = std::make_unique<sf::Sprite>();
	//LoadTexture(texture);
	CreateSprite(sprite, texture);
	//sprite->scale(sf::Vector2f(3.f, 3.f));
	//sprite->setTextureRect(sf::IntRect(0, 0, Consts::TEXTURE_SIZE, Consts::TEXTURE_SIZE));
	//sprite->setTextureRect(sf::IntRect(64, 0, 32, 32));

	//vectorSize = sprite->getTexture()->getSize();
	sprite->setOrigin(sf::Vector2f(texture->props.sizeX / 2.f, texture->props.sizeY / 2.f));
	//textureCount = ; /*vectorSize.x / Consts::TEXTURE_SIZE;*/
	textureCount = texture->props.animationsCount;
}

Player::~Player()
{
}

void Player::Draw(float gameTime, sf::RenderWindow* w)
{
	int animationPos = static_cast<int>((gameTime - bornTime) / Consts::ANIMATE_EVERY_X_SECOUND);
	int animation = animationPos % textureCount;
	sprite->setTextureRect(sf::IntRect(animation * texture->props.sizeX, 0, texture->props.sizeX, texture->props.sizeY));

	w->draw(*sprite);


	auto bounds = sprite->getGlobalBounds();
	auto winSize = w->getSize();

	//std::cout << bounds.getPosition().x << " " << bounds.getPosition().y << std::endl;
	if (bounds.getPosition().x < 0) {
		sf::Sprite spriteNew(*sprite);

		spriteNew.move(winSize.x, 0.f);
		w->draw(spriteNew);

		if (bounds.getPosition().x + bounds.getSize().x > 0) {
			sprite->move(winSize.x, 0.f);
			Logger("player relocated left");
		}
	}
	if (bounds.getPosition().x + bounds.getSize().x > winSize.x) {
		sf::Sprite spriteNew(*sprite);

		spriteNew.move(-1.f * winSize.x, 0.f);
		w->draw(spriteNew);

		if (bounds.getPosition().x > winSize.x) {
			sprite->move(-1.f * winSize.x, 0.f);
			Logger("player relocated right");
		}
	}
	//auto bonds = sprite->getGlobalBounds();
	//if(bonds.contains(0,0))
}

void Player::SetDefaultPosition(sf::RenderWindow* w) {
	auto size = w->getSize();

	sprite->setPosition(sf::Vector2f(size.x / 2.f, static_cast<float>(size.y - texture->props.sizeY - 1 )));
}


void Player::Move(const sf::Vector2u& windowSize, sf::Vector2f scale)
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
			vec.x += -Consts::MOVE_SIZE * scale.x;
			//sprite->move(sf::Vector2f(-0.05f, 0.f));
			break;
		case Consts::Direction::Right:
			vec.x += Consts::MOVE_SIZE * scale.x;
			//sprite->move(sf::Vector2f(0.05f, 0.f));
			break;
		case Consts::Direction::Up:
			vec.y += -Consts::MOVE_SIZE * scale.y;
			//sprite->move(sf::Vector2f(0.f, -0.05f));
			break;
		case Consts::Direction::Down:
			vec.y += Consts::MOVE_SIZE * scale.y;
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
	auto bounds = sprite->getGlobalBounds();
	auto newPos = bounds.getPosition() + vec;
	//if (newPos)
	//	Logger("bonds");

	if (newPos.y > 0 && newPos.y + bounds.getSize().y < windowSize.y)
		sprite->move(vec);
}
