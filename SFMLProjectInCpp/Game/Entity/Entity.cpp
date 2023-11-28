#include <Entity.hpp>
#include <EntitiesManager.hpp>
#include <Component.hpp>



Entity::Entity(entt::entity entity, EntitiesManager* manager) : entity(entity), manager(manager)
{
}

Entity::~Entity()
{
}
