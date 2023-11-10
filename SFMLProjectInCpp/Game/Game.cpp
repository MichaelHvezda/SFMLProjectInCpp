#include <Game.hpp>

Game::Game(sf::RenderWindow* w) {

	window = w;
	int i = 0;
	try
	{
		for (const auto& tex : Consts::TexturesToLoad)
		{
			textures.push_back(std::make_shared<TextureWithProperties>(tex.props));
			LoadTexture(textures[i], tex.path);
			//player = std::make_unique<Player>(textures[0]);

			i++;
		}
	}
	catch (std::exception& ex)
	{
		LoggerEx(ex);
		//throw ex;
	}

	for (auto& text : textures) {
		if (text->props.type == Consts::GraphicObjectType::Player)
		{
			player = std::make_unique<Player>(text);
			break;
		}
	}
	scale.x = 1.0f;
	scale.y = 1.0f;
	//Textures.push_back(std::make_unique<sf::Texture>());
	//Sprites.push_back(std::make_unique<sf::Sprite>());

	//CreateSprite(Sprites[0], Textures[0]);
	player->SetDefaultPosition(window);

	for (auto& text : textures)
	{
		if (text->props.type == Consts::GraphicObjectType::Projectile)
		{
			projectiles.push_back(std::make_unique<Projectile>(text, sf::Vector2f(window->getSize().x / 2.f, text->props.sizeY + 1), gameTime, sf::Vector2f(0.f, Consts::MOVE_SIZE), scale));
			break;
		}
	}
}

Game::~Game()
{

}

void Game::Update()
{
	ProcessEvents(window, this);

	auto renderTime = clock.restart().asSeconds();
	gameTime += renderTime;
	if (player->actionColdDown > 0)
		player->actionColdDown -= renderTime;

	//int animationPos = (gameTime - static_cast<int>(gameTime)) / Consts::ANIMATE_EVERY_X_SECOUND;
	int moveFrameCnt = (gameTime - static_cast<int>(gameTime)) / Consts::MOVE_EVERY_X_SECOUND;

	for (const auto& proj : projectiles)
	{

		if (moveFrameCount != moveFrameCnt)
			proj->Move();
		proj->Draw(gameTime, window);

		if (IsInsideWindow(proj->sprite->getPosition()) && proj->healt != 0)
		{
			proj->healt = 0;
			proj->bornTime = gameTime;
		}
	}

	if (moveFrameCount != moveFrameCnt)
		player->Move(window->getSize(), scale);
	player->Draw(gameTime, window);

	std::erase_if(projectiles, [](const std::shared_ptr<Projectile>& p) {return p->isAlive == false; });

	moveFrameCount = moveFrameCnt;
	MakeActions();
	Collisions();
}

void Game::MakeActions()
{
	for (const auto& act : player->actions)
	{
		if (player->actionColdDown > 0.f)
		{
			return;
		}
		switch (act)
		{
		case Consts::Action::Shoot:
			for (auto& text : textures)
			{
				if (text->props.type == Consts::GraphicObjectType::PlayerProjectile)
				{
					projectiles.push_back(std::make_shared<Projectile>(text, player->sprite->getPosition(), gameTime, sf::Vector2f(0.f * scale.x, -Consts::MOVE_SIZE * scale.y), scale));
					player->actionColdDown = Consts::COLDDOWN_TIME_SECOUND;
					break;
				}
			}
			break;
		default:
			break;
		}
	}
	player->actions.clear();
}

void Game::Collisions()
{
	for (auto& projectile : projectiles)
	{
		if (projectile->sprite->getGlobalBounds().intersects(player->sprite->getGlobalBounds()) && projectile->texture->props.type != Consts::GraphicObjectType::PlayerProjectile)
		{
			Logger("colision");
		}
	}
}

bool Game::IsInsideWindow(sf::Vector2f pos)
{

	auto wSize = window->getSize();

	if (wSize.x < pos.x || wSize.y < pos.y)
		return true;

	if (pos.x < 0 || pos.y < 0)
		return true;

	return false;
}