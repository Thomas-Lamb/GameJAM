/*
** EPITECH PROJECT, 2021
** Havane
** File description:
** Shoot
*/

#ifndef SHOOT_HPP_
#define SHOOT_HPP_

#include "SFML/Graphics.hpp"

class Lib;
class Save;

class Shoot {
    public:
        Shoot();
        ~Shoot();

        class Bullet
        {
            public:
                float angleShoot2;
                sf::CircleShape shape;
        };

        void use(Save*, Lib*);
        void draw(Lib*);

    private:
        Bullet bullet_type;
        std::vector<Bullet> projectiles;
        int timer, cooldown;
        float speed;
};

#endif /* !SHOOT_HPP_ */
