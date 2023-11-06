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
	player->Move();
	player->Draw(syncImageCount, window);

	syncImageCount++;
	syncImageCount = (syncImageCount + 1) % (128 * Consts::ANIMATE_EVERY_XFRAME);

	for (const auto& proj : projectiles) {
		proj->Draw(syncImageCount, window);
	}

	MakeActions();
}

void Game::MakeActions() {
	for (const auto& act : player->actions)
	{
		if (player->actionColdDown > 0) {
			player->actions.clear();
			return;
		}
		switch (act)
		{
		case Consts::Action::Shoot:
			for (auto& text : textures) {
				if (text->type == Consts::GraphicObjectType::Projectile) {
					projectiles.push_back(std::make_unique<Projectile>(text,player->sprite->getPosition()));
					player->actionColdDown = 1.f;
				}
			}
			break;
		default:
			break;
		}
	}
	player->actions.clear();
}