#include <EntitiesManager.hpp>


#include <entt.hpp>
#include <Entity.hpp>

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