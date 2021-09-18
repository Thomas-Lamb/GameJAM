/*
** EPITECH PROJECT, 2021
** Astrée
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>

class Lib;

class Button {
    public:
        Button(sf::Color color, sf::Vector2f pos, sf::Vector2f size, std::string name, std::string texture = "", sf::Color textColor = sf::Color::White);
        ~Button();

        bool isClick(sf::Vector2i);
        void print(Lib*);
        const float getWidth();
        const float getHeight();
        const float getX();
        const float getY();
        void setText(std::string);
        const std::string getName();

    private:
        std::string _name;
        sf::RectangleShape _rect;
        sf::Vector2f _pos;
        sf::Vector2f _size;
        sf::Color _color;
        sf::Color _textColor;
        std::string _text;
};

#endif /* !BUTTON_HPP_ */
