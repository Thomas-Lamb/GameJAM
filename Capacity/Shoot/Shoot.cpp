/*
** EPITECH PROJECT, 2021
** Havane
** File description:
** Shoot
*/

#include "Shoot.hpp"
#include "../../Lib/Lib.hpp"
#include "../../Save/Save.hpp"
#include "../../Entity/Entity.hpp"
#include <cmath>

Shoot::Shoot()
{
    bullet_type.shape.setFillColor(sf::Color::Red);
    bullet_type.shape.setRadius(8.f);
    cooldown = 10;
    speed = 10;
}

void Shoot::use(Save *save, Lib *lib)
{
    if (timer < cooldown) timer++;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && timer >= cooldown)
    {
        bullet_type.shape.setPosition({save->getEntities()[0]->getPosition().x + save->getEntities()[0]->getSize().x / 2,
                                save->getEntities()[0]->getPosition().y + save->getEntities()[0]->getSize().y / 2});
        sf::Vector2f mousePosition = lib->getWindow().mapPixelToCoords(sf::Mouse::getPosition(lib->getWindow()));
        float angleShot = atan2(mousePosition.y - bullet_type.shape.getPosition().y,
                                mousePosition.x - bullet_type.shape.getPosition().x);
        bullet_type.angleShoot2 = angleShot;
        projectiles.push_back(bullet_type);
        timer = 0;
    }
    for (int i = 0; i < projectiles.size(); i++)
    {
        projectiles[i].shape.move(cos(projectiles[i].angleShoot2) * speed, 0);
        projectiles[i].shape.move(0, sin(projectiles[i].angleShoot2) * speed);
    }
}

void Shoot::draw(Lib *lib)
{
    for (int i = 0; i < projectiles.size(); i++) lib->getWindow().draw(projectiles[i].shape);
}

Shoot::~Shoot()
{
}
