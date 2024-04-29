#include <EntitiesManager.hpp>


#include <entt.hpp>
#include <Entity.hpp>
#include <Component.hpp>

EntitiesManager::EntitiesManager(sf::RenderWindow* w, const float& gameTime) : window(w), gameTime(gameTime)
{
}

EntitiesManager::~EntitiesManager()
{
}
void EntitiesManager::Update()
{
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