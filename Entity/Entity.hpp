/*
** EPITECH PROJECT, 2021
** Astrée
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <SFML/Graphics.hpp>

class Lib;
class Player;
class Save;

class Entity {
    public:
        Entity();
        ~Entity();

        virtual void use(Save*, Lib*);
        virtual void draw(Lib*);
        virtual int getId();
        virtual sf::Vector2f getPosition();
        virtual sf::Vector2f getSize();
        virtual void setPosition(sf::Vector2f);

    protected:
    private:
};

#endif /* !ENTITY_HPP_ */
