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
void EntitiesManager::Update()
{
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
		}

		if (typ.type == Consts::GraphicObjectType::Enemy) {
			//ai here
		}
	}

	auto groupWithMom = registry.view<PositionComponent, const TypeComponent, MomentumComponent>();

	for (auto& entity : groupWithMom)
	{
		auto [pos, typ, mom] = groupWithMom.get<PositionComponent, const TypeComponent, MomentumComponent>(entity);

		pos.position.x = pos.position.x + (mom.momentum.x * pos.scale.x);
		pos.position.y = pos.position.y + (mom.momentum.y * pos.scale.y);
	}
}
void EntitiesManager::Draw()
{
	auto group = registry.view<const PositionComponent, SpriteComponent, const AnimationComponent>();

	for (auto& entity : group)
	{
		auto [pos, spr, ani] = group.get<const PositionComponent, SpriteComponent, const AnimationComponent>(entity);
		int animationPos = static_cast<int>((gameTime - ani.bornTime) / Consts::ANIMATE_EVERY_X_SECOUND);
		int animation = animationPos % ani.animationsCount;
		spr.sprite.setPosition(pos.position);
		spr.sprite.setScale(pos.scale);

		spr.sprite.setTextureRect(sf::IntRect(animation * ani.textureSize.x, 0, ani.textureSize.x, ani.textureSize.y));
		window->draw(spr.sprite);
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