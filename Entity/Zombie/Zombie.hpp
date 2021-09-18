/*
** EPITECH PROJECT, 2021
** Astrée
** File description:
** Zombie
*/

#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include "../Entity.hpp"

class Zombie : public Entity
{
    public:
        Zombie(sf::Vector2f position);
        ~Zombie();

        void use(Save*, Lib*);
        void draw(Lib*);
        int getId();
        sf::Vector2f getPosition();
        sf::Vector2f getSize();
        sf::Sprite getSprite();
        void setPosition(sf::Vector2f);
        void follow_target(sf::Vector2f);
        void touch_target(Entity*);

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        Player *_target;
};

#endif /* !ZOMBIE_HPP_ */
