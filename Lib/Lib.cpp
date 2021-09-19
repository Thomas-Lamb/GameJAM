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
	_font.loadFromFile("asset/arial.ttf");
	_text.setFont(_font);
    _start = new sf::Music();
    _start->openFromFile("asset/start.ogg");
    _start->setVolume(20);
	_fireball = new sf::Music();
    _fireball->openFromFile("asset/fireball.ogg");
    _fireball->setVolume(20);
	_speed = new sf::Music();
    _speed->openFromFile("asset/speed.ogg");
    _speed->setVolume(20);
	_death = new sf::Music();
    _death->openFromFile("asset/death.ogg");
    _death->setVolume(20);
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

void Lib::playFireBall()
{
	_fireball->stop();
	_fireball->play();
}

void Lib::playStart()
{
	_start->stop();
	_start->play();
}

void Lib::playSpeed()
{
	_speed->stop();
	_speed->play();
}

void Lib::playDeath()
{
	_death->stop();
	_death->play();
}

Lib::~Lib()
{}