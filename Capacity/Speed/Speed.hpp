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

        void use(Player*, Lib*);
        void draw(Lib*);
    private:
        int energy;
        bool used;
        float speedBoost;
        sf::Vector2f cpPlayerPos;
        sf::Texture texture_show_speed;
        sf::Sprite sprite_show_speed;
};

#endif /* !SPEED_HPP_ */
