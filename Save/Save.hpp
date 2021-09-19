/*
** EPITECH PROJECT, 2021
** Havane
** File description:
** Save
*/

#ifndef SAVE_HPP_
#define SAVE_HPP_

#include <vector>

class Entity;

class Save {
    public:
        Save();
        ~Save();

        std::vector<Entity*> getEntities();
        void addEntity(Entity*);
        void removeEntity(int);
        bool gameOver;

    protected:
    private:
        std::vector<Entity*> _entites;

};

#endif /* !SAVE_HPP_ */
