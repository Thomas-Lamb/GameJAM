/*
** EPITECH PROJECT, 2021
** Astrée
** File description:
** Platform
*/

#include "Platform.hpp"
#include "../../Entity/Player/Player.hpp"
#include "../../Entity/Zombie/Zombie.hpp"

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
    if (timer > 15)
    {
        core->getSave()->addEntity(new Zombie());
        timer = 0;
    }
    else timer++;

    for (int i = 0; i < core->getSave()->getEntities().size(); i++) core->getSave()->getEntities()[i]->use(core->getSave(), core->getLib());

    while(core->getLib()->getWindow().pollEvent(core->getLib()->getEvent()))
    {
        if (core->getLib()->getEvent().type == sf::Event::Closed) core->switchScene(-1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) core->switchScene(-1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) core->switchScene(0);
    }

    _camera.setCenter(core->getSave()->getEntities()[0]->getPosition().x + core->getSave()->getEntities()[0]->getSize().x / 2, core->getSave()->getEntities()[0]->getPosition().y + core->getSave()->getEntities()[0]->getSize().y / 2);
    core->getLib()->getWindow().setView(_camera);

    core->getLib()->getWindow().clear(sf::Color::Black);

    core->getLib()->getWindow().draw(sprite_background);

    for (int i = 0; i < core->getSave()->getEntities().size(); i++) core->getSave()->getEntities()[i]->draw(core->getLib());

    core->getLib()->printText(std::to_string(core->getSave()->getEntities().size()), {core->getSave()->getEntities()[0]->getPosition().x, core->getSave()->getEntities()[0]->getPosition().y + 80}, 75, sf::Color::White);

    core->getLib()->getWindow().display();
}

int Platform::getId()
{
    return 1;
}

Platform::~Platform()
{
}
