#include <EntitiesManager.hpp>


#include <entt.hpp>
#include <Entity.hpp>
#include <Component.hpp>

EntitiesManager::EntitiesManager(sf::RenderWindow* w) : window(w)
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
	auto group = registry.group<PositionComponent, SpriteComponent>();

	for (auto& entity : group)
	{
		auto [pos, spr] = group.get<PositionComponent, SpriteComponent>(entity);

		spr.sprite.setPosition(pos.position);
		spr.sprite.setScale(pos.scale);
		window->draw(spr.sprite);
	}
}

void EntitiesManager::ResizeAll(sf::Event::SizeEvent& newSize, sf::Vector2u oldSize)
{
	auto group = registry.group<PositionComponent, SpriteComponent>();

	sf::Vector2f scale(newSize.width / static_cast<float>(oldSize.x), newSize.height / static_cast<float>(oldSize.y));

	for (auto& entity : group)
	{
		auto [pos, spr] = group.get<PositionComponent, SpriteComponent>(entity);

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