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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) { core->getLib()->playStart(); core->switchScene(1); }
    }

    core->getLib()->getWindow().clear({ 161, 125, 72 });

    core->getLib()->printText("                       \n\n\t\t\t\t\t\tBonjour a toi jeune mage, te voila teleporte dans un monde apocalyptique.\n                 Ton but est de survivre le plus longtemps possible. Pour cela, tu dois tuer les zombies\n                                                                 avec tes boules de feu.\n\n                     Pour t aider, tu as deux competences, une balise de rappel qui une fois posez-te \n                 permet de te teleporter la ou tu l as pose quand tu appuieras de nouveau sur la touche.\n                                                     Tu as egalement un boost de vitesse.\n\n\
                    Attention, ces competences sont limites a une utilisation pour la balise et au 150 de speed.\n\n\n\n              Z = Go Up\n              S = Go Down\n              D = Go Right\n              Q = Go Left                                                Appuie sur G pour commencer la partie\n              ESC = Leave\n              F = Place Balise\n              C = Speed Boost", {0,0}, 40, sf::Color::Black);

    core->getLib()->getWindow().display();
}

int MainMenu::getId()
{
	return 0;
}

MainMenu::~MainMenu()
{}