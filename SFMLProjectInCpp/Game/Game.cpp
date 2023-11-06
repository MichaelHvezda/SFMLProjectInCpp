#include <Game.hpp>

Game::Game(sf::RenderWindow* w) {

	window = w;
	int i = 0;

	for (const auto& tex : Consts::TexturesToLoad) {
		textures.push_back(std::make_shared<TextureWithType>(tex.type));
		LoadTexture(textures[i], tex.path);

		player = std::make_unique<Player>(textures[0]);

		i++;
	}

	for (auto& text : textures) {
		if (text->type == Consts::GraphicObjectType::Player) {
			player = std::make_unique<Player>(text);
			break;
		}
	}

	//Textures.push_back(std::make_unique<sf::Texture>());
	//Sprites.push_back(std::make_unique<sf::Sprite>());

	//CreateSprite(Sprites[0], Textures[0]);
	player->SetDefaultPosition(window);
}

Game::~Game() {

}

void Game::Draw() {
	/*for (const auto& sprite : Sprites) {
		window->draw(*sprite);
	}*/
	auto renderTime = clock.restart().asSeconds();
	gameTime += renderTime;
	if (player->actionColdDown > 0)
		player->actionColdDown -= renderTime;

	int animationPos = (gameTime - static_cast<int>(gameTime)) / Consts::ANIMATE_EVERY_X_SECOUND;
	int moveFrameCnt = (gameTime - static_cast<int>(gameTime)) / Consts::MOVE_EVERY_X_SECOUND;

	if (moveFrameCount != moveFrameCnt)
		player->Move();
	player->Draw(animationPos, window);

	for (const auto& proj : projectiles) {
		if (moveFrameCount != moveFrameCnt)
			proj->Move();
		proj->Draw(animationPos, window);
		if (IsInsideWindow(proj->sprite->getPosition())) {
			proj->healt = 0;
		}
	}
	std::erase_if(projectiles, [](const std::unique_ptr<Projectile>& p) {return p->healt <= 0; });

	moveFrameCount = moveFrameCnt;
	MakeActions();
}

void Game::MakeActions() {
	for (const auto& act : player->actions)
	{
		if (player->actionColdDown > 0.f) {
			return;
		}
		switch (act)
		{
		case Consts::Action::Shoot:
			for (auto& text : textures) {
				if (text->type == Consts::GraphicObjectType::Projectile) {
					projectiles.push_back(std::make_unique<Projectile>(text, player->sprite->getPosition()));
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

bool Game::IsInsideWindow(sf::Vector2f pos) {

	auto wSize = window->getSize();

	if (wSize.x < pos.x || wSize.y < pos.y)
		return true;

	if (pos.x < 0 || pos.y < 0)
		return true;

	return false;
}