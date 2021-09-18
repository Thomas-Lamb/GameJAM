/*
** EPITECH PROJECT, 2021
** Astrée
** File description:
** Entity
*/

#include "Entity.hpp"
#include "Player/Player.hpp"
#include "../Save/Save.hpp"

Entity::Entity(){}

void Entity::use(Save *save, Lib *lib){}

void Entity::draw(Lib *lib){}

int Entity::getId(){}

sf::Vector2f Entity::getPosition(){}

sf::Vector2f Entity::getSize(){}

void Entity::setPosition(sf::Vector2f pos){}

Entity::~Entity(){}