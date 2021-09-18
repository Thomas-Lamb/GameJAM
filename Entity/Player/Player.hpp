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
#include "../../Capacity/Speed/Speed.hpp"

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
        sf::Sprite getSprite();
        void setPosition(sf::Vector2f);

        void capacity();
        void setSpeed(float sp);
        void resetSpeed();

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        float speed;
        int gold;
        bool left, right, up, down;
        Balise capacity_balise;
        Shoot capacity_shoot;
        Speed capacity_speed;

};

#endif /* !PLAYER_HPP_ */
