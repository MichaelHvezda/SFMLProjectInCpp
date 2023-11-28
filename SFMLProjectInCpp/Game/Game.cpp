#include <Game.hpp>
#include <Component.hpp>
#include <Entity.hpp>

Game::Game(sf::RenderWindow* w) : window(w), manager(w)
{
	window = w;
	int i = 0;
	auto ent = manager.CreateEntity();
	HealthComponent a(0);
	auto healt = ent.AddComponents<HealthComponent>(10.f);
	auto sss = ent.HaveComponents<HealthComponent>();
	auto ffa = ent.GetComponents<HealthComponent>();
	//auto healt = ent.AddComponents<HealthComponent>(0.f);
	//try
	//{
	//	for (const auto& tex : Consts::TexturesToLoad)
	//	{
	//		textures.push_back(std::make_shared<TextureWithProperties>(tex.props));
	//		LoadTexture(textures[i], tex.path);
	//		//player = std::make_unique<Player>(textures[0]);

	//		i++;
	//	}
	//}
	//catch (std::exception& ex)
	//{
	//	LoggerEx(ex);
	//	//throw ex;
	//}

	//for (auto& text : textures) {
	//	if (text->props.type == Consts::GraphicObjectType::Player)
	//	{
	//		player = std::make_unique<Player>(text);
	//		break;
	//	}
	//}
	//scale.x = 1.0f;
	//scale.y = 1.0f;
	////Textures.push_back(std::make_unique<sf::Texture>());
	////Sprites.push_back(std::make_unique<sf::Sprite>());

	////CreateSprite(Sprites[0], Textures[0]);
	//player->SetDefaultPosition(window);

	//for (auto& text : textures)
	//{
	//	if (text->props.type == Consts::GraphicObjectType::Enemy)
	//	{
	//		enemies.push_back(std::make_shared<Enemy>(text, sf::Vector2f(window->getSize().x / 2.f, window->getSize().y / 2.f), gameTime, sf::Vector2f(0.f, -Consts::MOVE_SIZE), scale));
	//		break;
	//	}
	//}

	//menu = std::make_unique<Menu>(window->getSize());
}

Game::~Game()
{

}

void Game::Update()
{
	//ProcessEvents(window, this);

	////always reset time
	//auto renderTime = clock.restart().asSeconds();

	//if (!menu->isOpen) {
	//	gameTime += renderTime;
	//	if (player->actionColdDown > 0)
	//	{
	//		player->actionColdDown -= renderTime;
	//	}
	//	for (const auto& enemy : enemies)
	//	{
	//		if (enemy->actionColdDown > 0)
	//		{
	//			enemy->actionColdDown -= renderTime;
	//		}
	//	}
	//}


	//if (isGameStart) {
	//	UpdateGame();
	//}

	//if (menu->isOpen) {
	//	UpdateMenu();
	//}
}

void Game::MakeActions()
{
	/*for (const auto& act : player->actions)
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
					projectiles.push_back(std::make_shared<Projectile>(text, player->sprite->getPosition(), gameTime, sf::Vector2f(0.f * scale.x, -Consts::MOVE_SIZE * scale.y), scale, 2.f, 2.f));
					player->actionColdDown = Consts::COLDDOWN_TIME_SECOUND;
					break;
				}
			}
			break;
		default:
			break;
		}
	}
	player->actions.clear();*/
}


void Game::UpdateGame()
{
	//int animationPos = (gameTime - static_cast<int>(gameTime)) / Consts::ANIMATE_EVERY_X_SECOUND;
	//int moveFrameCnt = static_cast<int>((gameTime - static_cast<int>(gameTime)) / Consts::MOVE_EVERY_X_SECOUND);

	//for (const auto& proj : projectiles)
	//{

	//	if (moveFrameCount != moveFrameCnt)
	//	{
	//		proj->Move();
	//	}

	//	proj->Draw(gameTime, window);

	//	if (IsInsideWindow(proj->sprite->getPosition()) && proj->healt > 0)
	//	{
	//		proj->healt = 0;
	//		proj->bornTime = gameTime;
	//	}
	//}
	//for (const auto& enemy : enemies)
	//{

	//	if (moveFrameCount != moveFrameCnt)
	//	{
	//		enemy->Move(window->getSize(), player->sprite->getPosition());
	//	}

	//	enemy->Draw(gameTime, window);

	//	if (enemy->actionColdDown <= 0)
	//	{
	//		for (auto& text : textures)
	//		{
	//			if (text->props.type == Consts::GraphicObjectType::Projectile)
	//			{
	//				auto playerPos = player->sprite->getPosition();
	//				auto pos = enemy->sprite->getPosition() - playerPos;
	//				auto norm = (abs(pos.x) + abs(pos.y)) * -1.f;
	//				pos.x = pos.x / norm;
	//				pos.y = pos.y / norm;
	//				//Logger(pos.x, " ", pos.y);
	//				projectiles.push_back(std::make_shared<Projectile>(text, enemy->sprite->getPosition(), gameTime, sf::Vector2f(pos.x * Consts::MOVE_SIZE * scale.x, pos.y * Consts::MOVE_SIZE * scale.y), scale));
	//				enemy->actionColdDown = Consts::COLDDOWN_TIME_SECOUND;
	//				break;
	//			}
	//		}
	//	}

	//	if (IsInsideWindow(enemy->sprite->getPosition()) && enemy->healt > 0)
	//	{
	//		enemy->healt = 0;
	//		enemy->bornTime = gameTime;
	//	}
	//}

	//if (moveFrameCount != moveFrameCnt)
	//{
	//	player->Move(window->getSize(), scale);
	//}
	//player->Draw(gameTime, window);

	//std::erase_if(projectiles, [](const std::shared_ptr<Projectile>& p) {return p->isAlive == false; });

	//std::erase_if(enemies, [](const std::shared_ptr<Enemy>& p) {return p->isAlive == false; });

	//moveFrameCount = moveFrameCnt;
	//MakeActions();
	//Collisions();
}
void Game::UpdateMenu()
{
	/*auto viewSize = window->getView().getSize();
	auto col = sf::Color(0, 0, 0, 200);

	sf::VertexArray lineStrip(sf::TriangleStrip, 4);
	lineStrip[0].position = sf::Vector2f(viewSize.x, 0.f);
	lineStrip[0].color = col;

	lineStrip[1].position = sf::Vector2f(viewSize.x, viewSize.y);
	lineStrip[1].color = col;

	lineStrip[2].position = sf::Vector2f(0.f, 0.f);
	lineStrip[2].color = col;

	lineStrip[3].position = sf::Vector2f(0.f, viewSize.y);
	lineStrip[3].color = col;
	window->draw(lineStrip);
	menu->Draw(window);*/
}


void Game::Collisions()
{
	/*for (auto& projectile : projectiles)
	{
		if (projectile->healt <= 0)
		{
			continue;
		}
		if (projectile->sprite->getGlobalBounds().intersects(player->sprite->getGlobalBounds()) && projectile->texture->props.type != Consts::GraphicObjectType::PlayerProjectile)
		{
			player->healt -= projectile->damage;
			projectile->healt -= player->damage;

			if (projectile->healt <= 0)
			{
				projectile->bornTime = gameTime;
			}

			if (player->healt <= 0)
			{
				player->bornTime = gameTime;
			}
			Logger("colision projectiles");
		}
		for (auto& projectileAnother : projectiles)
		{
			if (projectileAnother->healt <= 0)
			{
				continue;
			}

			if (projectile->sprite->getGlobalBounds().intersects(projectileAnother->sprite->getGlobalBounds()) && projectile->texture->props.type != projectileAnother->texture->props.type)
			{
				projectileAnother->healt -= projectile->damage;
				projectile->healt -= projectileAnother->damage;

				if (projectile->healt <= 0)
				{
					projectile->bornTime = gameTime;
				}

				if (projectileAnother->healt <= 0)
				{
					projectileAnother->bornTime = gameTime;
				}
				Logger("colision projectiles");
			}
		}
		for (auto& enemy : enemies)
		{
			if (projectile->sprite->getGlobalBounds().intersects(enemy->sprite->getGlobalBounds()) && projectile->texture->props.type != Consts::GraphicObjectType::Projectile)
			{
				enemy->healt -= projectile->damage;
				projectile->healt -= enemy->damage;

				if (projectile->healt <= 0)
				{
					projectile->bornTime = gameTime;
				}

				if (enemy->healt <= 0)
				{
					enemy->bornTime = gameTime;
				}
				Logger("colision enemy");
			}
		}
	}*/
}

bool Game::IsInsideWindow(sf::Vector2f pos)
{
	/*auto wSize = window->getSize();

	if (wSize.x < pos.x || wSize.y < pos.y)
		return true;

	if (pos.x < 0 || pos.y < 0)
		return true;
*/
	return false;
}