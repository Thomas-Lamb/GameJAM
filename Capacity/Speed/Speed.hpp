/*
** EPITECH PROJECT, 2021
** Havane
** File description:
** Speed
*/

#ifndef SPEED_HPP_
#define SPEED_HPP_

#include "SFML/Graphics.hpp"

class Lib;
class Player;

class Speed {
    public:
        Speed();
        ~Speed();

        void use(Player*);
        void draw(Lib*);
    private:
        int energy;
        bool used;
        sf::Vector2f cpPlayerPos;
};

#endif /* !SPEED_HPP_ */
