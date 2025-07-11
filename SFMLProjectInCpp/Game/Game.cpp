#include <Game.hpp>
#include <Component.hpp>
#include <Entity.hpp>

Game::Game(sf::RenderWindow* w) : window(w), manager(w, gameTime, actions)
{
	auto ent = manager.CreateEntity();

	auto& healt = ent.AddComponents<HealthComponent>(10.f);
	//auto healt = ent.AddComponents<HealthComponent>(0.f);
	try
	{
		for (const auto& tex : Consts::TexturesToLoad)
		{
			textures[tex.props.type] = std::make_shared<TextureWithProperties>(tex.props);
			LoadTexture(textures[tex.props.type], tex.path);
			//player = std::make_unique<Player>(textures[0]);
		}
	}
	catch (std::exception& ex)
	{
		LoggerEx(ex);
		//throw ex;
	}

	sf::Sprite sprite;
	//LoadTexture(texture);
	auto& texturaWithProps = textures[Consts::GraphicObjectType::Player];
	auto& texturaWithPropsShoot = textures[Consts::GraphicObjectType::PlayerProjectile];

	sprite.setTexture(texturaWithProps->texture);

	auto& const textProps = texturaWithProps->props;

	auto& shootComp = ent.AddComponents<ShootComponent>(texturaWithPropsShoot, 1.f, 1.f);
	auto& spriteComp = ent.AddComponents<SpriteComponent>(sprite);
	auto& typeComp = ent.AddComponents<TypeComponent>(texturaWithProps->props.type);
	auto& animionComp = ent.AddComponents<AnimationComponent>(sf::Vector2i(textProps.sizeX, textProps.sizeY), textProps.haveDeadAnimation, textProps.animationsCount, gameTime);
	ent.AddComponents<PositionComponent>(sf::Vector2f(255.f, 255.f), spriteComp.sprite.getScale(), sf::Vector2u(texturaWithProps->props.sizeX, texturaWithProps->props.sizeY));

	menu = std::make_unique<Menu>(window->getSize());
}

Game::~Game()
{

}

void Game::Update()
{
	ProcessEvents(window, this);

	//always reset time
	auto renderTime = clock.restart().asSeconds();
	int animationPos = (gameTime - static_cast<int>(gameTime)) / Consts::ANIMATE_EVERY_X_SECOUND;
	int moveFrameCnt = static_cast<int>((gameTime - static_cast<int>(gameTime)) / Consts::MOVE_EVERY_X_SECOUND);

	if (isGameStart) {
		manager.Update(renderTime);
		manager.Draw();
		gameTime += renderTime;
		moveFrameCount = moveFrameCnt;
	}

	if (menu->isOpen) {
		UpdateMenu();
	}
}

void Game::UpdateMenu()
{
	auto viewSize = window->getView().getSize();
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
	menu->Draw(window);
}

void Game::ResizeAll(sf::Event::SizeEvent& newSize, sf::Vector2u oldSize)
{
	menu->Resize(newSize, oldSize);
	manager.ResizeAll(newSize, oldSize);
}

bool Game::IsInsideWindow(const sf::Vector2f pos) const
{
	auto wSize = window->getSize();

	if (wSize.x < pos.x || wSize.y < pos.y)
		return true;

	if (pos.x < 0 || pos.y < 0)
		return true;

	return false;
}