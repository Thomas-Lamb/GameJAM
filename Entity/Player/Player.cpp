/*
** EPITECH PROJECT, 2021
** Astrée
** File description:
** Player
*/

#include "Player.hpp"
#include "../../Lib/Lib.hpp"

Player::Player()
{
    _texture.loadFromFile("Asset/player.png");
    _sprite.setTexture(_texture);
    speed = 5.f;
}

void Player::capacity()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) capacity_balise.use(this);
}

void Player::use(Save *save, Lib* lib)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) up = true; else up = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) down = true; else down = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) left = true; else left = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) right = true; else right = false;

    capacity_shoot.use(save, lib);
    capacity();

    if (up) _sprite.move(0.f, -speed);
    if (down) _sprite.move(0.f, speed);
    if (left) _sprite.move(-speed, 0.f);
    if (right) _sprite.move(speed, 0.f);

}

void Player::draw(Lib *lib)
{
    capacity_balise.draw(lib);
    capacity_shoot.draw(lib);
    lib->getWindow().draw(_sprite);
}

int Player::getId()
{
}

sf::Vector2f Player::getPosition()
{
    return _sprite.getPosition();
}

sf::Vector2f Player::getSize()
{
    return (sf::Vector2f)_texture.getSize();
}

void Player::setPosition(sf::Vector2f pos)
{
    _sprite.setPosition(pos);
}

Player::~Player()
{
}
