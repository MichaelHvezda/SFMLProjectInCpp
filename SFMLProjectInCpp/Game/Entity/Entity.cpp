#include <Entity.hpp>
#include <utility>
#include <EntitiesManager.hpp>



namespace Entity {
	Entity::Entity(entt::entity entity, EntitiesManager* manager) : entity(entity), manager(manager)
	{
	}

	Entity::~Entity()
	{
	}

	template<typename... T>
	bool Entity::HaveComponents()
	{
		return manager->registry.all_of<T>(entity);
	}

	template<typename T, typename ...Args>
	decltype(auto) Entity::AddComponents(Args&& ...components)
	{
		return manager->registry.emplace<T>(entity, std::forward<Args>(components)...);
	}

	template<typename... T>
	decltype(auto) Entity::GetComponents()
	{
		return manager->registry.get<T>(entity);
	}
}