/*
** EPITECH PROJECT, 2021
** Astrée
** File description:
** Button
*/

#include "Button.hpp"
#include "../Core/Core.hpp"

Button::Button(sf::Color color, sf::Vector2f pos, sf::Vector2f size, std::string name, std::string texture, sf::Color textColor)
{
    if (texture != "")
        _text = texture;
    _name = name;
    _pos = pos;
    _size = size;
    _color = color;
    _textColor = textColor;
    _rect.setPosition(pos);
    _rect.setSize(size);
    _rect.setFillColor(color);
}

void Button::setText(std::string text)
{
    _text = text;
}

bool Button::isClick(sf::Vector2i mousePos)
{
    sf::Vector2f news;
    news.x = (float)mousePos.x;
    news.y = (float)mousePos.y;

    if (news.x >= _pos.x && news.x <= (_pos.x + _size.x) &&
    news.y >= _pos.y && news.y <= (_pos.y + _size.y))
        return true;
    else 
        return false;
}

void Button::print(Lib *lib)
{
    lib->getWindow().draw(_rect);
    lib->printText(_text, {_pos.x + 45, _pos.y}, 75, _textColor);
}

float const Button::getX()
{
    return _pos.x;
}

float const Button::getY()
{
    return _pos.y;
}

float const Button::getWidth()
{
    return _size.y;
}

float const Button::getHeight()
{
    return _size.x;
}

std::string const Button::getName()
{
    return _name;
}

Button::~Button()
{
}
