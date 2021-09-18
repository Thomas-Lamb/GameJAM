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
    energy = 150;
    used = false;
}

void Speed::use(Player *player)
{
    cpPlayerPos = player->getPosition();
    if (energy <= 0) { player->resetSpeed(); used = false; return; }
    if (used) { energy--; player->setSpeed(10.f); }
    if (!used) player->resetSpeed();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        used = true;
    }
}

void Speed::draw(Lib *lib)
{
    lib->printText(std::to_string(energy), {cpPlayerPos.x - 75, cpPlayerPos.y}, 75, sf::Color::White);
}

Speed::~Speed()
{
}
