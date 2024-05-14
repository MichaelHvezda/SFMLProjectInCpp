#include <EntitiesManager.hpp>


#include <entt.hpp>
#include <Entity.hpp>
#include <Component.hpp>

EntitiesManager::EntitiesManager(sf::RenderWindow* w, const float& gameTime, const uint64_t& action) : window(w), gameTime(gameTime), action(action)
{
}

EntitiesManager::~EntitiesManager()
{
}
void EntitiesManager::Update(float renderTime)
{
	{
		auto group = registry.view<const HealthComponent>();
		for (auto& entity : group)
		{
			auto& hp = group.get<const HealthComponent>(entity);
			if (!hp.isAlive) {
				registry.destroy(entity);
			}
		}
	}

	auto group = registry.view<PositionComponent, const TypeComponent>(entt::exclude<MomentumComponent>);

	for (auto& entity : group)
	{
		auto [pos, typ] = group.get<PositionComponent, const TypeComponent>(entity);
		if (typ.type == Consts::GraphicObjectType::Player) {
			if (action & static_cast<uint64_t>(Consts::Direction::Left)) {
				pos.position.x += -Consts::MOVE_SIZE * pos.scale.x;
			}
			if (action & static_cast<uint64_t>(Consts::Direction::Right)) {
				pos.position.x += Consts::MOVE_SIZE * pos.scale.x;
			}
			if (action & static_cast<uint64_t>(Consts::Direction::Up)) {
				pos.position.y += -Consts::MOVE_SIZE * pos.scale.y;
			}
			if (action & static_cast<uint64_t>(Consts::Direction::Down)) {
				pos.position.y += Consts::MOVE_SIZE * pos.scale.y;
			}
			auto playerEntity = Entity(entity, this);

			if (playerEntity.HaveComponents<ShootComponent>()) {
				auto [shoot, pos] = playerEntity.GetComponents<ShootComponent, PositionComponent>();

				if (shoot.actionColdDown > 0) {
					shoot.actionColdDown -= renderTime;
				}
				Logger("Cooldoutn ", shoot.actionColdDown);
				if (shoot.actionColdDown <= 0 && (action & static_cast<uint64_t>(Consts::Action::Shoot))) {

					shoot.actionColdDown = Consts::COLDDOWN_TIME_SECOUND;
					auto shootProjectil = CreateEntity();
					shootProjectil.AddComponents<HealthComponent>(1.f);
					sf::Sprite sprite;
					sprite.setTexture(shoot.shootTextureWithProps->texture);
					auto& spriteComp = shootProjectil.AddComponents<SpriteComponent>(sprite);

					auto& const textProps = shoot.shootTextureWithProps->props;
					auto& typeComp = shootProjectil.AddComponents<TypeComponent>(textProps.type);

					shootProjectil.AddComponents<AnimationComponent>(sf::Vector2i(textProps.sizeX, textProps.sizeY), textProps.haveDeadAnimation, textProps.animationsCount, gameTime);

					shootProjectil.AddComponents<PositionComponent>(sf::Vector2f(pos.position.x, pos.position.y), pos.scale, sf::Vector2u(textProps.sizeX, textProps.sizeY));
					shootProjectil.AddComponents<MomentumComponent>(sf::Vector2f(0.f, -Consts::MOVE_SIZE));
				}
			}
		}

		if (typ.type == Consts::GraphicObjectType::Enemy) {
			//ai here
		}
	}

	auto groupWithMom = registry.view<PositionComponent, const TypeComponent, AnimationComponent, MomentumComponent, HealthComponent>();

	for (auto& entity : groupWithMom)
	{
		auto [pos, typ, ani, mom, health] = groupWithMom.get<PositionComponent, const TypeComponent, AnimationComponent, MomentumComponent, HealthComponent>(entity);
		if (health.health > 0) {
			pos.position.x = pos.position.x + (mom.momentum.x * pos.scale.x);
			pos.position.y = pos.position.y + (mom.momentum.y * pos.scale.y);

			if (IsInsideWindow(pos.position))
			{
				health = 0;
				ani.bornTime = gameTime;
			}
		}
	}
}
void EntitiesManager::Draw()
{
	auto group = registry.view<const PositionComponent, SpriteComponent, const AnimationComponent, HealthComponent>();

	for (auto& entity : group)
	{
		auto [pos, spr, ani, health] = group.get<const PositionComponent, SpriteComponent, const AnimationComponent, HealthComponent>(entity);
		int animationPos = static_cast<int>((gameTime - ani.bornTime) / Consts::ANIMATE_EVERY_X_SECOUND);
		int animation = animationPos % ani.animationsCount;


		spr.sprite.setPosition(pos.position);
		spr.sprite.setScale(pos.scale);

		if (health.health > 0)
		{
			spr.sprite.setTextureRect(sf::IntRect(animation * ani.textureSize.x, 0, ani.textureSize.x, ani.textureSize.y));
		}
		else
		{
			if (!ani.haveDeadAnimation)
			{
				health.isAlive = false;
				continue;
			}
			spr.sprite.setTextureRect(sf::IntRect(animation * ani.textureSize.x, ani.textureSize.y, ani.textureSize.x, ani.textureSize.y));
			if (animationPos == ani.animationsCount)
			{
				health.isAlive = false;
				continue;
			}
		}


		if (health.isAlive) {
			window->draw(spr.sprite);
		}
	}
}

void EntitiesManager::ResizeAll(const sf::Event::SizeEvent& newSize, sf::Vector2u oldSize)
{
	auto group = registry.view<PositionComponent>();

	sf::Vector2f scale(newSize.width / static_cast<float>(oldSize.x), newSize.height / static_cast<float>(oldSize.y));

	for (auto& entity : group)
	{
		auto& pos = group.get<PositionComponent>(entity);

		auto rateX = pos.position.x / static_cast<float>(oldSize.x);
		auto rateY = pos.position.y / static_cast<float>(oldSize.y);

		pos.position.x = rateX * newSize.width;
		pos.position.y = rateY * newSize.height;
		pos.scale.x *= scale.x;
		pos.scale.y *= scale.y;

	}
}

Entity EntitiesManager::CreateEntity()
{
	auto ent = Entity{ registry.create(), this };
	//auto& ss = registry.emplace<SpriteComponent>(ent.entity);
	//auto ss = ent.HaveComponents();
	//auto& spriteComp = ent.AddComponents<SpriteComponent>();
	//spriteComp.sprite = sprite;
	//ent.AddComponents<TypeComponent>(type.type);
	return ent;
}

bool EntitiesManager::IsInsideWindow(sf::Vector2f pos)
{
	auto wSize = window->getSize();

	if (wSize.x < pos.x || wSize.y < pos.y)
		return true;

	if (pos.x < 0 || pos.y < 0)
		return true;

	return false;
}