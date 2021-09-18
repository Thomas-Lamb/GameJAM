/*
** EPITECH PROJECT, 2021
** Astrée
** File description:
** Lib
*/

#include "Lib.hpp"

Lib::Lib()
{
	_app.create(sf::VideoMode(1920, 1080), "Vein", sf::Style::Fullscreen);
	_app.setFramerateLimit(60);
	_font.loadFromFile("Asset/arial.ttf");
	_text.setFont(_font);
}

sf::RenderWindow& Lib::getWindow()
{
	return _app;
}

sf::Event& Lib::getEvent()
{
	return _event;
}

void Lib::close()
{
	exit(0);
}

void Lib::printText(std::string str, sf::Vector2f vec, int charSize, sf::Color color)
{
	_text.setFillColor(color);
	_text.setString(str);
	_text.setCharacterSize(charSize);
	_text.setPosition(vec);
	_app.draw(_text);
}

Lib::~Lib()
{}