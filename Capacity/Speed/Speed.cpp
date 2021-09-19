/*
** EPITECH PROJECT, 2021
** Havane
** File description:
** Speed
*/

#include "Speed.hpp"
#include "../../Lib/Lib.hpp"
#include "../../Entity/Player/Player.hpp"

Speed::Speed()
{
    texture_show_speed.loadFromFile("asset/speed.png");
    sprite_show_speed.setTexture(texture_show_speed);
    energy = 150;
    used = false;
    speedBoost = 10.f;
}

void Speed::use(Player *player, Lib *lib)
{
    sprite_show_speed.setPosition({player->getPosition().x + 50, player->getPosition().y + 350});
    cpPlayerPos = player->getPosition();
    if (energy <= 0) { player->resetSpeed(); used = false; return; }
    if (used) { energy--; player->setSpeed(speedBoost); }
    if (!used) player->resetSpeed();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        lib->playSpeed();
        used = true;
    }
}

void Speed::draw(Lib *lib)
{
    if (energy > 0)
    {
        lib->printText(std::to_string(energy), {cpPlayerPos.x + 55, cpPlayerPos.y + 420}, 40, sf::Color::White);
        lib->getWindow().draw(sprite_show_speed);
    }
}

Speed::~Speed()
{
}
