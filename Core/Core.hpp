/*
** EPITECH PROJECT, 2021
** Astrée
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "../Lib/Lib.hpp"
#include <vector>
#include <iostream>
#include "../Scene/IScene.hpp"
#include "../Save/Save.hpp"

class Core {
    public:
        Core();
        ~Core();

	    void switchScene(int id);
	    void use();
	    Lib* getLib();
		Save* getSave();
    private:
	    Lib* _lib;
	    std::vector<IScene*> _scenes;
		Save *_save;
};

#endif /* !CORE_HPP_ */
