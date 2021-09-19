/*
** EPITECH PROJECT, 2021
** Havane
** File description:
** GameOver
*/

#ifndef GAMEOVER_HPP_
#define GAMEOVER_HPP_

#include "../IScene.hpp"
#include "../../Core/Core.hpp"

class GameOver : public IScene
{
    public:
        GameOver(Save*);
        ~GameOver();

        void use(Core*);
        int getId();
};

#endif /* !GAMEOVER_HPP_ */
