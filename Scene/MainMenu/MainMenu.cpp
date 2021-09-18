#include "MainMenu.hpp"

MainMenu::MainMenu(Save *save) : IScene(save)
{
}

void MainMenu::use(Core *core)
{

    while (core->getLib()->getWindow().pollEvent(core->getLib()->getEvent()))
    {
        if (core->getLib()->getEvent().type == sf::Event::Closed) core->switchScene(-1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) core->switchScene(-1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) core->switchScene(1);
    }

    core->getLib()->getWindow().clear({ 161, 125, 72 });

    core->getLib()->getWindow().display();
}

int MainMenu::getId()
{
	return 0;
}

MainMenu::~MainMenu()
{}