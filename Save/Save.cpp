/*
** EPITECH PROJECT, 2021
** Havane
** File description:
** Save
*/

#include "Save.hpp"
#include "../Entity/Entity.hpp"

Save::Save()
{
}

std::vector<Entity*> Save::getEntities()
{
    return _entites;
}

void Save::addEntity(Entity *entity)
{
    _entites.push_back(entity);
}

Save::~Save()
{
}
