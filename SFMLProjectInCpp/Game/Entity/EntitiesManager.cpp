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
		window->draw(spr.sprite);
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