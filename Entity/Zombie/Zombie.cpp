/*
** EPITECH PROJECT, 2021
** Astrée
** File description:
** Zombie
*/

#include "Zombie.hpp"
#include "../../Lib/Lib.hpp"
#include "../../Save/Save.hpp"
#include <cmath>

Zombie::Zombie(sf::Vector2f position)
{
    _texture.loadFromFile("asset/zombie1.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(position);
}

void Zombie::use(Save *save, Lib* lib)
{
    follow_target(save->getEntities()[0]->getPosition());
    touch_target(save->getEntities()[0], save);
}

void Zombie::follow_target(sf::Vector2f target)
{
    sf::Vector2f moveVec = {target.x - _sprite.getPosition().x, target.y - _sprite.getPosition().y};
    float lengthVec = sqrt(pow(moveVec.x, 2) + pow(moveVec.y, 2));
    moveVec /= lengthVec;

    if (_sprite.getPosition().x != target.x) _sprite.move(moveVec.x * 3, moveVec.y * 3);
}

void Zombie::touch_target(Entity *target, Save *save)
{
    if (target->getSprite().getGlobalBounds().intersects(getSprite().getGlobalBounds()))
    save->gameOver = true;
}

void Zombie::draw(Lib *lib)
{
    lib->getWindow().draw(_sprite);
}

int Zombie::getId()
{
}

sf::Vector2f Zombie::getPosition()
{
    return _sprite.getPosition();
}

sf::Vector2f Zombie::getSize()
{
    return (sf::Vector2f)_texture.getSize();
}

void Zombie::setPosition(sf::Vector2f pos)
{
    _sprite.setPosition(pos);
}

sf::Sprite Zombie::getSprite()
{
    return _sprite;
}

Zombie::~Zombie()
{
}
