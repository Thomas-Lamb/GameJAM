/*
** EPITECH PROJECT, 2021
** Astrée
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "../Entity.hpp"
#include "../../Capacity/Balise/Balise.hpp"
#include "../../Capacity/Shoot/Shoot.hpp"

class Player : public Entity
{
    public:
        Player();
        ~Player();

        void use(Save*, Lib*);
        void draw(Lib*);
        int getId();
        sf::Vector2f getPosition();
        sf::Vector2f getSize();
        void setPosition(sf::Vector2f);

        void capacity();


    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        float speed;
        bool left, right, up, down;
        Balise capacity_balise;
        Shoot capacity_shoot;

};

#endif /* !PLAYER_HPP_ */
