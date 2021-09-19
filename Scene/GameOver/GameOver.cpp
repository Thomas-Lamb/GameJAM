/*
** EPITECH PROJECT, 2021
** Havane
** File description:
** GameOver
*/

#include "GameOver.hpp"

GameOver::GameOver(Save *save) : IScene(save)
{
}

void GameOver::use(Core *core)
{
    while (core->getLib()->getWindow().pollEvent(core->getLib()->getEvent()))
    {
        if (core->getLib()->getEvent().type == sf::Event::Closed) core->switchScene(-1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) core->switchScene(-1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) core->switchScene(-1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) core->switchScene(-1);
    }

    core->getLib()->getWindow().setView(core->getLib()->getWindow().getDefaultView());

    core->getLib()->getWindow().clear(sf::Color::Black);

    core->getLib()->printText("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tTu es deja assez amoche comme ca,\n\t\t\t\t\t\t\t\t\t\tnous ne pouvons pas te renvoyer la bas\n\t\t\t\t\t\t\t\t\t\tMeme ce programme ne veut plus te voir", {0,0}, 50, sf::Color::White);

    core->getLib()->getWindow().display();
}

int GameOver::getId()
{
    return 2;
}

GameOver::~GameOver()
{
}
