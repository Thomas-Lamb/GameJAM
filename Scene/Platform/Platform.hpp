/*
** EPITECH PROJECT, 2021
** Astrée
** File description:
** Platform
*/

#ifndef PLATFORM_HPP_
#define PLATFORM_HPP_

#include "../IScene.hpp"
#include "../../Core/Core.hpp"
#include "../../Entity/Entity.hpp"

class Platform : public IScene
{
    public:
        Platform(Save*);
        ~Platform();

        void use(Core *core);
        int getId();
    private:
        sf::View _camera;
        sf::Texture texture_background;
        sf::Sprite sprite_background;
        int timer;
};

#endif /* !PLATFORM_HPP_ */
