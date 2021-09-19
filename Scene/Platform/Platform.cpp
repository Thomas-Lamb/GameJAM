/*
** EPITECH PROJECT, 2021
** Astrée
** File description:
** Platform
*/

#include "Platform.hpp"
#include "../../Entity/Player/Player.hpp"
#include "../../Entity/Zombie/Zombie.hpp"
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

Platform::Platform(Save *save) : IScene(save)
{
    sf::View temp(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1920.0f, 1080.0f));
    temp.zoom(0.9);
    _camera = temp;

    texture_background.loadFromFile("asset/back.png");
    sprite_background.setTexture(texture_background);
    save->getEntities()[0]->setPosition({sf::Vector2f(texture_background.getSize().x / 2, texture_background.getSize().y / 2)});
    timer = 0;
}

void Platform::use(Core *core)
{
    sf::Vector2f vectSpawn;
    int rand = 0;
    if (timer > 15)
    {
        rand = (std::rand() % 4) + 1;
        vectSpawn = core->getSave()->getEntities()[0]->getPosition();
        if (rand == 1) {vectSpawn.x += 1000; vectSpawn.y += (std::rand() % 2000) - 1000;}
        if (rand == 2) {vectSpawn.x -= 1000; vectSpawn.y += (std::rand() % 2000) - 1000;}
        if (rand == 3) {vectSpawn.y += 1000; vectSpawn.x += (std::rand() % 2000) - 1000;}
        if (rand == 4) {vectSpawn.y -= 1000; vectSpawn.x += (std::rand() % 2000) - 1000;}
        core->getSave()->addEntity(new Zombie(vectSpawn));
        timer = 0;
    }
    else timer++;

    for (int i = 0; i < core->getSave()->getEntities().size(); i++) core->getSave()->getEntities()[i]->use(core->getSave(), core->getLib());

    while(core->getLib()->getWindow().pollEvent(core->getLib()->getEvent()))
    {
        if (core->getLib()->getEvent().type == sf::Event::Closed) core->switchScene(-1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) core->switchScene(-1);
        if (core->getSave()->gameOver) core->switchScene(2);
    }

    for (int i = 1; i < core->getSave()->getEntities().size(); i++)
    {
        if (core->getSave()->getEntities()[i]->getSprite().getGlobalBounds().intersects(core->getSave()->getEntities()[0]->getSprite().getGlobalBounds()))
         {core->getLib()->playDeath(); core->switchScene(2); }
    }

    _camera.setCenter(core->getSave()->getEntities()[0]->getPosition().x + core->getSave()->getEntities()[0]->getSize().x / 2,
                    core->getSave()->getEntities()[0]->getPosition().y + core->getSave()->getEntities()[0]->getSize().y / 2);
    core->getLib()->getWindow().setView(_camera);

    core->getLib()->getWindow().clear(sf::Color::Black);

    core->getLib()->getWindow().draw(sprite_background);

    for (int i = 0; i < core->getSave()->getEntities().size(); i++) core->getSave()->getEntities()[i]->draw(core->getLib());

    core->getLib()->getWindow().display();
}

int Platform::getId()
{
    return 1;
}

Platform::~Platform()
{
}
