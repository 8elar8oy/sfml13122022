#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
void initBat(sf::RectangleShape& bat, const sf::Color batColor, const sf::Vector2f batPosition) 
{
	bat.setSize(batsize);
	bat.setFillColor(batColor);
	bat.setPosition(batPosition);
}
void initBall(sf::CircleShape& ball, const sf::Vector2f ballPosition)
{
	ball.setRadius(ballradius);
	ball.setFillColor(Color::White);
	ball.setPosition(ballPosition);
}
void initScore(sf::Text& score, const sf::Vector2f textPosition) {
	score.setCharacterSize(64);
	score.setPosition(textPosition);
	score.setFillColor(Color::White);
}