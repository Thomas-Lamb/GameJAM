/*
** EPITECH PROJECT, 2021
** Astrée
** File description:
** Lib
*/

#ifndef LIB_HPP_
#define LIB_HPP_

#include "SFML/Graphics.hpp"

class Lib {
    public:
        Lib();
        ~Lib();

        sf::RenderWindow& getWindow();
        sf::Event& getEvent();
        void close();
        void printText(std::string str, sf::Vector2f vec, int charSize, sf::Color color);

    private:
        sf::Event _event;
        sf::RenderWindow _app;
        sf::Text _text;
        sf::Font _font;
};

#endif /* !LIB_HPP_ */
