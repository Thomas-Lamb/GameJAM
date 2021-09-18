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
    _texture.loadFromFile("asset/player.png");
    _sprite.setTexture(_texture);
    speed = 5.f;
    gold = 0;
}

void Player::capacity()
{
    capacity_balise.use(this);
    capacity_speed.use(this);
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

    if (_sprite.getPosition().x < 0) _sprite.setPosition({0, _sprite.getPosition().y});
    if (_sprite.getPosition().x >= 8192 - _texture.getSize().x) _sprite.setPosition({8192 - _texture.getSize().x,  _sprite.getPosition().y});
    if (_sprite.getPosition().y < 0) _sprite.setPosition(_sprite.getPosition().x, 0);
    if (_sprite.getPosition().y >= 8192 - _texture.getSize().y) _sprite.setPosition(_sprite.getPosition().x, 8190 - _texture.getSize().y);

}

void Player::draw(Lib *lib)
{
    capacity_balise.draw(lib);
    capacity_shoot.draw(lib);
    capacity_speed.draw(lib);
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

void Player::setSpeed(float sp)
{
    speed = sp;
}

void Player::resetSpeed()
{
    speed = 5.f;
}

sf::Sprite Player::getSprite()
{
    return _sprite;
}

float Player::getSpeed()
{
    return speed;
}

Player::~Player()
{
}
