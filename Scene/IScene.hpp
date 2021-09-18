/*
** EPITECH PROJECT, 2021
** Astrée
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

class Core;
class Save;

class IScene {
    public:
        IScene(Save*);
        ~IScene();

        virtual void use(Core*);
        virtual int getId();

    protected:
    private:
};

#endif /* !ISCENE_HPP_ */
