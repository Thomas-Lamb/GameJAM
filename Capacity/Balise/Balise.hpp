/*
** EPITECH PROJECT, 2021
** Havane
** File description:
** Balise
*/

#ifndef BALISE_HPP_
#define BALISE_HPP_

#include "SFML/Graphics.hpp"

class Lib;
class Player;

class Balise {
    public:
        Balise();
        ~Balise();

        void use(Player*);
        void draw(Lib*);

    private:
        bool isPlaced;
        int numberUseLeft;
        sf::RectangleShape texture_balise;
        int cooldown, maxCooldown;
};

#endif /* !BALISE_HPP_ */
