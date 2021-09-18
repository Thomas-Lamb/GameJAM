/*
** EPITECH PROJECT, 2021
** Havane
** File description:
** Balise
*/

#include "Balise.hpp"
#include "../../Lib/Lib.hpp"
#include "../../Entity/Player/Player.hpp"

Balise::Balise()
{
    texture_balise.setFillColor(sf::Color::Yellow);
    texture_balise.setSize(sf::Vector2f(35, 35));
    texture_balise.setPosition(-1000, -1000);
    isPlaced = false;
    numberUseLeft = 1;
    maxCooldown = 5;
    cooldown = 0;
}

void Balise::use(Player *player)
{
    if (numberUseLeft <= 0) return;
    if (isPlaced && cooldown < maxCooldown) cooldown++;
    if (!isPlaced)
    {
        texture_balise.setPosition(player->getPosition());
        isPlaced = true;
        return;
    }
    if (isPlaced && cooldown == maxCooldown)
    {
        player->setPosition(texture_balise.getPosition());
        numberUseLeft = 0;
        texture_balise.setPosition(-1000, -1000);
        isPlaced = false;
    }

}

void Balise::draw(Lib *lib)
{
    lib->getWindow().draw(texture_balise);
}

Balise::~Balise()
{
}
